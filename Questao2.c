#include <stdio.h>
#include <time.h>
#include <stdlib.h>
    #define LINHA 5
    #define COLUNA 4
int main(){
    int matriz[LINHA][COLUNA], maior, menor;
    int v1[5], v2[5];
    srand(time(NULL));

    for (int i = 0; i < LINHA; i++){
        for (int j = 0; j < COLUNA; j++){
        matriz[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < LINHA; i++){
        for (int j = 0; j < COLUNA; j++){
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < COLUNA; j++){
        for (int i = 0; i < LINHA; i++){
            if (i == 0 && j == 0){
            v1[0] = matriz[i][j];
            v2[0] = matriz[i][j];
            }
            if (i == 0 && j == 1){
            v1[1] = matriz[i][j];
            v2[1] = matriz[i][j];
            }
            if (i == 0 && j == 2){
            v1[2] = matriz[i][j];
            v2[2] = matriz[i][j];
            }
            if (i == 0 && j == 3){
            v1[3] = matriz[i][j];
            v2[3] = matriz[i][j];
            }
            if (matriz[i][j] > v1[j]){
                v1[j] = matriz[i][j];
            }
            if (matriz[i][j] < v2[j]){
                v2[j] = matriz[i][j];
            }
        }
    }
    printf("Maiores de cada coluna:\n");
    for (int j = 0; j < COLUNA; j++){
        printf("%d ", v1[j]);
    }
    printf("\nMenores de cada coluna:\n");

    for (int j = 0; j < COLUNA; j++){
        printf("%d ", v2[j]);
    }
    printf("\n");
    return 0;
}