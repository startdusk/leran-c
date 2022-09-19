#include <stdio.h>
#include "include/fib.h"

void fib_demo(void);

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        unsigned int res = factorial(i);
        printf("facotial(%d)=%u\n", i, res);
    }

    fib_demo();
    return 0;
}