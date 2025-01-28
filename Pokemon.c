#include <stdio.h>
#include <string.h>
    void repetido(char str[][1000], int *p, int i){
        for (int j = 0; j < i; j++){
            if(strcmp(str[i], str[j]) == 0){
                *p = 0;
                break;
            }
        }
    }
    int main(){
    int N, contador = 151;
    scanf("%d", &N);
    
    char str[N][1000];

    for (int i = 0; i < N; i++){
        scanf("%s", str[i]);

        if (i > 0){
        int unico = 1;
                repetido(str, &unico, i);
                if (unico)
                contador--;
        }
        else
        contador--;
    }
    printf("Falta(m) %d pomekon(s).\n", contador);
    return 0;
}