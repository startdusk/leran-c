#include <stdio.h>
#include "include/fib.h"

void fib_demo(void)
{

    for (int i = 0; i < 10; i++)
    {
        unsigned int res = factorial(i);
        printf("fib_demo facotial(%d)=%u\n", i, res);
    }
}