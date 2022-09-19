#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

// 宏只允许定义一行，如果定义过长请使用换行符号
#define IS_HEX_CHAR(ch)                 \
    ((ch) >= '0' && (ch) <= '9') ||     \
        ((ch) >= 'A' && (ch) <= 'F') || \
        ((ch) >= 'a' && (ch) <= 'f')

int main(void)
{
    // 宏只是做文本替换，会抹除类型
    // 不要在宏里面做其他操作如 MAX(MAX(1,2), 3), MAX(a++, 1)
    int max = MAX(1, 3);
    printf("max=%d\n", max);
    printf("is hex char %d\n", IS_HEX_CHAR('R'));
    return 0;
}