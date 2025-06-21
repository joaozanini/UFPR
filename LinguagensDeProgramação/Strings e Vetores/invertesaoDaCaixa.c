#include <stdio.h>

#define MAX 1000

char inverterCaixa(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    } else if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}

int main() {
    char texto[MAX];

    fgets(texto, MAX, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '\n' || texto[i] == '\r') {
            texto[i] = '\0';
            break;
        }
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = inverterCaixa(texto[i]);
    }

    printf("%s\n", texto);

    return 0;
}
