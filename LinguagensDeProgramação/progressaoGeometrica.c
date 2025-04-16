#include <stdio.h>

int main() {
    int a0, razao, n;
    
    scanf("%d", &a0);
    scanf("%d", &razao);
    scanf("%d", &n);

    int termo = a0;
    for (int i = 0; i < n; i++) {
        printf("%d\n", termo);
        termo *= razao;
    }

    return 0;
}
