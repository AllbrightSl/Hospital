#include <stdio.h>


int main(){
    int x;

    printf("Escreva a quantia de muros: ");
    scanf("%d", &x);

            for (int i = 1; i <= x; i++){
            for (int y = i; y < x; y++)
            printf(" ");
        for (int y = 1; y <= i; y++){
            printf("%c", '#');
        }
        printf("  ");

        for(int z = 1; z <= i; z++){
            printf("%c", '#');
        }
        printf("\n");
        }

    return 0;
}