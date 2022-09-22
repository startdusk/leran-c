#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <locale.h>

#include "./include/io_utils.h"
#include "./include/time_utils.h"

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

int copy_file(char const *src, char const *dest)
{
    if (!src || !dest)
    {
        return COPY_ILLEGAL_ARGUMENTS;
    }

    FILE *src_file = fopen(src, "r");
    if (!src_file)
    {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dest_file = fopen(dest, "w");
    if (!dest_file)
    {
        fclose(src_file);
        return COPY_DEST_OPEN_ERROR;
    }
    int result;
    while (1)
    {
        int next = fgetc(src_file);
        if (next == EOF)
        {
            if (ferror(src_file))
            {
                result = COPY_SRC_READ_ERROR;
            }
            else if (feof(src_file))
            {
                result = COPY_SUCCESS;
            }
            else
            {
                result = COPY_UNKNOWN_ERROR;
            }
            break;
        }

        if (fputc(next, dest_file) == EOF)
        {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
    }
    fclose(src_file);
    fclose(dest_file);
    return result;
}
int copy_file2(char const *src, char const *dest)
{
    if (!src || !dest)
    {
        return COPY_ILLEGAL_ARGUMENTS;
    }

    FILE *src_file = fopen(src, "r");
    if (!src_file)
    {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dest_file = fopen(dest, "w");
    if (!dest_file)
    {
        fclose(src_file);
        return COPY_DEST_OPEN_ERROR;
    }
    int result = COPY_SUCCESS;
    char buffer[BUFSIZ];
    char *next;
    while (1)
    {
        next = fgets(buffer, BUFSIZ, src_file);
        if (!next)
        {
            if (ferror(src_file))
            {
                result = COPY_SRC_READ_ERROR;
            }
            else if (feof(src_file))
            {
                result = COPY_SUCCESS;
            }
            else
            {
                result = COPY_UNKNOWN_ERROR;
            }
            break;
        }

        if (fputs(next, dest_file) == EOF)
        {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
    }

    fclose(src_file);
    fclose(dest_file);
    return result;
}

int main(void)
{
    setlocale(LC_ALL, "zh_CN.utf-8");
    char *srcs[] = {"./include/io_utils.h", "./include/time_utils.h"};
    char *dests[] = {"./data_copy/io_utils.h", "./data_copy/io_utils.h"};

    for (int i = 0; i < 2; i++)
    {
        time_cost(NULL);
        copy_file(srcs[i], dests[i]);
        time_cost(srcs[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        time_cost(NULL);
        copy_file2(srcs[i], dests[i]);
        time_cost(srcs[i]);
    }
    return 0;
}