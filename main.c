#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 201
void ordena(int v[], int n){
    int i, j, chave;
    for (i = 1; i < n; i++){
        chave = v[i];
        j = i-1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}
int main(){
    int n;
    char str[MAX];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++){
        scanf("%[^\n]", str);
        getchar();
        str[strcspn(str, "\n")] = '\0';

    int tam = strlen(str), vet[tam], frequente = 0;
    
    for (int j = 0; j < tam; j++){
        str[j] = tolower(str[j]);
    }
    for (int j = 0; j < tam; j++){
        int cont = 1;
        for (int k = 0; k < tam; k++){
            if(str[j] == str[k])
            cont++;
            if (!isalpha(str[j]))
            cont = 0;
        }
        if(cont > frequente){
        frequente = cont;
        }
        vet[j] = cont;
    }

   int *ptr, andador_vet = 0;
   ptr = malloc(sizeof(int));
//frequency letters
   for (int j = 0; j < tam; j++){
    for (int l = 0; l <= andador_vet; l++){
            if (vet[j] == frequente && str[j] != ptr[l]){ // preciso apenas comparar os caracteres para reduzir a quantia de caracteres impressos
                ptr[andador_vet] = (int) str[j];
                ptr = realloc(ptr, sizeof(int) + 1);
                andador_vet++;
            }
        }
   }
   printf("%d", andador_vet);
   ordena(ptr, andador_vet);
   for (int j = 0; j < andador_vet; j++){
    printf("%c", ptr[j]);
   }
   printf("\n");
   free(ptr);
   }
    return 0;
}