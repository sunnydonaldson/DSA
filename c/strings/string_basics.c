#include <stdio.h>

static void instantiatingStrings()
{
    // This isn't a string, it's just a character array
    // Because there's no null termination character
    char char_array[] = {'a', 'b', 'c'};
    printf("%s\n", char_array);

    // These are strings because they have the null termination character
    // \0
    char my_str[] = {'a', 'b', 'c', 'd', '\0'};
    printf("%s\n", my_str);
    char other_str[] = {97, 90, 65, '\0'};
    printf("%s\n", other_str);

    // The compiler takes care of adding the null termination character for us
    // If we use a string literal.
    char easiest[] = "Easiest way to make a string!";
    printf("%s\n", easiest);
}

static void readingFromStdin()
{
    // getline reads until newline.
    // It dynamically allocates extra memory, up to a specified cap.
    // This is safer than gets, which just naively reads forever.
    printf("enter a line:\n");
    char *line = NULL;
    size_t size = 255;
    ssize_t chars_read = getline(&line, &size, stdin);
    printf("line: %s\n", line);

    // scanf reads a single word.
    printf("enter a word:\n");
    char word[31];
    scanf("%s", word);
    printf("word: %s\n", word);
}

static size_t length(char str[])
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int main()
{
    instantiatingStrings();
    readingFromStdin();
    char str[] = "bacon";
    printf("length of %s: %zu\n", str, length(str));
    return 0;
}