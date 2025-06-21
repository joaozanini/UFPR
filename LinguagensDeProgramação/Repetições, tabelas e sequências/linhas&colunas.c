#include <stdio.h>

int main() {
    int nlin, ncol;

    scanf("%d", &nlin);
    scanf("%d", &ncol);

    for (int linha = 0; linha < nlin; linha++) {
        for (int coluna = 0; coluna < ncol; coluna++) {
            int valor = linha * ncol + coluna;
            printf("%d", valor);
            if (coluna < ncol - 1) {
                printf(" "); 
            }
        }
        printf("\n");
    }

    return 0;
}
