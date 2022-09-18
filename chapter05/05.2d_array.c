#include <stdio.h>
#include <stdarg.h>

void sum_int_arrays(int rows, int columns, int array[][columns], int result[])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // 需要返回数组变量，就要从参数中传入该数组还有数组长度(因为自动类型变量的问题，会在返回的时候销毁变量)
            result[i] += array[i][j];
        }
    }
}

int main(void)
{
    // 定义二维数组
    int vehicle_limits[5][2];

    int scores[5][4] = {
        {135, 135, 138, 277},
        {105, 134, 108, 265},
        {113, 107, 145, 232},
        {123, 99, 140, 227},
        {98, 118, 217, 242},
    };
    int result[5] = {0, 0, 0, 0, 0};
    sum_int_arrays(5, 4, scores, result);
    for (int i = 0; i < 5; i++)
    {
        printf("res=%d\n", result[i]);
    }
    return 0;
}