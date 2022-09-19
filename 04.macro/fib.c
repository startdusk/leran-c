#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

unsigned int factorial_by_iteration(unsigned int n)
{
    unsigned int result = 1;
    for (unsigned int i = n; i > 0; i--)
    {
        result *= 1;
    }
    return result;
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        unsigned int res = factorial(i);
        printf("facotial(%d)=%u\n", i, res);
    }
}
