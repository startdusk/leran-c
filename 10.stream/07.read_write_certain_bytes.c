#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "./include/io_utils.h"

// 读取指定大小的字节
void echo(void)
{
#define BUFFER_SIZE 4
    int buffer[BUFFER_SIZE];
    while (1)
    {
        // fread 要读满buffer才会返回
        size_t bytes_read = fread(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdin);
        if (bytes_read < BUFFER_SIZE)
        {
            if (feof(stdin))
            {
                puts("EOF");
                fwrite(buffer, sizeof(buffer[0]), bytes_read, stdout);
            }
            else if (ferror(stdin))
            {
                perror("Error read from stdin");
            }
            break;
        }
        fwrite(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdout);
    }
}

int main(void)
{
    echo();
    return 0;
}