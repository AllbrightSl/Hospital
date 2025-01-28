#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char carac, *seq;
    int cont = 0;
    printf("Escreva sua sequencia de caracteres:\n");
    seq = malloc(sizeof(char));
    if(seq == NULL){
    printf("Erro alocacao!\n");
    return -1;
    }
    while((carac = getchar()) != '\n')
    {
        seq = realloc(seq, (cont + 1) * sizeof(char));
        if (seq == NULL){
            printf("Erro de realocacao\n");
            return -1;
        }
        seq[cont] = carac;
        cont++;
    }
    char *vet;
    vet = malloc((cont + 1) * sizeof(char));
    if (vet == NULL){
        printf("Erro vet!\n");
        return -1;
    }
    int indice = 0;
    for (int i = 0; i < cont; i++){
        if(!isspace(seq[i]))
        {
            vet[indice] = seq[i];
            indice++;
        }
    }

    vet[indice] = '\0';
    puts(vet);
    free(seq);
    free(vet);

    return 0;
}