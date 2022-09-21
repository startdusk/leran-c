#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "./include/io_utils.h"
#include "./include/time_utils.h"

int main(void)
{
    time_t current_time;
    time(&current_time);
    struct tm *calendar_time = localtime(&current_time);

    // asctime 和 ctime 返回的是共享的一块内存
    // 在高并发的情况下会有并发安全问题
    puts(asctime(calendar_time)); // Thu Sep 22 05:24:05 2022
    puts(ctime(&current_time));   // Thu Sep 22 05:24:05 2022

    // strftime 会新生成字符串，没有并发安全问题
    char current_time_s[20];
    size_t size = strftime(current_time_s, 20, "%Y%m%d%H%M%S", calendar_time);
    PRINT_INT(size); // 14
    puts(current_time_s);

    // C语言标准库不能格式化毫秒(设计之初没有考虑到这里)，所以我们只能自己拼接
    long_time_t current_time_in_ms = time_in_millisecond();
    int current_time_millisecond = current_time_in_ms % 1000;
    // +14表示从第14个字符开始添加进去(最后一个)
    sprintf(current_time_s + 14, "%03d", current_time_millisecond);
    puts(current_time_s);
    return 0;
}