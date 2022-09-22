#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "./include/io_utils.h"

void read_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        int next_char = getc(file);
        while (next_char != EOF)
        {
            putchar(next_char);
            next_char = getc(file);
        }
        fclose(file);
    }
    else
    {
        puts(strerror(errno));
        perror("fopen");
    }
}

int main(void)
{
    // getchar 从stdin读取一个字符
    // putchar 向stdout输出一个字符(等价于 putc(c, stdout))
    // putc, fputc 向指定流当中写入字符
    // while (1)
    // {
    //     // 读取命令行输入的字符(返回的数字，要转换成字符)
    //     int next_input = getchar();
    //     if (next_input == EOF)
    //     {
    //         break;
    //     }
    //     else if (next_input == '\n')
    //     {
    //         continue;
    //     }
    //     // printf("%c\n", next_input);
    //     putchar(c);
    // }
    read_file("test.txt");
    return 0;
}
