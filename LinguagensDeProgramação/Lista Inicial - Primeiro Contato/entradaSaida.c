#include <stdio.h>
#include <string.h>

int main()
{
    int value;
    scanf("%d", &value);
    getchar(); 

    char tecla;
    tecla = getchar();

    float flutuante;
    scanf("%f", &flutuante);
    getchar();  

    char texto[100];
    fgets(texto, sizeof(texto), stdin);
    
    size_t len = strlen(texto);
    if (len > 0 && texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
    }

    printf("%d\n%d %c\n%.2f\n%s\n", value, tecla, tecla, flutuante, texto);

    return 0;
}
