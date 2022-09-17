#include <stdio.h>
#include <stdarg.h>

void printlnf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

// 格式化打印并换行
#define PRINTLNF(format, ...) printf("("__FILE__              \
                                     ":%d) %s: " format "\n", \
                                     __LINE__, __FUNCTION__, ##__VA_ARGS__)

// 格式化打印int变量 如：int x = 3 PRINT_INT(x) => x: 3
#define PRINT_INT(value) PRINTLNF(#value ": %d", value)

int main(void)
{
    int value = 2;
    printlnf("Hello World: %d", value);
    PRINTLNF("Hello World: %d", value);
    PRINTLNF("Hello World");

    int x = 3;
    PRINT_INT(x);
    return 0;
}