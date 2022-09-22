#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "./include/io_utils.h"

void echo(void)
{
    size_t size = 1024;
    char buffer[size];
    while (1)
    {
        // 从控制台读取一行数据，fgets是安全的，size太小也没问题
        if (!fgets(buffer, 4, stdin))
        {
            break;
        }
        // 输出
        printf("%s", buffer);
    }
}

int main(void)
{
    echo();
    return 0;
}