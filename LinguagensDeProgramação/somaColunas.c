#include <stdio.h>

int main() {
    int matriz[3][4];
    int somaColunas[4] = {0, 0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
            somaColunas[j] += matriz[i][j];
        }
    }

    for (int j = 0; j < 4; j++) {
        printf("%d\n", somaColunas[j]);
    }

    return 0;
}
