#include <stdio.h>

int compararStrings(const char *a, const char *b) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) {
            return -1;
        } else if (a[i] > b[i]) {
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

    int resultado = compararStrings(A, B);
    printf("%d\n", resultado);

    return 0;
}
