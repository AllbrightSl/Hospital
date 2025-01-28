#include <stdio.h>
int main(){
    int n, digito, soma, pot;
    printf("Digite um numero: ");
    scanf("%d", &n);

    soma = 0;
    pot = 1;

    while (n != 0){
    digito = n%2;
    n = n/2;
    soma = soma + (digito*pot);
    pot = pot*10;
    }

    printf("Seu numero eh: %d", soma);
    return 0;
}