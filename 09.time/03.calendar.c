#include <time.h>

#include "./include/io_utils.h"
#include "./include/time_utils.h"

int main(void)
{
    time_t current_time;
    time(&current_time);
    PRINT_LLONG(current_time);
    // localtime 本地日历时间
    struct tm *calendar_time = localtime(&current_time);
    PRINT_INT(calendar_time->tm_year);
    PRINT_INT(calendar_time->tm_mon);
    PRINT_INT(calendar_time->tm_mday);
    PRINT_INT(calendar_time->tm_hour);
    PRINT_INT(calendar_time->tm_min);
    PRINT_INT(calendar_time->tm_sec);

    calendar_time->tm_sec = 70;
    // mktime对时间进行格式化，并转化成time_t 类型
    time_t current_time2 = mktime(calendar_time);
    PRINT_LLONG(current_time2);
    PRINT_INT(calendar_time->tm_year);
    PRINT_INT(calendar_time->tm_mon);
    PRINT_INT(calendar_time->tm_mday);
    PRINT_INT(calendar_time->tm_hour);
    PRINT_INT(calendar_time->tm_min);
    PRINT_INT(calendar_time->tm_sec);

    // gmtime 格林威治日历时间
    struct tm *gmt = gmtime(&current_time);
    PRINT_INT(gmt->tm_year);
    PRINT_INT(gmt->tm_mon);
    PRINT_INT(gmt->tm_mday);
    PRINT_INT(gmt->tm_hour);
    PRINT_INT(gmt->tm_min);
    PRINT_INT(gmt->tm_sec);
    return 0;
}