#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 3
#define LIMITE 100

int main() {
    int matriz[TAMANHO][TAMANHO];
    int soma = 0, acimaDe50 = 0;

    // Configurar a semente para geração de números aleatórios
    srand(time(NULL));

    // Gerar valores aleatórios para a matriz
    printf("Matriz 3x3 gerada:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = rand() % LIMITE; // Valores entre 0 e 99
            printf("%2d ", matriz[i][j]);
            soma += matriz[i][j];
            if (matriz[i][j] > 50) {
                acimaDe50++;
            }
        }
        printf("\n");
    }

    // Resultados
    printf("\nSoma dos elementos: %d\n", soma);
    printf("Quantidade de elementos acima de 50: %d\n", acimaDe50);

    return 0;
}
