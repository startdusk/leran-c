// 函数指针
#include <stdio.h>
#include <stdlib.h>

// https://www.cdecl.org/ 这个网站可以查看函数类型定义
// 函数指针类型
// 1.
int *(f1)(int, double);

// 2.
int (*f2)(int, double);

// 3.
int *(f3)(int, double);

// 4.error
// int (*f4)(int, double)[]; 等价于 int p[], 但C语言不支持返回数组类型，所以不支持

// 5.
int (*f5[])(int, double); // 函数指针可以是数组 *f5[] []的优先级比*高

// 6.error
// int (*f6)[](int, double); // 函数的数组是不允许的,每个函数都是独一无二的

typedef int (*Func)(int, double); // 定义一个叫Func的函数类型

int add(int a, double b)
{
}

typedef int *intptr; // 类型别名，int的指针类型

void init_pointer(int **ptr, int len, int default_val)
{
    *ptr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
        (*ptr)[i] = default_val;
}

int main(void)
{

    int *p;
    void (*func)(int **ptr, int len, int default_val) = &init_pointer;
    func(&p, 10, 0);

    for (int i = 0; i < 10; i++)
    {
        printf("p[%d]=%d\t", i, p[i]);
        p[i] = i;
    }
    printf("\n");

    free(p);
    p = NULL;

    Func func1 = &add;
    return 0;
}