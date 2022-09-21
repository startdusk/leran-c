#include <string.h>
#include <stdlib.h>

#include "./include/io_utils.h"

int main(void)
{
    char string[] = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";

    typedef struct
    {
        char *name;
        int year;
    } Language;

    const char *language_break = ";";
    const char *field_break = ",";

    int language_capacity = 3;
    int language_size = 0;

    Language *languages = malloc(sizeof(Language) * language_capacity);
    if (!languages)
    {
        abort(); // 分配内存失败，直接退出
    }
    // strtok内部会维护一个状态，所以后面接续切分string，就传NULL(非线程安全)
    char *next = strtok(string, field_break);
    while (next)
    {
        Language language;
        language.name = next;

        next = strtok(NULL, language_break);
        if (next)
        {
            language.year = atoi(next);

            if (language_size + 1 >= language_capacity)
            {
                language_capacity *= 2;
                languages = realloc(languages, sizeof(Language) * language_capacity);
                if (!languages)
                {
                    abort();
                }
            }

            languages[language_size++] = language;
            next = strtok(NULL, field_break);
        }
    }

    PRINTLNF("languages %d", language_size);
    PRINTLNF("languages capacity: %d", language_capacity);
    for (int i = 0; i < language_size; i++)
    {
        PRINTLNF("index=%d, name=%s, year=%d", i, languages[i].name, languages[i].year);
    }
    free(languages);
    return 0;
}