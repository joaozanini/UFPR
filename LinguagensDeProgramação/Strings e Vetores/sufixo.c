#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str); 

    int len = strlen(str);  

    for(int i = 0; i <= len; i++) {
        printf("%.*s\n", len - i, str + i);
    }

    return 0;
}
