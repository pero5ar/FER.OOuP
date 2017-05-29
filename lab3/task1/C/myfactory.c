#include "myfactory.h"

#include <stdio.h>
#include <windows.h>

typedef struct Animal* (*PTRFUN_AC) (char const*);

void* myfactory(char const* libname, char const* ctorarg)
{
    HMODULE hDLL = LoadLibrary(libname);
    if (hDLL == NULL) {
        fprintf(stderr, "Cannot load library %s\n", libname);
        return NULL;
    }
    PTRFUN_AC create = (PTRFUN_AC) GetProcAddress(hDLL, "create");
    return create(ctorarg);
}