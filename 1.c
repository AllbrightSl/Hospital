#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    double **matriz1, **matriz2;
    printf("Escreva o tamanho n da matriz: ");
    scanf("%d", &n);

    matriz1 = malloc(n * sizeof(double*));
    matriz2 = malloc(n * sizeof(double*));

    if(matriz1 == NULL || matriz2 == NULL)
    return -1;

    else{

    for (int i = 0; i < n; i++){
    matriz1[i] = (double*) malloc(n * sizeof(double));
    matriz2[i] = (double*) malloc(n * sizeof(double));
    }

    printf("Escreva todos os elementos da sua matriz 1: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &matriz1[i][j]);
        }
    }

    printf("Escreva todos os elementos da sua matriz 2: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &matriz2[i][j]);
        }
    }
    printf("Soma:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%2.2lf ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }
    printf("Multiplicacao:\n");

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            double sum = 0.0;
            for (int k = 0; k < n; k++){
                sum += matriz1[i][k] * matriz2[k][j];
            }
            printf("%2.2lf ", sum);
        }
        printf("\n");
    }
    free(matriz1);
    free(matriz2);
    }
    return 0;
}