#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[100];
    char simbolo[2];
    
    bool encontrado = false;
    
    scanf("%s", str); 
    scanf("%s", simbolo);
    
    for(int i = 0; i < strlen(str); i++) {
        if (str[i] == simbolo[0]) {
            printf("%d\n", i);
            encontrado = true;
            break;
        }
    }
    
    if(!encontrado) {
        printf("-1\n");
    } 

    return 0;
}
