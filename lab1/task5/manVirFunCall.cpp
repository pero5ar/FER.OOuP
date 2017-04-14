#include <iostream>
using namespace std;

class B {
  public:
    virtual int prva() = 0;
    virtual int druga() = 0;
};

class D : public B {
  public:
    virtual int prva() {return 0;}
    virtual int druga() {return 42;}
};

void print_virtual(B* pb) {
  int (***pfun)(); 
  pfun = (int (***)()) pb;
  cout << pfun[0][0]() << endl;
  cout << pfun[0][1]() << endl;
//  cout << (*(&(**pfun)+1))() << endl;
}

int main(void)
{
  B* b = new D();
  print_virtual(b);
  delete b;
  return 0;
}
