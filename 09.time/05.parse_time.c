#define _XOPEN_SOURCE // 对C标准的扩展，必须定义该宏

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
    char *current_time_s[20];
    // %F => %Y-%m-%d; %T => %H:%M:%S
    size_t size = strftime(current_time_s, 20, "%F %T", calendar_time);
    PRINT_INT(size); // 19
    puts(current_time_s);

    struct tm parsed_time;
    // strptime 和 strftime 是一个相反的过程
    // strptime 返回的是剩余不能格式化的字符串
    char *unparsed_string = strptime(current_time_s, "%F %T", &parsed_time); // 非C标准库函数，Linux下的POSIX对C的扩展
    PRINT_INT(parsed_time.tm_year);
    PRINT_INT(parsed_time.tm_mon);
    PRINT_INT(parsed_time.tm_mday);
    PRINT_INT(parsed_time.tm_hour);
    PRINT_INT(parsed_time.tm_min);
    PRINT_INT(parsed_time.tm_sec);

    char *time = "2022-09-23 21:50:23.123";
    puts(time);
    struct tm parsed_time1;
    char *unparsed_string1 = strptime(time, "%F %T", &parsed_time1); // 非C标准库函数，Linux下的POSIX对C的扩展
    puts(unparsed_string1);
    // 解析毫秒
    int millisecond;
    sscanf(unparsed_string1, ".%3d", &millisecond);
    PRINT_INT(millisecond);
    return 0;
}
