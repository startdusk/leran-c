#define _XOPEN_SOURCE // 对C标准的扩展，必须定义该宏

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "./include/io_utils.h"
#include "./include/time_utils.h"

void do_hard_work(void)
{
    double sum = 0;
    for (int i = 0; i < 100000000; i++)
    {
        sum += i * i / M_PI;
    }
    PRINT_DOUBLE(sum);
}

int main(void)
{
    // 计算时间差
    // 计时一般用毫秒
    long_time_t start_time_ms = time_in_millisecond();
    do_hard_work();
    long_time_t end_time_ms = time_in_millisecond();
    PRINT_LLONG(start_time_ms);
    PRINT_LLONG(end_time_ms);
    PRINT_LLONG(end_time_ms - start_time_ms);

    // clock() 返回的是处理器消耗的时间，更能真实的反映程序运行的耗时(衡量程序的性能)
    // time() 返回的系统时间，更适合描述真实世界的时间变化
    clock_t start_time_c = clock();
    do_hard_work();
    clock_t end_time_c = clock();
    PRINT_DOUBLE((end_time_c - start_time_c) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}