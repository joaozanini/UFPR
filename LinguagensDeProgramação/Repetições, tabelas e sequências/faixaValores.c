#include <stdio.h>

int main() {
    int x1, x2, y1, y2;

    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &y1);
    scanf("%d", &y2);

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            printf("%d\t", x + y);
        }
        printf("\n");
    }

    return 0;
}
