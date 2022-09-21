#define __STDC_WANT_LIB_EXIT1__ 1

#include <string.h>

#include "./include/io_utils.h"

int main(void)
{
    char dst[2];
    // GCC(linux) 不支持 C11 safe 函数
    int error_no = strcpy_s(dst, 2, "Too long!");
    PRINT_INT(error_no); // 34
    if (error_no)
    {
        perror("strcpy_s returns: "); //
    }
    return 0;
}