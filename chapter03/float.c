#include <stdio.h>

// 你没写参数 C不知道你要传几个参数, 如果你传入了参数，不会报错或警告。。
void empty_param_list()
{
    puts("Hello");
}

// 除非申名为void，不传参数
void empty_param_list2(void)
{
    puts("empty_param_list2");
}

int auto_int(void)
{
    // 静态变量
    // 1.作用域全局，内存不会因为函数退出而销毁
    // 2.int 初始值默认为0
    static int static_var;
    printf("static_var = %d\n", static_var);

    // 自动变量
    // 1.函数，块作用域，随着函数和块退出而销毁
    // 2.没有默认初始值
    // auto int b; C语言中用auto没啥意义，和直接 int b一样，CPP才能做类型推导
    int b;
    printf("auto int b = %d\n", b);
    return 0;
}

void clear_memery(void)
{
    int e = 1000;
}

int main()
{
    float a_float = 3.14f;
    printf("size of float: %d\n", sizeof(float));
    empty_param_list(1.0, "Hello");
    empty_param_list2();

    // 变量声明一定要初始化赋值，否则会被函数栈上的其他同类型已赋值的变量给覆盖掉
    // 如下面的代码。自动变量b会被e给覆盖
    auto_int();
    clear_memery();
    auto_int();
    clear_memery();
    return 0;
}
