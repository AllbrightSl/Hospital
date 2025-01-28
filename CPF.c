#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char cpf[15];
    int vet[11];
    while (fgets(cpf, 15, stdin) != NULL){
        getchar();
        cpf[strcspn(cpf, "\n")] = '\0';

        int cont = 0;
        for (int i = 0; i < 14; i++){
            if ( isdigit(cpf[i])){
                vet[cont] = cpf[i] - '0';
                cont++;
            }
        }
    
        int soma1 = 0, soma2 = 0;
        
        for (int j = 0; j < 9; j++){
            soma1 += (vet[j]*(j+1));
            soma2 += (vet[j] * (9 - j));
        }
        
        int digito1 = soma1%11;
        int digito2 = soma2%11;

        if(digito1 == 10)
        digito1 = 0;
        
        if(digito2 == 10)
        digito2 = 0;

        if (digito1 == vet[9] && digito2 == vet[10])
        printf("CPF valido\n");
        else
        printf("CPF invalido\n");
    }
    return 0;
}
