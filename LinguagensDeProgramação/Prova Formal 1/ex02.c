#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int val;
    int reg = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val % 2 == 0) {
            if(val > reg) {
                reg = val;
            }
        }
    }

    printf("%d", reg);
    return 0;
}