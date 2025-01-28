#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função auxiliar para verificar palíndromo recursivamente
int verifica_palindromo(char *str, int inicio, int fim) {
    // Avança o ponteiro inicial enquanto encontrar espaços ou pontuações
    while (inicio < fim && !isalnum(str[inicio])) {
        inicio++;
    }

    // Retrocede o ponteiro final enquanto encontrar espaços ou pontuações
    while (inicio < fim && !isalnum(str[fim])) {
        fim--;
    }

    // Condição de parada: se os índices se cruzaram ou se igualaram
    if (inicio >= fim) {
        return 1;
    }

    // Verifica se os caracteres atuais são iguais (ignorando maiúsculas/minúsculas)
    if (tolower(str[inicio]) != tolower(str[fim])) {
        return 0; // Não é palíndromo
    }

    // Chama recursivamente com os próximos caracteres
    return verifica_palindromo(str, inicio + 1, fim - 1);
}

// Função principal para checar palíndromo
int eh_palindromo(char *str) {
    int tamanho = strlen(str);
    return verifica_palindromo(str, 0, tamanho - 1);
}

// Programa principal
int main() {
    char string[1000];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    // Remove o '\n' adicionado pelo fgets
    string[strcspn(string, "\n")] = '\0';

    if (eh_palindromo(string)) {
        printf("A string é um palíndromo!\n");
    } else {
        printf("A string NÃO é um palíndromo!\n");
    }

    return 0;
}
