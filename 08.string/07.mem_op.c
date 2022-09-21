#include <string.h>
#include <stdlib.h>

#include "./include/io_utils.h"

int main(void)
{
    char *mem = malloc(10);
    memset(mem, 0, 0); // 对内存清零
    PRINT_INT_ARRAY(mem, 10);
    free(mem);

    char src[] = "HelloWorld";
    char *dest = malloc(11);
    memset(dest, 0, 11);
    memcpy(dest, src, 11);
    puts(dest);

    // 移动字符串中的某个字符到某个位置，移动次数为4
    // mem*类的函数用于没有\0结尾的字符串
    // str*类的函数用于有\0结尾的字符串(能确定长度)
    memmove(dest + 3, dest + 1, 4);
    puts(dest);
    free(dest);
    return 0;
}
