#include <stdio.h>

int main() {
    char A[201];
    char B[101];
    int i = 0, j = 0;

    scanf("%s", A);
    scanf("%s", B);

    while (A[i] != '\0') {
        i++;
    }

    while (B[j] != '\0') {
        A[i] = B[j];
        i++;
        j++;
    }

    A[i] = '\0';
    printf("%s\n", A);

    return 0;
}
