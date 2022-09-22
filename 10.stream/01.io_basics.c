#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "./include/io_utils.h"

int main(void)
{
    FILE *file = fopen("test.txt", "r");
    if (file)
    {
        puts("Open successfully.");
        int err = ferror(file);
        PRINT_INT(err);
        int eof = feof(file);
        PRINT_INT(eof);
        fclose(file);
    }
    else
    {
        perror("fopen");
    }

    for (int i = 0; i < 10; i++)
    {
        PRINT_INT(i);
        puts(strerror(i));
    }

    // stdout 标准输出流
    // stderr 标准错误流
    // stdin  标准输入流
    return 0;
}