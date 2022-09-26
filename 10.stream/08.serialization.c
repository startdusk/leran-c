#include "./include/io_utils.h"

#define ERROR 0
#define OK 1

typedef struct
{
    int visibility;
    int allow_notification;
    int refresh_rate;
    int region;
    int font_state;
} Settings;

void print_settings(Settings *settings)
{
    PRINT_INT(settings->visibility);
    PRINT_INT(settings->allow_notification);
    PRINT_INT(settings->refresh_rate);
    PRINT_INT(settings->region);
    PRINT_INT(settings->font_state);
}

int save_settings(Settings *settings, char *settings_file)
{
    FILE *file = fopen(settings_file, "wb");
    if (file)
    {
        fwrite(&settings->visibility, sizeof(settings->visibility), 1, file);
        fwrite(&settings->allow_notification, sizeof(settings->allow_notification), 1, file);
        fwrite(&settings->refresh_rate, sizeof(settings->refresh_rate), 1, file);
        fwrite(&settings->region, sizeof(settings->region), 1, file);
        fwrite(&settings->font_state, sizeof(settings->font_state), 1, file);
        fclose(file);
        return OK;
    }
    else
    {
        perror("Failed to save settings.");
        return ERROR;
    }
}

void loading_settings(Settings *settings, char *settings_file)
{
    FILE *file = fopen(settings_file, "rb");
    if (file)
    {
        fread(&settings->visibility, sizeof(settings->visibility), 1, file);
        fread(&settings->allow_notification, sizeof(settings->allow_notification), 1, file);
        fread(&settings->refresh_rate, sizeof(settings->refresh_rate), 1, file);
        fread(&settings->region, sizeof(settings->region), 1, file);
        fread(&settings->font_state, sizeof(settings->font_state), 1, file);
        fclose(file);
    }
    else
    {
        settings->visibility = 1;
        settings->allow_notification = 1;
        settings->refresh_rate = 30;
        settings->region = 86;
        settings->font_state = 18;
    }
}

//=================================================
// 使用结构体直接读写

int save_settings2(Settings *settings, char *settings_file)
{
    FILE *file = fopen(settings_file, "wb");
    if (file)
    {
        // 由于第一个参数是 void* 所以可以直接传结构体进去
        fwrite(settings, sizeof(Settings), 1, file);
        fclose(file);
        return OK;
    }
    else
    {
        perror("Failed to save settings.");
        return ERROR;
    }
}

void loading_settings2(Settings *settings, char *settings_file)
{
    FILE *file = fopen(settings_file, "rb");
    if (file)
    {
        fread(settings, sizeof(Settings), 1, file);
        fclose(file);
    }
    else
    {
        settings->visibility = 1;
        settings->allow_notification = 1;
        settings->refresh_rate = 30;
        settings->region = 86;
        settings->font_state = 18;
    }
}

int main(void)
{
    Settings settings;
    loading_settings2(&settings, "settings.bin");
    print_settings(&settings);
    settings.font_state = 30;
    settings.allow_notification = 0;
    save_settings2(&settings, "settings.bin");
    return 0;
}