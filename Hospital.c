#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct MEDICO{
    char registro_m[MAX];
    char nome_medico[MAX];
    char especialidade[MAX];
}medico;

typedef struct PACIENTE{
    char registro_p[MAX];
    char nome_paciente[MAX];
    char identidade[MAX];
    char endereco[MAX];
    char telefone[MAX];
    char sexo[MAX];
}paciente;
typedef struct DATA{
    int dia;
    int mes;
    int ano;
}data;

typedef struct CONSULTA{
    int numero;
    medico;
    paciente;
    int horario;
    int duracao;
    int data;
}consulta;

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
        printf("Escreva o horario para sua consulta:\n");
        fgets;

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