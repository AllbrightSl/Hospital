#include <stdio.h>
#include <string.h>

void reverse(char s[], int start, int end) {
    // Caso base: se os índices se encontrarem ou cruzarem, a inversão está completa
    if (start >= end) {
        return;
    }

    // Trocar os caracteres nas posições `start` e `end`
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    // Chamada recursiva com os índices ajustados
    reverse(s, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o caractere de nova linha, se existir
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    reverse(str, 0, len - 1); // Chamar a função de inversão
    printf("String invertida: %s\n", str);

    return 0;
}
