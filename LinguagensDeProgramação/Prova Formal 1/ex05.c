#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _CEL {
    int valor;
    struct _CEL *prox;
} CEL;

int main() {
    CEL *comeco = NULL, *agora = NULL, *novo = NULL;
    int numero;

    while (true) {
        scanf("%d", &numero);

        if (numero == 999) {
            break;
        }

        novo = (CEL *)malloc(sizeof(CEL));
        if (novo == NULL) {
            printf("Erro de alocação de memória.\n");
            return 1;
        }

        novo->valor = numero;
        novo->prox = NULL;

        if (comeco == NULL) {
            comeco = novo;
        } else {
            agora->prox = novo;
        }
        agora = novo;
    }

    agora = comeco;
    while (agora != NULL) {
        printf("%d ", agora->valor);
        agora = agora->prox;
    }
    printf("\n");

    agora = comeco;
    while (agora != NULL) {
        CEL *temp = agora;
        agora = agora->prox;
        free(temp);
    }

    return 0;
}