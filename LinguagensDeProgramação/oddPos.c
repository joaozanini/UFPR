#include <stdio.h>

int main()
{
    int valores[10];
    int value;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &value);
        valores[i] = value;
    }
    
    for(int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            printf("%d\n", valores[i]);
        }
    }
    
    return 0;
}
