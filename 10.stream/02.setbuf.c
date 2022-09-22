#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "./include/io_utils.h"

// 要保证文件缓冲区要大于文件的生命周期
char std_buffer[BUFSIZ];

int main(void)
{
    // 给控制台输入设置缓存区，文件关闭前(main函数退出前)，不能关闭该缓冲区
    // 所以std_buffer放在全局变量，因为main函数不是程序执行的第一行代码
    setbuf(stdout, std_buffer);

    FILE *file = fopen("test.txt", "r");
    char buff[BUFSIZ];                   // 默认使用BUFSIZ大小的缓冲区
    setvbuf(file, buff, _IOLBF, BUFSIZ); // 不要使用setbuf(功能受限制)
    // _IOLBF 按行缓冲(读取文件用这个)
    // _IOFBF 全量缓冲(读取二进制用这个)
    // _IONBF 不使用缓冲
    if (file)
    {
        puts("Open succ");
        // 因为设置了stdout缓冲区，需要清空缓冲区才能输出上面的puts
        fflush(stdout); // 清空缓冲区
        fclose(file);
    }
    return 0;
}