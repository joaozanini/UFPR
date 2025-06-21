#include <stdio.h>

int main() {
    int vetor[10];
    int frequencia[10] = {0};
    int i, j, max_frequencia = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (vetor[i] == vetor[j]) {
                frequencia[i]++;
            }
        }

        if (frequencia[i] > max_frequencia) {
            max_frequencia = frequencia[i];
        }
    }

    for (i = 0; i < 10; i++) {
        if (frequencia[i] == max_frequencia) {
            int ja_impresso = 0;
            for (j = 0; j < i; j++) {
                if (vetor[i] == vetor[j]) {
                    ja_impresso = 1;
                    break;
                }
            }
            if (!ja_impresso) {
                printf("%d\n", vetor[i]);
            }
        }
    }

    return 0;
}
