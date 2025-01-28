#include <stdio.h>

int main() {
    char operador;
    double num1, num2, resultado;

    // Pergunta ao usuário a operação
    printf("Digite a operação (+, -, *, /): ");
    scanf("%c", &operador);

    // Pergunta ao usuário os números
    printf("Digite dois números: ");
    scanf("%lf %lf", &num1, &num2);

    // Realiza a operação com base no operador
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisão por zero não é permitida.\n");
                return 1;
            }
            break;
        default:
            printf("Operador inválido.\n");
            return 1;
    }

    // Exibe o resultado
    printf("Resultado: %.2lf\n", resultado);

    return 0;
}
