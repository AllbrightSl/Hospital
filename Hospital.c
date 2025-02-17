#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int dia;
    int mes;
    int ano;
}data;

typedef struct CONSULTA{
    int numero;
    medico m; //Aqui a gente precisa colocar o nome da variavel para poder acessar depois, tipo c1.m.nome_medico 
    paciente p;
    int horario;
    int duracao;
    data data;
}consulta;

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
        // Coloquei o primeiro switch case sendo a criação geral da consulta, mas acho que a professora errou ao colocar aquele exemplo de menu. Não tem o delete da consulta
        consultas[id].numero = id;
        printf("Escreva data para a sua consulta. Dia, Mês e Ano: ");
        scanf("%d %d %d", &consultas->data.dia, &consultas->data.mes, &consultas->data.ano );
        printf("\nEscreva o horario para sua consulta. às 3 horas, 6 horas ou 9 horas da manha?: ");
        scanf("%d", &consultas->horario);
        printf("\nEscreva a duração para sua consulta. 30 minutos, 60 minutos ou 120 minutos?: ");
        scanf("%d", &consultas->duracao);

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
        
        break;
        
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
