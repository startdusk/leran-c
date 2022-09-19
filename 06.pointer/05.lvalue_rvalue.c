#include <stdio.h>

int main(void)
{
    // 左值，右值
    // 左值必须为 内存空间(被操作的地方)
    // 右值必须为 值(单纯就是一个值,不涉及存储)
    int a;
    a = 2;
    int *p = &a;
    *p = 2;
    int b = *p;

    // &a = p; error
    // *p + 1 = 3; error

    int array[4] = {0};
    int *pa = array;
    *pa = 2;
    *(pa++) = 3;
    // *pa + 1 = 4;
    return 0;
}