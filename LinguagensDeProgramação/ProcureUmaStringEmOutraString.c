#include <stdio.h>

#define MAX 1000

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

int tamanho(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int encontrarPosicao(char A[], char B[]) {
    int lenA = tamanho(A);
    int lenB = tamanho(B);

    if (lenA == 0 || lenA > lenB) return -1;

    for (int i = 0; i <= lenB - lenA; i++) {
        int j = 0;
        while (j < lenA && toLower(B[i + j]) == toLower(A[j])) {
            j++;
        }
        if (j == lenA) return i;
    }

    return -1;
}

int main() {
    char A[MAX], B[MAX];

    fgets(A, MAX, stdin);
    fgets(B, MAX, stdin);

    for (int i = 0; A[i] != '\0'; i++)
        if (A[i] == '\n' || A[i] == '\r') A[i] = '\0';

    for (int i = 0; B[i] != '\0'; i++)
        if (B[i] == '\n' || B[i] == '\r') B[i] = '\0';

    int pos = encontrarPosicao(A, B);
    printf("%d\n", pos);

    return 0;
}
