#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct MEDICO{
    char identificador[MAX];
    char nome[MAX];
    char especialidade[MAX];
}medico;

typedef struct PACIENTE{
    char identificador[MAX];
    char nome[MAX];
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
}

int main(){
    
    return 0;
}