#include <stdio.h>
#include <string.h>
#include <ctype.h>

void contarFrequencia(const char *str, int freq[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;
        }
    }
}

int main() {
    char str1[100], str2[100];
    int freq1[26] = {0}, freq2[26] = {0};

    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    contarFrequencia(str1, freq1);
    contarFrequencia(str2, freq2);

    int isAnagrama = 1;
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            isAnagrama = 0;
            break;
        }
    }

    if (isAnagrama) {
        printf("É anagrama.\n");
    } else {
        printf("Não é anagrama.\n");
    }

    return 0;
}