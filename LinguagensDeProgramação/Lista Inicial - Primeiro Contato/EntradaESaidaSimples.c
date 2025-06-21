#include <stdio.h>
#include <conio.h>

int main() {
    int intValue;
    char chValue;
    float flutuante;
    char texto[100];

    scanf("%d", &intValue);
    chValue = getch();
    scanf("%f", &flutuante);
    getchar();
    gets(texto);
    printf("%d\n", intValue);
    printf("%d %c\n", chValue, chValue);
    printf("%.2f\n", flutuante);
    printf("%s\n", texto);



    return 0;
}
