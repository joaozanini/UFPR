#include <stdio.h>

int compararStrings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 < *str2) return -1;
        if (*str1 > *str2) return 1;
        str1++;
        str2++;
    }

    if (*str1 < *str2) return -1;
    if (*str1 > *str2) return 1;
    return 0;
}

int main() {
    char str1[101], str2[101];
    scanf("%100s", str1);
    scanf("%100s", str2);

    printf("%d", compararStrings(str1, str2));

    return 0;
}
