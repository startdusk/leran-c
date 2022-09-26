#include <stdio.h>
#include <locale.h>

#include "./include/io_utils.h"

int main(void)
{
    FILE *file = fopen("./data/io_utils.h", "rb");
    long position = ftell(file);
    PRINT_LONG(position);
    char buffer[128];
    fread(buffer, 1, 128, file);
    PRINT_LONG(ftell(file));
    fseek(file, 10, SEEK_SET);
    PRINT_LONG(ftell(file));
    return 0;
}