#include <stdio.h>
int par (int x){
    int cont = 0;
    if(x % 2 != 0){
        cont++;
    }
    return cont;
}
int main(){
    int N, i = 2, cont = 0, pares = 0;
    printf("Escreva o limite a ser calculado de numeros pares: ");
    scanf("%d", &N);
    while (i < N){
        if (par(i) == 0){
            printf("%d\n", i);
            pares++;
        }
        i++;

    }
    printf("Temos %d pares\n", pares);
    return 0;
}