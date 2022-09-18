#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    // 定义为12 因为最后一个字符为\0
    char string[] = "Hello World";
    for (int i = 0; i < 11; i++)
    {
        printf("i=%d, val=%c\n", i, string[i]);
    }

    printf("%s\n", string);

    char string_zh[] = "你好，中国";
    printf("%s\n", string_zh);

    // 宽字符 两个字节的char，结尾也是 \0
    wchar_t ws[] = L"你好，中国123";
    // TODO: 下面打印不出来？？？
    setlocale(LC_ALL, "zh_CN.UTF-8");
    wprintf(L"ws: %ls\n", ws);
    return 0;
}
