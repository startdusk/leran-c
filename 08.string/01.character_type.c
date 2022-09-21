#include <ctype.h> // 判断字符类型

#include "./include/io_utils.h"

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int main(void)
{
    PRINT_INT(isdigit('0')); // 2048
    PRINT_INT(isdigit('a')); // 0
    return 0;
}