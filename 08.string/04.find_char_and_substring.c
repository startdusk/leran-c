#include <string.h>

#include "./include/io_utils.h"

int main(void)
{
    char *string = "Hello World!";
    char *result = strchr(string, 'l');          // 从左往右开始，碰到第一个'l'就截断
    char *result_reverse = strrchr(string, 'l'); // 从右往左开始，碰到第一个'l'就截断
    puts(result);                                // llo World!
    puts(result_reverse);                        // ld!

    char *string2 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
    char *bread_set = ",;";
    int count = 0;
    char *p = string2;

    do
    {
        p = strpbrk(p, bread_set); // 按字符集拆分
        if (p)
        {
            puts(p);
            p++; // 指向切分后的字符串首地址
            count++;
        }
    } while (p);

    PRINTLNF("find %d char", count);

    char *string3 = "Hello World!";
    char *substring = strstr(string3, "Wo"); // 截取子字符串(从W索引开始到结尾)
    PRINTLNF("%s", substring);               // World!
    return 0;
}