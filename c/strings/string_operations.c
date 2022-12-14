#include "string_operations.h"

static int is_uppercase(char c);
static int is_lowercase(char c);

int length_str(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

void to_uppercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_lowercase(str[i]))
            str[i] = str[i] - 32;
    }
}

void to_lowercase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_uppercase(str[i]))
            str[i] = str[i] + 32;
    }
}

void toggle_case(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_lowercase(str[i]))
            str[i] = str[i] - 32;
        else if (is_uppercase(str[i]))
            str[i] = str[i] + 32;
    }
}

void trim(char str[])
{
    int length = length_str(str);
    int count;
    int right_count;
    int i;
    for (count = 0; str[count] == '\n' || str[count] == ' '; count++);
    for (right_count = 0; str[length - right_count -1] == '\n' || str[length - right_count -1] == ' '; right_count++);
    if  (count > 0 || right_count > 0) {
        for (i = count; i < length - right_count; i++)
            str[i - count] = str[i];
        str[i - count] = '\0';
    }


}

int count_words(char str[])
{
    trim(str);
    int space_count = 0;
    for (int i = 0; i < length_str(str); i++)
        if (str[i] == ' ' && str[i -1] != ' ')
            space_count++;
    return space_count + 1;
}

static int is_uppercase(char c)
{
    return c >= 65 && c <= 90;
}

static int is_lowercase(char c)
{
    return c >= 97 && c <= 122;
}