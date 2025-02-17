#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_CONSULTA 100
#define MAX_PACIENTE 50
#define MAX_MEDICO 20
typedef struct medico{
    char registro_m[MAX]; //Aqui estou deixando com 100 porque é o tamanho máximo que as strings terão
    char nome_medico[MAX];
    char especialidade[MAX];
}MEDICO;

typedef struct paciente{
    char registro_p[MAX];
    char nome_paciente[MAX];
    char identidade[MAX];
    char endereco[MAX];
    char telefone[MAX];
    char sexo[MAX];
}PACIENTE;
typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;
typedef struct consulta{
    int numero;
    MEDICO medico;
    PACIENTE paciente;
    char horario[6];
    int duracao;
    DATA;
}CONSULTA;

    PACIENTE P[MAX_PACIENTE];
    MEDICO M[MAX_MEDICO];
    CONSULTA C[MAX_CONSULTA];

    void consulta(){
    /*Antes de já criar a consulta e colocar diretamente no nosso sistema, 
    quero ver se o horário da consulta com o medico já está sendo usado
    */    
    printf("Escreva o numero de identificacao da consulta:\n");
        scanf("");
        printf("Escreva o nome do medico desejado:\n");
        scanf("");
        printf("Escreva o nome completo do paciente:\n");
        scanf("");
        printf("Escreva o horario desejado (no formato HH:MM):\n");
        scanf("");
        printf("Escreva a duracao necessaria para sua consulta:\n");
        scanf("");
        printf("Escreva a data: DD/MM/AA\n");
        scanf(" %d/%d/%d", );
    }

int main(){
    while(1){
    int n;
    printf("----MENU----\n");
    printf("1 - Consulta\n");
    printf("2 - Paciente\n");
    printf("3 - Medico\n");
    printf("4 - Relatorios\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &n);

    

    switch (n){
        case 1:
        consulta();
        break;

        case 2:
        break;

        case 3:
        break;
        
        case 4:
        int escolha;
        printf("Voce deseja:\n");
        printf("1 - Ver a lista de consultas agendadas para um paciente\n");
        prinf("2 - Ver a lista de consultas agendadas para um medico\n");
        printf("3 - Ver a lista de pacientes para cada especialidade\n");
        scanf("%d", &escolha);
        
            switch (escolha){
                case 1:
                
            
                break;

                case 2:
                break;

                case 3:
                break;
        
                default:
                    printf("Escolha um numero valido\n");
                    break;
            } 
        case 5:
        printf("Saindo...\n");
        return 0;

        default:
        printf("Esse nao eh um numero valido.\n");
    }
    printf("\n");
    }
    return 0;
}
