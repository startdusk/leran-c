#ifndef INCLUDE_TIME_UTILS_H_
#define INCLUDE_TIME_UTILS_H_

#if defined(_WIN32) // win
#include <sys/timeb.h>
#elif defined(__unix__) || defined(__APPLE__) // linux
#include <sys/time.h>
#endif

typedef long long long_time_t;

// 获取毫秒
long_time_t time_in_millisecond(void)
{
#if defined(_WIN32)
    struct timeb time_buffer;
    ftime(&time_buffer);
    return time_buffer.time * 1000LL + time_buffer.millitm;
#elif defined(__unix__) || defined(__APPLE__)
    struct timeval time_value;
    gettimeofday(&time_value, NULL);
    return time_value.tv_sec * 1000LL + time_value.tv_sec / 1000;
#elif defined(__STDC__) && __STDC_VERSION__ == 201112L // C11版本
    struct timespec timespec_value;
    timespec_get(&timespec_value, TIME_UTC);
    return timespec_value.tv_sec * 1000LL + timespec_value.tv_nsec / 1000000;
#else
    // 判断出来系统，也就为了让程序运行，不追求精准，把秒数×1000
    time_t current_time = time(NULL);
    return current_time * 1000LL;
#endif
}

#endif // INCLUDE_TIME_UTILS_H_
