#include <time.h>

#include "./include/io_utils.h"
#include "./include/time_utils.h"

int main(void)
{
    time_t current_time;
    time(&current_time);

    PRINT_LLONG(current_time);

    current_time = time(NULL);
    PRINT_LONG(current_time);

    PRINT_LLONG(time_in_millisecond());
    PRINT_LLONG(time_in_millisecond());
    PRINT_LLONG(time_in_millisecond());
    PRINT_LLONG(time_in_millisecond());
    PRINT_LLONG(time_in_millisecond());
    return 0;
}
