#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#if defined(__APPLE__) || defined(__linux__)
#include <unistd.h>
#elif defined(_WIN32)
#include <io.h>
#endif

void redirect_stdout(char const *filename)
{
    static int saved_stdout_no = -1;
    if (filename)
    {
        // 还没有指向自定义的输出流，就默认指向标准输出流
        if (saved_stdout_no == -1)
        {
            // dup 指向一个打开的文件
            saved_stdout_no = dup(fileno(stdout));
        }
        fflush(stdout);
        freopen(filename, "a", stdout);
    }
    else
    {
        if (saved_stdout_no != -1)
        {
            fflush(stdout);
            dup2(saved_stdout_no, fileno(stdout));
            close(saved_stdout_no);
            saved_stdout_no = -1;
        }
    }
}

int main(void)
{
    puts("1");
    redirect_stdout("output.log"); // 输出流重定向到 output.log
    puts("2");
    redirect_stdout(NULL); // 输出流重定向到 stdout
    puts("3");
    redirect_stdout("output.log"); // 输出流重定向到 output.log
    puts("4");
    redirect_stdout(NULL); // 输出流重定向到 stdout
    puts("end");
    return 0;
}