#include <stdio.h>
#include <stdlib.h>

#define FALSE 0;
#define TRUE 1;

typedef void* (*PTRFUN)(void);

/*class Unary_Function*/
typedef struct {
  PTRFUN* vtable;
  int lower_bound_;
  int upper_bound_;
} Unary_Function;

typedef double (*PtrFunDUfD)(Unary_Function*, double); // double <- Unary_Function*, double

double _Unary_Function_negative_value_at(Unary_Function* obj, double x) {
  PtrFunDUfD value_at = (PtrFunDUfD) obj->vtable[0];
  return -value_at(obj, x);
}

PTRFUN _Unary_Function_Vtable[2] = {
  (PTRFUN) NULL,
  (PTRFUN) _Unary_Function_negative_value_at,
};

void Unary_Function_Init(Unary_Function* obj, int lb, int ub) {
  obj->lower_bound_ = lb;
  obj->upper_bound_ = ub;
  obj->vtable = _Unary_Function_Vtable;
}

Unary_Function* Unary_Function_Create(int lb, int ub) {
  Unary_Function* obj = (Unary_Function*) malloc( sizeof(Unary_Function) );
  Unary_Function_Init(obj, lb, ub);
  return obj;
}

void Unary_Function_tabulate(Unary_Function* obj) {
  PtrFunDUfD value_at = (PtrFunDUfD) obj->vtable[0];
  for(int x = obj->lower_bound_; x <= obj->upper_bound_; x++) {
    printf("f(%d)=%lf\n", x, value_at(obj, x));
  }
}

int same_functions_for_ints(Unary_Function* f1, Unary_Function* f2, double tolerance) {
  if(f1->lower_bound_ != f2->lower_bound_) return FALSE;
  if(f1->upper_bound_ != f2->upper_bound_) return FALSE;
  for(int x = f1->lower_bound_; x <= f1->upper_bound_; x++) {
    PtrFunDUfD value_at_f1 = (PtrFunDUfD) f1->vtable[0];
    PtrFunDUfD value_at_f2 = (PtrFunDUfD) f2->vtable[0];
    double delta = value_at_f1(f1, x) - value_at_f2(f2, x);
    if(delta < 0) delta = -delta;
    if(delta > tolerance) return FALSE;
  }
  return TRUE;
}
/**/

/*class Square*/
typedef struct {
  PTRFUN* vtable;
  int lower_bound_;
  int upper_bound_;
} Square;

double _Square_value_at(Square* obj, double x) {
  return x*x;
}

PTRFUN _Square_Vtable[2] = {
  (PTRFUN) _Square_value_at,
  (PTRFUN) _Unary_Function_negative_value_at,
};

void Square_Init(Square* obj, int lb, int ub) {
  Unary_Function_Init((Unary_Function*) obj, lb, ub);
  obj->vtable = _Square_Vtable;
}

Square* Square_Create(int lb, int ub) {
  Square* obj = (Square*) malloc( sizeof(Square) );
  Square_Init(obj, lb, ub);
  return obj;
}
/**/

/*class Linear*/
typedef struct {
  PTRFUN* vtable;
  int lower_bound_;
  int upper_bound_;
  double a_;
  double b_;
} Linear;

double _Linear_value_at(Linear* obj, double x) {
  return obj->a_*x + obj->b_;
}

PTRFUN _Linear_Vtable[2] = {
  (PTRFUN) _Linear_value_at,
  (PTRFUN) _Unary_Function_negative_value_at,
};

void Linear_Init(Linear* obj, int lb, int ub, double a_coef, double b_coef) {
  Unary_Function_Init((Unary_Function*) obj, lb, ub);
  obj->vtable = _Linear_Vtable;
  obj->a_ = a_coef;
  obj->b_ = b_coef;
}

Linear* Linear_Create(int lb, int ub, double a_coef, double b_coef) {
  Linear* obj = (Linear*) malloc( sizeof(Linear) );
  Linear_Init(obj, lb, ub, a_coef, b_coef);
  return obj;
}
/**/

int main(void)
{
  Unary_Function* f1 = (Unary_Function*) Square_Create(-2, 2);
  Unary_Function_tabulate(f1);
  Unary_Function* f2 = (Unary_Function*) Linear_Create(-2, 2, 5, -2);
  Unary_Function_tabulate(f2);
  printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
  PtrFunDUfD negative_value_at_f2 = (PtrFunDUfD) f2->vtable[1];
  printf("neg_val f2(1) = %lf\n", negative_value_at_f2(f2, 1.0));
  free(f1);
  free(f2);
  return 0;
}