#include <stdio.h>
#include <stdlib.h>

typedef char const* (*PTRFUN)(void);

/*class Animal*/
typedef struct {
  PTRFUN* vtable;
  char const* name;
} Animal;

void animalPrintGreeting(Animal* obj) {
  printf("%s pozdravlja: %s \n", obj->name, obj->vtable[0]());
  return;
}

void animalPrintMenu(Animal* obj) {
  printf("%s voli %s \n", obj->name, obj->vtable[1]());
  return;
}

PTRFUN animal_vtable[2] = {
  (PTRFUN) NULL,
  (PTRFUN) NULL,
};

Animal* createAnimal(char const* name) {
  Animal* obj = (Animal*) malloc( sizeof(Animal) );
  obj->vtable = animal_vtable;
  obj->name = name;
  return obj;
}
/**/

/*class Dog*/
typedef struct {
  PTRFUN* vtable;
  char const* name;
} Dog;

char const* dogGreet(void) {
  return "vau!";
}
char const* dogMenu(void) {
  return "kuhanu govedinu";
}

PTRFUN dog_vtable[2] = {
  (PTRFUN) dogGreet,
  (PTRFUN) dogMenu,
};

Animal* createDog(char const* name) {
  Animal* obj = createAnimal(name);
  obj->vtable = dog_vtable;
  return obj;
}
/**/

/*class Cat*/
typedef struct {
  PTRFUN* vtable;
  char const* name;
} Cat;

char const* catGreet(void) {
  return "mijau!";
}
char const* catMenu(void) {
  return "konzerviranu tunjevinu";
}

PTRFUN cat_vtable[2] = {
  (PTRFUN) catGreet,
  (PTRFUN) catMenu,
};

Animal* createCat(char const* name) {
  Animal* obj = createAnimal(name);
  obj->vtable = cat_vtable;
  return obj;
}
/**/

/*extra functions for dogs*/
Dog** createDogs(int n) {
  Dog** dogs = (Dog**) malloc ( n * sizeof(Dog*) );
  static char str[10][10];  // hard coded !
  for (int i = 0; i < n; i++) {
    sprintf(str[i], "dog %d", i);
    Dog* d = (Dog*) createDog(str[i]);
    dogs[i] = d;
  }
  return dogs;
}

void printDogs(Dog** dogs, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d %s \n", i+1, dogs[i]->name);
  }
}

void destroyDogs(Dog** dogs, int n) {
  for (int i = 0; i < n; i++) {
    free(dogs[i]);
  }
  free(dogs);
}
/**/

void testAnimals(void) {
  Animal* p1=createDog("Hamlet");
  Animal* p2=createCat("Ofelija");
  Animal* p3=createDog("Polonije");

  animalPrintGreeting(p1);
  animalPrintGreeting(p2);
  animalPrintGreeting(p3);

  animalPrintMenu(p1);
  animalPrintMenu(p2);
  animalPrintMenu(p3);

  free(p1); free(p2); free(p3);
}

int main(void)
{
  testAnimals();

  printf("\n\n");
  Dog** dogs = createDogs(10);
  printDogs(dogs, 10);
  destroyDogs(dogs, 10);

  return 0;
}