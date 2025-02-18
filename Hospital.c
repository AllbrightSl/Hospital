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
    MEDICO medico;
    PACIENTE paciente;
    char horario[6];
    int duracao;
    DATA data;
}CONSULTA;

    PACIENTE P[MAX_PACIENTE];
    MEDICO M[MAX_MEDICO];
    CONSULTA C[MAX_CONSULTA];
    int total_consultas=0;

    void medico(){
        int registro;




    }





    void consulta(){
    int num_verif, dia, mes, ano, duracao;
    char nome_m[MAX], nome_p[MAX], horario[6];

    /* *Problema* - Sera que a gente tem que verificar se a duracao de 
    uma colsulta conflita com o horario de outro paciente?

    Tipo, com o mesmo medico,
    paciente1 as 14:00 com 60 minutos
    paciente2 as 13:30 com 60 minutos.
    Eles conflitam um com o outro na duracao mas o horario e diferente.

    Se for o caso talvez seria melhor pegar o horario como int, pra poder
    fazer operacoes com ele e verificar isso
    */

    // mudei a posicao para facilitar o uso de caso de testes e deixar o codigo mais logico
    printf("Escreva a data que deseja marcar a consulta: DD/MM/AA\n");
        scanf(" %d/%d/%d", &dia, &mes, &ano);
    printf("Escreva o horario desejado (no formato HH:MM):\n");
        scanf("%s", horario);
    printf("Escreva a duracao necessaria para sua consulta em minutos:\n");
        scanf("%d", &duracao);
    printf("Escreva o nome do medico desejado:\n");
        getchar();
        fgets(nome_m, sizeof(nome_m), stdin); // Usando fgets para caso o nome seja composto
        nome_m[strcspn(nome_m, "\n")] = '\0';

    //Loop para verificar se o horario do medico ja esta sendo usado
    for(int i=0; i<=total_consultas; i++){
        if(strcmp(C[i].medico.nome_medico, nome_m) == 0 && strcmp(C[i].horario, horario)== 0 && (C[i].data.dia == dia) && (C[i].data.mes == mes) && (C[i].data.ano) == ano){
            printf("\n\nO medico ja esta reservado nesse horario.\n");
            return;
        }// Falta verificar se a duracao da consulta antes desse horario conflita 
    }
    printf("Escreva o nome completo do paciente:\n");
        fgets(nome_p, sizeof(nome_p), stdin);
        nome_p[strcspn(nome_p, "\n")] = '\0';

    printf("Escreva o numero de identificacao da consulta:\n");
        scanf("%d", &num_verif);

    // Adicionando a consulta
    for(int i=0; i<= MAX_PACIENTE; i++){
        if(strcmp(M[i].nome_medico, nome_m) == 0) C[total_consultas].medico = M[i];
        if(strcmp(P[i].nome_paciente, nome_p) == 0) C[total_consultas].paciente = P[i];
    }
    C[total_consultas].numero = num_verif;
    C[total_consultas].data.dia = dia;
    C[total_consultas].data.mes = mes;
    C[total_consultas].data.ano = ano;
    C[total_consultas].duracao = duracao;
    strcpy(C[total_consultas].horario, horario);
    total_consultas++; 

    printf("\nConsulta criada para o dia %d do mes %d, ano %d, as %s com duracao de %d minutos\n\n", dia, mes, ano, horario, duracao);
   
    }

int main(){
    while(1){
    int n, escolha_c, escolha_p, escolha_m, escolha_r;
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
        printf("\n\nVoce deseja:\n");
        printf("1 - Criar uma consulta\n");
        printf("2 - Alterar uma consulta\n");
        printf("3 - Excluir uma consulta\n");
        printf("4 - Pesquisar sobre uma consulta\n");
        printf("5 - Retornar ao menu\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha_c);

        switch (escolha_c){
            case 1:
            consulta();
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            printf("Voltando...\n");
            break;

            default:
            printf("Esse nao eh um numero valido.\n");
        }
        break;

        case 2:
        printf("\n\nVoce deseja:\n");
        printf("1 - Cadastrar um paciente\n");
        printf("2 - Alterar dados de um paciente\n");
        printf("3 - Excluir um paciente\n");
        printf("4 - Pesquisar sobre um paciente\n");
        printf("5 - Retornar ao menu\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha_p);

        switch (escolha_p){
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            printf("Voltando...\n");
            break;

            default:
            printf("Esse nao eh um numero valido.\n");
        }
        break;

        case 3:
        printf("\n\nVoce deseja:\n");
        printf("1 - Cadastrar um medico\n");
        printf("2 - Alterar dados de um medico\n");
        printf("3 - Excluir um medico\n");
        printf("4 - Pesquisar sobre um medico\n");
        printf("5 - Retornar ao menu\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha_m);

        switch (escolha_m){
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            printf("Voltando...\n");
            break;

            default:
            printf("Esse nao eh um numero valido.\n");
        }
        break;
        
        case 4:
        //int escolha;// Aqui no vscode esse int t� dando erro, pra voc� tamb�m?
        printf("\n\nVoce deseja:\n");
        printf("1 - Ver a lista de consultas agendadas para um paciente\n");
        printf("2 - Ver a lista de consultas agendadas para um medico\n");
        printf("3 - Ver a lista de pacientes para cada especialidade\n");
        printf("4- Retornar ao menu\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha_r);
        
        switch (escolha_r){
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            printf("Voltando...\n");
            break;
        
            default:
            printf("Escolha um numero valido\n");
            break;
        } 
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
