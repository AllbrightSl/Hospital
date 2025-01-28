#include <stdio.h>
int main(){
    int N, soma = 0;
    printf("Escreva seu limite: ");
    scanf("%d", &N);
    
    for(int i = 3; i < N; i +=2){
        soma = i + soma;
    }
    printf("Soma: %d", soma);
    return 0;
}