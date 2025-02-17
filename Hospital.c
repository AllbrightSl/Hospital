#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
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
=======
#include <locale.h>

#define MAX_PACIENTE 50
#define MAX_MEDICO 20
#define MAX_CONSULTA 100 // Eu só troquei os limites para ficar igual o do trabalho, mas deixar todos como 100 dá também

typedef struct MEDICO{
    int registro_m;  // Eu posso ter me enganado aqui, mas essa parte não é pra ser tipo o id? Pra mim o registro e o numero da consulta seriam o mesmo
    char nome_medico[MAX_MEDICO];
    char especialidade[MAX_MEDICO];
}medico;

typedef struct PACIENTE{
    int registro_p;
    char nome_paciente[MAX_PACIENTE];
    char sexo[MAX_PACIENTE];
    char endereco[MAX_PACIENTE];
    int identidade;
    int telefone;
}paciente;
typedef struct DATA{
>>>>>>> 018d3e6d775aab3b20bd3ce2d6f93adfec430f10
    int dia;
    int mes;
    int ano;
}DATA;
typedef struct consulta{
    int numero;
<<<<<<< HEAD
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
=======
    medico m; //Aqui a gente precisa colocar o nome da variavel para poder acessar depois, tipo c1.m.nome_medico 
    paciente p;
    int horario;
    int duracao;
    data data;
}consulta;
>>>>>>> 018d3e6d775aab3b20bd3ce2d6f93adfec430f10

int main(){
    setlocale(LC_ALL, "Portuguese"); // Para aceitar acentos em português

    while(1){
    int n, id=0, escolha;
    consulta consultas[100];

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
<<<<<<< HEAD
        char hora[6];
        printf("Escreva o horario para sua consulta (formato HH:MM):\n");
        scanf(" %6[^\n]", &hora);
        if (buscar_consulta(hora)){
            printf("Horario da consulta ja marcado!\n");
            pritf("Favor marcar outro horario\n");
        }
        else{
            
        }

=======
        // Coloquei o primeiro switch case sendo a criação geral da consulta, mas acho que a professora errou ao colocar aquele exemplo de menu. Não tem o delete da consulta
        consultas[id].numero = id;
        printf("Escreva data para a sua consulta. Dia, Mês e Ano: ");
        scanf("%d %d %d", &consultas->data.dia, &consultas->data.mes, &consultas->data.ano );
        printf("\nEscreva o horario para sua consulta. às 3 horas, 6 horas ou 9 horas da manha?: ");
        scanf("%d", &consultas->horario);
        printf("\nEscreva a duração para sua consulta. 30 minutos, 60 minutos ou 120 minutos?: ");
        scanf("%d", &consultas->duracao);
>>>>>>> 018d3e6d775aab3b20bd3ce2d6f93adfec430f10

        printf("\n\nConsulta feito para o dia %d do mês %d, ano %d, às %d horas da manhã com duração de %d minutos\n\n",consultas[id].data.dia, consultas[id].data.mes, consultas[id].data.ano, consultas[id].horario, consultas[id].duracao);

        printf("\nAgora para a informação do paciente, forneça por favor o nome completo.");
        fgets(consultas[id].p.nome_paciente, MAX_PACIENTE, stdin);
        consultas->p.nome_paciente[strcspn(consultas->p.nome_paciente, "\n")] = 0;

        id++;
        break;

        case 2:
        break;

        case 3:
        break;
        
        case 4:
        // int escolha; Declarar essa variavel aqui tava bugando por algum motivo, coloquei ela lá pra cima.

        printf("Voce deseja:\n");
        printf("1 - Ver a lista de consultas agendadas para um paciente\n");
        printf("2 - Ver a lista de consultas agendadas para um medico\n");
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
