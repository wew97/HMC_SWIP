// add.c
#if 0
// 0000000000000000 T _add
int add(int a, int b)
{
    return a + b;
}
#endif

#include <stdio.h>

int add(int a, int b);
//                  U _add

int main(void)
{
    printf("%d\n", add(100, 200));

    return 0;
}
