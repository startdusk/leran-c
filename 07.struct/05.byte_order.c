#include "./include/io_utils.h"

// 判断是不是大端序1=是 0=不是
int is_big_endian()
{
    union
    {
        char c[2];
        short s;
    } value = {.s = 0x100};

    return value.c[0] == 1;
}

int main(void)
{
    PRINT_INT(is_big_endian());
    return 0;
}
