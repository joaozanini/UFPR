#include <stdio.h>

int main() {
    char str[101];
    int i, tamanho = 0;

    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    while (str[tamanho] != '\0') {
        tamanho++;
    }

    for (i = tamanho - 1; i >= 0; i--) {
        putchar(str[i]);
    }

    putchar('\n');
    return 0;
}
