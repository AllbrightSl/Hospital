#include <stdio.h>
int main(){
    int ant = 0, atual = 1, N, temp;
    printf("Escreva a posicao desejada: ");
    scanf("%d", &N);
    if (N == 0){
    atual = 0;
    }
    for (int i = 1; i < N; i++){
        temp = atual;
        atual = atual + ant;
        ant = temp;
    }
    printf("Seu numero: %d\n", atual);
    return 0;
}