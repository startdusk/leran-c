#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 通用内存交换
void swap(void *first, void *second, size_t size)
{
    void *temp = malloc(size);
    if (temp)
    {
        memcpy(temp, first, size);
        memcpy(first, second, size);
        memcpy(second, temp, size);
        free(temp);
    }
    else
    {
        // Handle error
    }
}
// 因为宏是文本替换，如果碰到前面定义有相同的变量名，会有冲突
#define SWAP(a, b, type) \
    do                   \
    {                    \
        type temp = a;   \
        a = b;           \
        b = temp;        \
    } while (0)

// 不具有可移植性。。
#define SWAP_EXT(a, b)      \
    do                      \
    {                       \
        typeof(a) temp = a; \
        a = b;              \
        b = temp;           \
    } while (0)

int main(void)
{
    int a = 0;
    int b = 1;

    printf("a=%d, b=%d\n", a, b);
    swap_int(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    swap(&a, &b, sizeof(int));
    printf("a=%d, b=%d\n", a, b);

    SWAP(a, b, int);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}