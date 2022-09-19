#include <stdio.h>
#include "./include/io_utils.h"

// 枚举
typedef enum Media
{
    MP4,      // 0
    MP3 = 10, // 10
    MKV,      // 11
    STREAM,   // 12
} Media;

typedef enum FileFormat
{
    PNG,
    JPEG,
    BMP,
    UNKNOWN
} FileFormat;

FileFormat guess_format(char *file_path)
{
    FILE *file = fopen(file_path, "rb");
    FileFormat file_format = UNKNOWN;
    if (file)
    {
        char buffer[8] = {0};
        size_t bytes_count = fread(buffer, 1, 8, file);
        if (bytes_count == 8)
        {
            // bmp: 42 4D
            // png: 89 50 4E 47 0D 0A 1A 0A
            // jpeg: FF 08 FF E0
            if (*((short *)buffer) == 0x4D42)
            {
                file_format = BMP;
            }
            else if (*((long long *)buffer) == 0x0A1A0A0D474E5089)
            {
                file_format = PNG;
            }
            else if (*((int *)buffer) == 0xE0FFD8FF)
            {
                file_format = JPEG;
            }
        }

        fclose(file);
    }
    return file_format;
}

int main(void)
{
    FileFormat file_format = UNKNOWN;
    PRINT_INT(guess_format("./images/c.bmp"));
    PRINT_INT(guess_format("./images/c.jpeg"));
    PRINT_INT(guess_format("./images/c.png"));
    PRINT_INT(guess_format("./images/c.webp"));

    // C语言枚举的缺陷，枚举可以被赋值(没有类型限制)
    FileFormat file_format1 = 10;
    return 0;
}