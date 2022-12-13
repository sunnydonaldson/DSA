#include "string_operations.h"
#include "stdio.h"

int main() {
    char *str = "myStr";
    printf("length of '%s' = %d\n", str, length_str(str));
    return 0;
}