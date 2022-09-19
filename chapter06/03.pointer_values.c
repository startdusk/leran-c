#include <stdio.h>

int *pointer_at_large;

void dangerous_pointer(void)
{
    int a = 2;
    // 危险，指针指向栈上的地址(野指针)，C编译器不会报错！！！
    pointer_at_large = &a;

    // ...
    // 处理，置为NULL
    pointer_at_large = NULL;
}

int main(void)
{
    // 定义指针不能使用硬编码地址
    // int *p = (int*)0x65fe18;

    int *p = NULL; // NULL 是一个宏，是0
    // *p = 3; error // 不能给0赋值，0有特殊含义

    dangerous_pointer();
    return 0;
}