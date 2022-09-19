#include <stdio.h>

// 定义一个unsigned char*指针，可以用来遍历字节
typedef unsigned char *pointer;

// 打印字节序是大端还是小端，pc使用小端，网络传输使用大端
void show_bytes(pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf("%p\t0x%.2x\n", start + i, start[i]);
    }
    printf("\n");
}

int main(void)
{
    int a = 15213;
    printf("int a = %d;\n", a);
    // (pointer)&a 是把a转成 unsigned char*指针(相当于一个char[] 数组)，可以用来遍历字节
    show_bytes((pointer)&a, sizeof(int));
    // 会输出如下结果
    // int a = 15213;
    // 0x7ffeec7a71a4  0x6d
    // 0x7ffeec7a71a5  0x3b
    // 0x7ffeec7a71a6  0x00
    // 0x7ffeec7a71a7  0x00
    return 0;
}