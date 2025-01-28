#include <stdio.h>

int dividirRecursivo(int A, int B) {
    // Caso base: se A for menor que B, o quociente é 0
    if (A < B) {
        return 0;
    }

    // Reduz A subtraindo B e incrementa o quociente
    return 1 + dividirRecursivo(A - B, B);
}

int main() {
    int A, B;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    if (B == 0) {
        printf("Erro: Divisão por zero não é permitida.\n");
        return 1;
    }

    int quociente = dividirRecursivo(A, B);

    printf("Resultado da divisão inteira %d / %d = %d\n", A, B, quociente);

    return 0;
}
