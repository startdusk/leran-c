#include <stdio.h>
#include <limits.h>

int main()
{
    printf("short int size: %lu\n", sizeof(short int)); // 2
    printf("int size: %lu\n", sizeof(int));             // 4
    printf("long int: %lu\n", sizeof(long int));        // 8

    printf("max int %d. min int %d\n", INT_MAX, INT_MIN);
    // 无符号打印整数用 %u
    printf("unsigned max int %u. unsigned min int %u\n", UINT_MAX, 0);
    return 0;
}