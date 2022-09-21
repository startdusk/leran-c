#include <string.h>

#include "./include/io_utils.h"

int main(void)
{
    //==========================================================================
    // 取字符串的长度
    // 不安全的获取字符串长度(一个一个的数字符的做法，如果字符串足够长就容易出问题)
    char *string = "Hello World!";
    PRINT_INT(strlen(string));

    PRINT_INT(strnlen(string, 100)); // 增加一个参数maxlen, 让读取的长度限制在固定的数字

    //==========================================================================
    // 字符串比较
    char *left = "Hello World!";
    char *right = "Hello C Programmers!";
    PRINT_INT(strcmp(left, right));
    PRINT_INT(strncmp(left, right, 7)); // 相等会返回0
    return 0;
}