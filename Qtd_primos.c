#include <stdio.h>
#include <stdbool.h>

int main() {
    int N, cont = 0, valor = 2;  // Começando de 2, o primeiro número primo
    scanf("%d", &N);

    while (cont < N) {
        bool isPrime = 1;  // Assume que o número é primo até que se prove o contrário
        for (int x = 2; x * x <= valor; x++) {  // Testa até a raiz quadrada de 'valor'
            if (valor % x == 0) {
                isPrime = 0;  // Não é primo se for divisível por 'x'
                break;
            }
        }
        
        if (isPrime) {
            cont++;  // Se é primo, incrementa o contador
        }
        
        if (cont < N) {
            valor++;  // Só incrementa o valor quando o número não for o N-ésimo primo
        }
    }

    printf("%d-%d", N, valor);  // Exibe o N-ésimo número primo

    return 0;
}
