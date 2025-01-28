#include <stdio.h>
#include <string.h>
/*o arthur é lindo 
lindo arthur é o*/
int main(){
    char receber[100], inicio[100], meio[100], fim[100], *ptr = receber;
    int posI = 0, posF, pos = 0;
    fgets(receber, sizeof(receber), stdin);
    receber[strcspn(receber, "\n")] = '\0';

    int tam = strlen(receber);

    for (int i = 0; receber[i] != ' ' && receber[i] != '\0'; i++){
        posI = i;
        inicio[i] = receber[i];
    }
    inicio[posI+1] = '\0';
    
    for (int j = tam-1; receber[j] != ' ' && j>=0; j--){
        posF = j;
    }
    strcpy(fim, &receber[posF]);

    for (int k = posI+2; k < posF; k++){
        meio[pos++] = receber[k];
    }
    meio[pos] = '\0';
    
    printf("%s %s %s\n", fim, meio, inicio);
    return 0;
}