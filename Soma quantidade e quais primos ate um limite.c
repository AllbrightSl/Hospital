#include <stdio.h>

int eh_primo (int x);

int main(){
    int N, contador = 0, soma = 0;
    printf("Escreva seu limite: ");
    scanf("%d", &N);

    for (int div = 2; div <= N; div++){
        if (eh_primo(div)){
        soma = soma + div;
        printf("%d\n", div);
        contador++;
    }
    }
    printf("Tem %d primos\n", contador);
    printf("Soma = %d", soma);
    return 0;
}

    int eh_primo (int x){
        int primo = 1;

        for (int i = 2; i <= x/2; i++){
            if (x % i == 0){
                primo = 0;
            }
        }
        return primo;
    }