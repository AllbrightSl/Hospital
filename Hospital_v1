#include <stdio.h>
#include <stdlib.h>
#define MAX_PACIENTE 50
#define MAX_MEDICO 20
#define MAX_CONSULTA 100 // Eu só troquei os limites para ficar igual o do trabalho, mas deixar todos como 100 dá também

typedef struct MEDICO{
    char registro_m[MAX_MEDICO];
    char nome_medico[MAX_MEDICO];
    char especialidade[MAX_MEDICO];
}medico;

typedef struct PACIENTE{
    char registro_p[MAX_PACIENTE];
    char nome_paciente[MAX_PACIENTE];
    char identidade[MAX_PACIENTE];
    char endereco[MAX_PACIENTE];
    int telefone;
    char sexo[MAX_PACIENTE];
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
