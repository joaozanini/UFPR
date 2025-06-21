#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int valores[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    for (int i = 0; i < 9; i++) {
        if (abs(valores[i] - valores[i+1]) <= 1) {
            printf("%d %d\n", valores[i], valores[i+1]);
        }
    }

    return 0;
}
