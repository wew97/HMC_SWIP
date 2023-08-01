// 9_ÇÔ¼ö6.c
#include <stdio.h>

// foo.h
// #include "foo.h"
extern void foo(void);

int main(void)
{
    foo();
    foo();
    foo();
    // count = 1000;

    foo();
    foo();

    return 0;
}