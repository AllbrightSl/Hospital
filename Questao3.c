#include <stdio.h>
#include <ctype.h>
#include <string.h>

int verifica_palindromo(char *str, int inicio, int fim) {
    while (inicio < fim && !isalnum(str[inicio])) {
        inicio++;
    }
    while (inicio < fim && !isalnum(str[fim])) {
        fim--;
    }

    if (inicio >= fim) {
        return 1;
    }

    if (tolower(str[inicio]) != tolower() {
        return 0; 
    }
    return verifica_palindromo(str, inicio + 1, fim - 1);
}
int eh_palindromo(char *str) {
    int tamanho = strlen(str);
    return verifica_palindromo(str, 0, tamanho - 1);
}


int main() {
    char string[100];

    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    if (eh_palindromo(string)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
