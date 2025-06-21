#include <stdio.h>
#include <string.h>

int main()
{   
    char str[100];
    char caractere;
    
    fgets(str, sizeof(str), stdin);
    scanf("%s", &caractere);
    
    for (int i = 0; i <= sizeof(str); i++) {
        if (str[i] == caractere) {
            printf("%d", i);
            break;
        } 
        
        if (str[i] == '\0') {
            printf("%d", -1);
            break;
        }
    }
    
    return 0;
}
