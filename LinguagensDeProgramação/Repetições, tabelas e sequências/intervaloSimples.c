#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    if (a < b) {
        for(int i = a; i <= b; i++) {
            printf("%d\n", i);
        }
    } else {
        for(int i = b; i <= a; i++) {
            printf("%d\n", i);
        }
    }

    return 0;
}
