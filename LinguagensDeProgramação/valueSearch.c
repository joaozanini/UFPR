#include <stdio.h>

int main()
{
    int valores[10];
    int value;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &value);
        valores[i] = value;
    }

    int busca;
    scanf("%d", &busca);

    int encontrado = 0;

    for (int i = 0; i < 10; i++) {
        if (valores[i] == busca) {
            printf("%d\n", i);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("-1\n");
    }

    return 0;
}
