#include <stdio.h>

#define LENGTH 10

// C语言中的数组参数只是一个数组的首地址(根据首地址是推断不出数组的长度的)
// 所以需要传入它的长度
// 这是历史的原因，为了对性能的追求，数组不会带有数组len和cap的信息，需要程序员自己处理
int sum_int_array(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main(void)
{
    int array[LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("sum=%d\n", sum_int_array(10, array));
    return 0;
}