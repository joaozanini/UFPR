#include <stdio.h>

int main() {
    int a0, razao, n;
    
    scanf("%d", &a0);
    scanf("%d", &razao);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int termo = a0 + i * razao;
        printf("%d\n", termo);
    }

    return 0;
}
