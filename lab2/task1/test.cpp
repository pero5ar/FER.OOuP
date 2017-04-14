#include "client.hpp"
#include "derived.hpp"
#include "derived2.hpp"
#include "derived3.hpp"

int main() {
    Derived d;
    Client c(d);
    c.operate();

    Derived2 d2;
    Client c2(d2);
    c2.operate();

    Derived3 d3;
    Client c3(d3);
    c3.operate();

    return 0;
}

// g++ *.cpp -o task1