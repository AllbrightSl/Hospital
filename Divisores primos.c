#include <stdio.h>
int main(){
    int div, n, divisores;

    printf("Digite seu numero:\n");
    scanf("%d", &n);
    div = 2;
    divisores = 0;

    while (div < n){
        if(n%div == 0)
        divisores++;
        div++;
    }
    if (divisores == 0)
    printf("Eh primo!\n");
    else{
        printf("Nao eh primo\n");
        printf("Seu numero tem %d divisores", divisores);
    }
    return 0;
}