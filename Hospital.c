#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_CONSULTA 100
#define MAX_PACIENTE 50
#define MAX_MEDICO 20
typedef struct medico{
    char registro_m[MAX];
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
    MEDICO;
    PACIENTE;
    int horario;
    int duracao;
    DATA;
}CONSULTA;

    PACIENTE P[MAX_PACIENTE];
    MEDICO M[MAX_MEDICO];
    CONSULTA C[MAX_CONSULTA];

int buscar_consulta(char string[]){
    for (int i = 0; i < 100; i++){
        if(strcmp(string, C[i].) == 0){
            return 1;
        }
    }
    return 0;
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
        char hora[6];
        printf("Escreva o horario para sua consulta (formato HH:MM):\n");
        scanf(" %6[^\n]", &hora);
        if (buscar_consulta(hora)){
            printf("Horario da consulta ja marcado!\n");
            pritf("Favor marcar outro horario\n");
        }
        else{
            
        }


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