#include <stdio.h>

int main()
{   
    char str[1000];
    fgets(str, sizeof(str), stdin);
    
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    
    printf("%d", len);
    
    return 0;
}
