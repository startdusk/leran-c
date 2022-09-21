#include <string.h>

#include "./include/io_utils.h"

int main(void)
{
    char src[] = "Hello World";
    char dest[10] = "C said: ";
    PRINTLNF("dest len=%d", strlen(dest)); // 8
    strcat(dest, src);                     // strcat 把src追加到dest中
    PRINTLNF("dest len=%d", strlen(dest)); // 19
    puts(dest);

    char dest1[30] = "CPP said: ";
    // + strlen(dest1) 表示copy src 到 dest1 后面
    // strcpy copy src的长度为strlen(dest1)的长度。。
    strcpy(dest1 + strlen(dest1), src);
    puts(dest1);
    return 0;
}
