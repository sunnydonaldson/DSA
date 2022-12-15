#include "string_operations.h"
#include "stdio.h"

int main() {
    char str[] = "myStr";
    printf("length of '%s' = %d\n", str, length_str(str));

    printf("toUppercase(%s) = ", str);
    to_uppercase(str);
    printf("%s\n", str);

    printf("to_lowercase(%s) = ", str);
    to_lowercase(str);
    printf("%s\n", str);

    char camelStr[] = "camelCaseStr";
    printf("toggle_case(%s) = ", camelStr);
    toggle_case(camelStr);
    printf("%s\n", camelStr);

    char string_with_spaces[] = "  a spaced string  ";
    printf("trim '%s'\n", string_with_spaces);
    trim(string_with_spaces);
    printf("'%s'\n", string_with_spaces);

    char multi_words[] = "  multiple words in a string  ";
    printf("count words in %s:\n", multi_words);
    printf("%d\n", count_words(multi_words));

    printf("Reverse %s:\n", multi_words);
    reverse(multi_words);
    printf("%s\n", multi_words);

    return 0;
}