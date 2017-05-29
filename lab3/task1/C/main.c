#include "myfactory.h"

#include <stdio.h>
#include <stdlib.h>

typedef char const *(*PTRFUN)();

struct Animal
{
    PTRFUN *vtable;
    // vtable entries:
    // 0: char const* name(void* this);
    // 1: char const* greet();
    // 2: char const* menu();
};

// parrots and tigers defined in respective dynamic libraries

void animalPrintGreeting(struct Animal* obj) {
    printf("%s pozdravlja: %s \n", obj->vtable[0](obj), obj->vtable[1]());
    return;
}

void animalPrintMenu(struct Animal* obj) {
    printf("%s voli %s \n", obj->vtable[0](obj), obj->vtable[2]());
    return;
}

int main(void)
{
    struct Animal *p1 = (struct Animal *)myfactory("parrot", "Modrobradi");
    struct Animal *p2 = (struct Animal *)myfactory("tiger", "Strasko");
    if (!p1 || !p2) {
        printf("Creation of plug-in objects failed.\n");
        exit(1);
    }

    animalPrintGreeting(p1); //"Sto mu gromova!"
    animalPrintGreeting(p2); //"Mijau!"

    animalPrintMenu(p1); //"brazilske orahe"
    animalPrintMenu(p2); //"mlako mlijeko"

    free(p1);
    free(p2);
}