#include <time.h>
#include <sys/timeb.h>

#include "./include/io_utils.h"

#ifdef __unix__
#include <sys/time.h>
#endif

int main(void)
{
    time_t;
    clock_t;
    struct tm;
    struct timespec; // C11; MSVC
    struct timeb;
#ifdef __unix__
    struct timeval;
#endif
    return 0;
}