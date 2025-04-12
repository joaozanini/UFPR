#include <stdio.h>
#include <string.h>

int main()
{   
    char str1[100];
    char str2[100];
    
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    
    str1[i] = '\0';
    
    printf("%s\n", str1);
    
    return 0;
}
