#include "string_operations.h"

length_str(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}