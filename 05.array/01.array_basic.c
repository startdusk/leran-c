#include <stdio.h>

#define ARRAY_SIZE 10

int main(void)
{
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i;
        printf("arrar[%d]: %d\n", i, array[i]);
    }

    // C99 开始支持按位置初始化(数组特别大的情况下，之初始化指定位置)
    char array_char[5] = {[2] = 'o',
                          'l',
                          'l'};
    for (int i = 0; i < 5; i++)
    {
        printf("arrar_char[%d]: %c\n", i, array_char[i]);
    }
    return 0;
}
