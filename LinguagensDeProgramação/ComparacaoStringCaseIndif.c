#include <stdio.h>

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int compararStringsIgnoreCaixa(const char *a, const char *b) {
    int i = 0;
    char ca, cb;

    while (a[i] != '\0' && b[i] != '\0') {
        ca = toLowerChar(a[i]);
        cb = toLowerChar(b[i]);

        if (ca < cb) {
            return -1;
        } else if (ca > cb) {
            return 1;
        }
        i++;
    }

    if (a[i] == '\0' && b[i] == '\0') {
        return 0;
    } else if (a[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    char A[101], B[101];

    fgets(A, sizeof(A), stdin);
    fgets(B, sizeof(B), stdin);

    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == '\n') {
            A[i] = '\0';
            break;
        }
    }

    for (int i = 0; B[i] != '\0'; i++) {
        if (B[i] == '\n') {
            B[i] = '\0';
            break;
        }
    }

    int resultado = compararStringsIgnoreCaixa(A, B);
    printf("%d\n", resultado);

    return 0;
}
