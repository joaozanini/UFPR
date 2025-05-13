#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str1[100];
  int nPalavras = 0;
  int inWord = 0;

  gets(str1);

  for (int i = 0; str1[i] != '\0'; i++) {
    if (!isspace(str1[i]) && !ispunct(str1[i])) {
      if (!inWord) {
        nPalavras++;
        inWord = 1;
      }
    } else {
      inWord = 0;
    }
  }

  printf("%d\n", nPalavras);

  return 0;
}