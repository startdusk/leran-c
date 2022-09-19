#include <stdio.h>

int sum_in_array(int array[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += array[i];

    return sum; // 返回值会发生copy操作
}

void sum_in_array_no_copy(int array[], int len, int *sum)
{
    // sum 直接是外部指针,没有拷贝操作
    *sum = 0; // 赋值为0,避免指向其他东西
    for (int i = 0; i < len; i++)
        *sum += array[i];
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    // 会发生两次拷贝,
    // 一次从函数退出拷贝到寄存器,然后从寄存器拷贝到arr_sum
    int arr_sum = sum_in_array(arr, 5);

    int sum = 0;
    sum_in_array_no_copy(arr, 5, &sum);
    printf("arr_sum=%d, sum=%d\n", arr_sum, sum);
    return 0;
}

// 使用指针作为返回值
// 1.避免返回值带来的拷贝开销(特别是对象特别大的情况下)
// 2.C语言只能返回单个值,所以使用指针参数作为返回值可以实现函数的多个返回值的目的
