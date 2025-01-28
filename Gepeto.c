#include <stdio.h>
#include <math.h>

int main() {
    int N, original_N, maior_fator = 0, maior_expoente = 0, contador;
    double maior_potencia = 0, potencia_teste;

    printf("Escreva seu valor: ");
    scanf("%d", &N);

    original_N = N; // Guardar o valor original de N para casos onde N é primo

    for (int i = 2; i <= N / 2; i++) {
        contador = 0;

        // Dividir N pelo fator primo i enquanto for possível
        while (N % i == 0) {
            N = N / i;
            contador++;
        }

        // Verificar se encontramos uma nova maior potência
        if (contador > 0) {
            potencia_teste = pow(i, contador);

            if (potencia_teste > maior_potencia) {
                maior_potencia = potencia_teste;
                maior_fator = i;
                maior_expoente = contador;
            }
        }
    }

    // Caso N seja primo e maior que 1, ele é o maior fator com expoente 1
    if (N > 1) {
        maior_fator = N;
        maior_expoente = 1;
        maior_potencia = pow(N, 1);
    }

    printf("%.0lf = %d^%d\n", maior_potencia, maior_fator, maior_expoente);

    return 0;
}
