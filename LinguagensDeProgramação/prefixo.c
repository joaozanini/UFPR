#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str); 

    int len = strlen(str);  

    for(int i = 1; i <= len; i++) {
        printf("%.*s\n", i, str);
    }

    return 0;
}
