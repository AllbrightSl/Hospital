#include <stdio.h>
int main(){
    int i, n, cont, ant, next, temp;

    printf("Digite a quantia de numeros a serem lidos: ");

    scanf("%d", &n);   
    cont = 0; 
    ant = 0;

    for (int i = 1; i <= n; i++){
        scanf("%d", &next);

        if (next < ant)
            cont++;
        else{
            ant = next;
        }
        if (cont != 0){
            printf("Sequencia nao ordenada\n");
            break;
        }
    
    }
    if (cont == 0){
        printf("Sequencia ordenada\n");
    }
    return 0;
}