#include <stdio.h>

int main()
{
    int val1, val2, menor, mdc = 1;
    scanf("%d", &val1);
    scanf("%d", &val2);

    if (val1 < val2) {
        menor = val1;
    } else {
        menor = val2;
    }

    for (int i = menor; i > 1; i--) {
        if (val1 % i == 0 && val2 % i == 0) {
            mdc = i;
            break;
        }
    }

    printf("%d\n", mdc);

    return 0;
}