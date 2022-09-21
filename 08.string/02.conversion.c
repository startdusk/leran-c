#include "./include/io_utils.h"
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    PRINT_INT(atoi("1234"));  // 1234
    PRINT_INT(atoi("a1234")); // 0

    char const *const k_input = "1 20000000000000000000000000000000000000 3 -4 fdsaf bda";
    PRINTLNF("parse: %s", k_input);

    char const *start = k_input;
    char *end;
    while (1)
    {
        errno = 0; // 清空错误
        const long i = strtol(start, &end, 10);
        if (start == end)
            break;

        printf("'%.*s'\t ===> %ld.", (int)(end - start), start, i);
        if (errno == ERANGE)
            perror("解析错误"); // 打印错误，错误包含在了perror里面，传入的参数是上下文信息

        putchar('\n');
        start = end;
    }

    PRINTLNF("left: %s", end);
    return 0;
}