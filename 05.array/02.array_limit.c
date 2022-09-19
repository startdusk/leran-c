#include <stdio.h>

#define ARRAY_SIZE 5

// C诞生的背景是为了写操作系统，当时硬件的性能很差
// 需要极高的效率，所以C在很多方面交给了程序员处理
// 就减少了很多代码编译的检查(减少很多指令的执行)，如数组越界是不会报错的(可能会访问到其他的内存，也可能会报错，不确定的行为)
// 因为当时的背景，程序语言是面向专业的程序员，还不像现在这样面向普罗大众

int main(void)
{
    int array[ARRAY_SIZE];
    int array_with_expression[3 + 2];

    int value = 2;

    // C99, VLA; GCC ok; MSVG errorss
    int array_size_of_value[value];

    const int k_size = 5;            // C++ ok
    int array_size_of_const[k_size]; // C99, VLA; GCC ok; MSVG error

    return 0;
}
