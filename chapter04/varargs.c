#include <stdio.h>
#include <stdarg.h>

// C语言的可变参数类型很难保证类型一致，所以需要开发者保证

// 可变参数定义方式
// 第一个参数必须为int，可变参数的个数
// 第二个参数为 ...
void handler_varargs(int arg_count, ...)
{
    // 1.定义 va_list 用于获取我们的变长参数
    va_list args;

    // 2.开始遍历
    va_start(args, arg_count);
    for (int i = 0; i < arg_count; i++)
    {
        // 3.取出对应参数 (va_list, type)
        int arg = va_arg(args, int);
        printf("index=%d, value=%d\n", i, arg);
    }

    // 4.结束遍历
    va_end(args);
}

int main(void)
{
    handler_varargs(5, 1, 2, 3, 4);
    return 0;
}