#include <stdio.h>

int main(void)
{
    int a = 2;
    int *p = &a;

    // 指针加减
    // p是指向int的指针，int是4字节，
    // p+1就相当于p在内存中移动了4个字节的位置
    printf("p+1=%d\n", *(p + 1)); // 会输出一个无意义的值

    {
        // array数组相当于 int * const array_p = array
        // 指向不能被修改，但里面的元素可以被修改
        int array[] = {0, 1, 2, 3, 4};
        int *p = array;

        // 等价操作
        printf("*(p+3)=%d\n", *(p + 3));
        printf("*(array+3)=%d\n", *(array + 3));
        printf("*(3+array)=%d\n", *(3 + array));
        printf("array[3]=%d\n", array[3]);
        printf("p[3]=%d\n", p[3]);
        // 不推荐写法
        printf("3[array]=%d\n", 3 [array]);
    }

    // 指针大小的比较仅限于连续的内存中使用才有意义，如数组
    // 其他不允许使用

    return 0;
}
