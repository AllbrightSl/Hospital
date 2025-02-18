#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_CONSULTA 100
#define MAX_PACIENTE 50
#define MAX_MEDICO 20

typedef struct medico{
    int registro_m; //Esse registro aqui nao seriam numeros?
    char nome_medico[MAX];
    char especialidade[MAX];
}MEDICO;

typedef struct paciente{
    int registro_p;
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
int total_medicos=0;
int total_pacientes=0;

void consulta(){
    int num_verif, dia, mes, ano, duracao, verificador_m=0, verificador_p=0;
    char nome_m[MAX], nome_p[MAX], horario[6];

    /* *Problema* - Sera que a gente tem que verificar se a duracao de 
    uma consulta conflita com o horario de outro paciente?

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
        getchar();
    printf("Escreva o nome do medico desejado:\n");
        fgets(nome_m, sizeof(nome_m), stdin); // Usando fgets para caso o nome seja composto
        nome_m[strcspn(nome_m, "\n")] = '\0';

    printf("Escreva o nome completo do paciente:\n");
        fgets(nome_p, sizeof(nome_p), stdin);
        nome_p[strcspn(nome_p, "\n")] = '\0';

    //Loop para verificar se o horario do medico ja esta sendo usado
    for(int i=0; i< total_medicos; i++){
        if(strcmp(M[i].nome_medico, nome_m) == 0 ){
            verificador_m= 1;
        }
    }
    for(int i=0; i < total_pacientes; i++){
        if(strcmp(P[i].nome_paciente, nome_p) == 0 ) {
            verificador_p = 1;
        }
    }
    if(verificador_m == 0 || verificador_p ==0) {
        printf("\n\nNao foi possivel achar algum dos nomes mencionados, tente novamente\n");
        return;
    }
    for(int i=0; i< total_medicos; i++){
        if((strcmp(C[i].medico.nome_medico, nome_m) == 0 ) && strcmp(C[i].horario, horario)== 0 && (C[i].data.dia == dia) && (C[i].data.mes == mes) && (C[i].data.ano == ano)) {
                printf("\n\nO medico ja esta reservado nesse horario.\n");
                return;
        }
    }

    printf("Escreva o numero de identificacao da consulta:\n");
        scanf("%d", &num_verif);

    // Adicionando a consulta
    for(int i=0; i< total_medicos; i++){
        if(strcmp(M[i].nome_medico, nome_m) == 0) C[total_consultas].medico = M[i];
    }
    for(int i=0; i< total_pacientes; i++){
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


void alterarconsulta(){
    int i, num, escolha;
    char nome[MAX];

    printf("\n\nDigite o numero da consulta: ");
    scanf("%d", &num);


    printf("O que voce deseja alterar?\n1- Numero\n2- Medico\n3- Paciente\n4- Horario\n5- Duracao\n6- Data\n");
    printf("escolha: ");
    scanf("%d",&escolha);

    for (i = 0; i <= total_consultas; i++) {
        if (C[i].numero == num) {
            switch(escolha){
                case 1:
                printf("\n\nDigite o novo numero da consulta: ");
                scanf("%d",&C[i].numero);
                getchar();
                printf("Numero da consulta alterado com sucesso!\n");
                return;
                
                case 2:
                printf("\n\nDigite o nome do medico para qual voce deseja trocar: ");
                fgets(nome, MAX, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                

                for(int j=0;j<total_medicos;j++){
                    printf("nome:%s\n", nome);
                    printf("data:%s\n",M[j].nome_medico);
                    if(strcmp(nome, M[j].nome_medico)==0){
                        strcpy(C[i].medico.nome_medico, nome);
                        strcpy(C[i].medico.especialidade, M[j].especialidade);
                        C[i].medico.registro_m = M[j].registro_m; 
                        printf("Medico alterado com sucesso!\n");
                        return;      
                    }
                }
                printf("\nMedico nao encontrado!\n");
                return;

                case 3:  // Alterar paciente
                printf("\nDigite o nome do novo paciente: ");
                fgets(nome, MAX, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                for (int j = 0; j < total_pacientes; j++) {
                    if (strcmp(nome, P[j].nome_paciente) == 0) {
                        strcpy(C[i].paciente.nome_paciente, P[j].nome_paciente);
                        strcpy(C[i].paciente.telefone, P[j].telefone);
                        strcpy(C[i].paciente.endereco, P[j].endereco);
                        strcpy(C[i].paciente.sexo, P[j].sexo);
                        strcpy(C[i].paciente.identidade, P[j].identidade);
                        C[i].paciente.registro_p = P[j].registro_p;
                        printf("Paciente alterado com sucesso!\n");
                        return;
                    }
                }
                printf("\nPaciente nao encontrado!\n");
                return;

                case 4:  // Alterar horário
                printf("\nDigite o novo horario (HH:MM): ");
                scanf("%s", C[i].horario);
                printf("Horario alterado com sucesso!\n");
                return;

                case 5:  // Alterar duração
                printf("\nDigite a nova duracao (minutos): ");
                scanf("%d", &C[i].duracao);
                printf("Duracao alterada com sucesso!\n");
                return;

                case 6:  // Alterar data
                printf("\nDigite a nova data (DD/MM/AA): ");
                scanf("%d/%d/%d", &C[i].data.dia, &C[i].data.mes, &C[i].data.ano);
                printf("Data alterada com sucesso!\n");
                return;

                default:
                printf("Opcao invalida!\n");
                return;

            }
        }
        printf("\nNumero da consulta nao encontrado!\n");
        return;
    }
}

void excluirconsulta() {
    int i, num, encontrada = 0;

    printf("\nDigite o numero da consulta que deseja excluir: ");
    scanf("%d", &num);

    for (i = 0; i <= total_consultas; i++) {
        if (C[i].numero == num) {
            encontrada = 1;
            printf("\nConsulta %d excluida com sucesso!\n", num);

            C[i] = C[total_consultas - 1];

            total_consultas--;
            return;
        }
    }

    if (!encontrada) {
        printf("\nConsulta nao encontrada!\n");
    }
}


void mostrarconsulta() {
    for(int i=0; i< total_consultas; i++){
        if (C[i].numero != 0) {
        printf("\nConsulta n%d do paciente %s, com o medico %s, no dia %d, mes %d, ano %d, as %s com duracao de %d minutos\n\n",C[i].numero,
                                                                                                                            C[i].paciente.nome_paciente,
                                                                                                                            C[i].medico.nome_medico,
                                                                                                                            C[i].data.dia,
                                                                                                                            C[i].data.mes,
                                                                                                                            C[i].data.ano,
                                                                                                                            C[i].horario,
                                                                                                                            C[i].duracao);
        }                                                                                                                    
    }   
}

//Funcao para gerenciar tanto medicos (1) tanto pacientes (2)
void gerenciar(int tipo, int opcao) {
    int i, registro, registro_in, escolha;
    char nome[MAX];
    getchar();

    switch (opcao) {
        case 1: // Cadastrar
            if ((tipo == 1 && total_medicos >= MAX_MEDICO) ||
                (tipo == 2 && total_pacientes >= MAX_PACIENTE)) {
                printf("Limite atingido!\n");
                return;
            }

            printf("\nDigite o nome: ");
            fgets(nome, MAX, stdin);
            nome[strcspn(nome, "\n")] = '\0'; 
            printf("Digite o registro: ");
            scanf("%d", &registro);
            getchar();

            for(int i=0; i<= MAX_PACIENTE; i++){
                if((tipo == 1 && M[i].registro_m == registro) ||
                (tipo == 2 && P[i].registro_p == registro)){
                    printf("\nEsse registro ja existe!\n\n");
                    return;
                }
            }

            if (tipo == 1) { // Médico
                M[total_medicos].registro_m = registro;
                strcpy(M[total_medicos].nome_medico, nome);
                printf("Digite a especialidade: ");
                fgets(M[total_medicos].especialidade, MAX, stdin);
                M[total_medicos].especialidade[strcspn(M[total_medicos].especialidade, "\n")] = '\0';
                total_medicos++;

            } else { // Paciente
                P[total_pacientes].registro_p = registro;
                strcpy(P[total_pacientes].nome_paciente, nome);
                printf("Digite a identidade do paciente: ");
                fgets(P[total_pacientes].identidade,MAX,stdin);
                P[total_pacientes].identidade[strcspn(P[total_pacientes].identidade, "\n")] = '\0';
                printf("Digite o Endereco completo: ");
                fgets(P[total_pacientes].endereco, MAX, stdin);
                P[total_pacientes].endereco[strcspn(P[total_pacientes].endereco, "\n")] = '\0';
                printf("Digite o telefone: ");
                fgets(P[total_pacientes].telefone, MAX, stdin);
                P[total_pacientes].telefone[strcspn(P[total_pacientes].telefone, "\n")] = '\0';
                printf("Digite o sexo: ");
                fgets(P[total_pacientes].sexo, MAX, stdin);
                P[total_pacientes].sexo[strcspn(P[total_pacientes].sexo, "\n")] = '\0';
                total_pacientes++;
            }
            printf("\nCadastro realizado!\n");
            break;

        case 2: // Alterar
            printf("\n\nDigite o id da pessoa para se alterar: ");
            scanf("%d", &registro);

            printf("\nO que deseja se alterar dessa pessoa?\n");
            printf("1 - Nome\n");
            printf("2 - identificador\n");
            if(tipo ==2){
                printf("3 - Identidade\n");
                printf("4 - Endereco\n");
                printf("5 - Telefone\n");
                printf("6 - Sexo\n");
            }
            else printf("3 - Especialidade\n");
            printf("escolha: ");

            scanf("%d", &escolha);
            getchar();

            switch(escolha){
                case 1: // trocando o nome
                for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                    if ((tipo == 1 && M[i].registro_m == registro) ||
                        (tipo == 2 && P[i].registro_p == registro )) {
                        printf("\nDigite o novo nome:");
                        fgets(nome, MAX, stdin);
                        nome[strcspn(nome, "\n")] = '\0';
    
                        if (tipo == 1) strcpy(M[i].nome_medico, nome);
                        else strcpy(P[i].nome_paciente, nome);
                        printf("Alteracao feita!\n");
                        return;
                    }
                } break;

                case 2: // trocando o identificador
                for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                    if ((tipo == 1 && M[i].registro_m == registro) ||
                        (tipo == 2 && P[i].registro_p == registro )) {
                        printf("Digite o novo id:");
                        scanf("%d", &registro_in);
                        getchar();
    
                        if (tipo == 1) M[i].registro_m = registro_in;
                        else P[i].registro_p = registro_in;
                        printf("Alteracao feita!\n");
                        return;
                    }
                } break;

                case 3: // trocando especialdade ou identidade
                for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                    if ((tipo == 1 && M[i].registro_m == registro) ||
                        (tipo == 2 && P[i].registro_p == registro )) {
                        
                        if (tipo == 1){
                            printf("Digite a nova especialidade: ");
                            fgets(M[i].especialidade, MAX, stdin);
                            M[i].especialidade[strcspn(M[i].especialidade, "\n")] = '\0';
                        }
                        else{
                            printf("Digite a nova identidade: ");
                            fgets(P[i].identidade, MAX, stdin);
                            P[i].identidade[strcspn(P[i].identidade, "\n")] = '\0';
                        }
                        printf("Alteracao feita!\n");
                        return;
                    }
                } break;

                case 4: 
                for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                    if ((tipo == 1 && M[i].registro_m == registro) ||
                        (tipo == 2 && P[i].registro_p == registro )) {
                        if (tipo == 1) {
                            printf("Nao temos essa opcao para medicos");
                            return;
                        }
                        else {
                            printf("Digite o novo endereco: ");
                            fgets(P[i].endereco, MAX, stdin);
                            P[i].endereco[strcspn(P[i].endereco, "\n")] = '\0';
                        }
                        printf("Alteracao feita!\n");
                        return;
                    }
                } break;

                case 5: 
                for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                    if ((tipo == 1 && M[i].registro_m == registro) ||
                        (tipo == 2 && P[i].registro_p == registro )) {
                        if (tipo == 1) {
                            printf("Nao temos essa opcao para medicos");
                            return;
                        }
                        else {
                            printf("Digite o novo telefone: ");
                            fgets(P[i].telefone, MAX, stdin);
                            P[i].telefone[strcspn(P[i].telefone, "\n")] = '\0';
                        }
                        printf("Alteracao feita!\n");
                        return;
                    }
                } break;

                case 6:
                for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                    if ((tipo == 1 && M[i].registro_m == registro) ||
                        (tipo == 2 && P[i].registro_p == registro )) {
                        if (tipo == 1) {
                            printf("Nao temos essa opcao para medicos");
                            return;
                        }
                        else {
                            printf("Digite o novo sexo: ");
                            fgets(P[i].sexo, MAX, stdin);
                            P[i].sexo[strcspn(P[i].sexo, "\n")] = '\0';
                        }
                        printf("Alteracao feita!\n");
                        return;
                    }
                } break;
                
            }
            printf("Registro nao encontrado!\n");
            break;

        case 3: // Excluir
            printf("\n\nDigite o id da pessoa para se excluir: ");
            scanf("%d", &registro);
            getchar();

            for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                if ((tipo == 1 && M[i].registro_m == registro) ||
                    (tipo == 2 && P[i].registro_p == registro )) {
                    printf("Excluindo...\n");

                    if (tipo == 1) {
                        M[i] = M[total_medicos - 1]; // Substituir pelo último
                        total_medicos--;
                    } else {
                        P[i] = P[total_pacientes - 1]; // Substituir pelo último
                        total_pacientes--;
                    }
                    printf("Excluído com sucesso!\n");
                    return;
                }
            }
            printf("Registro não encontrado!\n");
            break;

        case 4: // Listar
            printf("\nLista de %s:\n", tipo == 1 ? "Medicos" : "Pacientes");
            for (i = 0; i < (tipo == 1 ? total_medicos : total_pacientes); i++) {
                if (tipo == 1)
                    printf("ID: %d | Nome: %s | Especialidade: %s\n", M[i].registro_m, M[i].nome_medico, M[i].especialidade);
                else
                    printf("ID: %d | Nome: %s | Indentidade: %s | Endereco: %s | Telefone: %s | Sexo: %s \n", P[i].registro_p, P[i].nome_paciente, P[i].identidade, P[i].endereco, P[i].telefone, P[i].sexo);
            }
            break;

        default:
            printf("Opção inválida!\n");
    }
}

void menuconsulta(){
    int escolha;

    printf("\n\nVoce deseja:\n");
    printf("1 - Criar uma consulta\n");
    printf("2 - Alterar uma consulta\n");
    printf("3 - Excluir uma consulta\n");
    printf("4 - Pesquisar sobre uma consulta\n");
    printf("5 - Retornar ao menu\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha){
        case 1:consulta() ;break;

        case 2: alterarconsulta(); break;

        case 3: excluirconsulta(); break;

        case 4: mostrarconsulta(); break;

        case 5:
        printf("Voltando...\n");
        break;

        default:
        printf("Esse nao eh um numero valido.\n");
    }
}

void menupaciente(){
    int escolha;

    printf("\n\nVoce deseja:\n");
    printf("1 - Cadastrar um paciente\n");
    printf("2 - Alterar dados de um paciente\n");
    printf("3 - Excluir um paciente\n");
    printf("4 - Pesquisar sobre um paciente\n");
    printf("5 - Retornar ao menu\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha){
        case 1:gerenciar(2, 1); break;

        case 2:gerenciar(2, 2); break;

        case 3:gerenciar(2, 3); break;

        case 4:gerenciar(2, 4); break;

        case 5:
        printf("Voltando...\n");
        break;

        default:
        printf("Esse nao eh um numero valido.\n");
    }
}

void menumedico(){
    int escolha;

    printf("\n\nVoce deseja:\n");
        printf("1 - Cadastrar um medico\n");
        printf("2 - Alterar dados de um medico\n");
        printf("3 - Excluir um medico\n");
        printf("4 - Pesquisar sobre um medico\n");
        printf("5 - Retornar ao menu\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:gerenciar(1, 1); break;

            case 2:gerenciar(1, 2); break;
    
            case 3:gerenciar(1, 3); break;
    
            case 4:gerenciar(1, 4); break;

            case 5:
            printf("Voltando...\n");
            break;

            default:
            printf("Esse nao eh um numero valido.\n");
        }
}

void menurelatorio() {
    int escolha;
    char nome[MAX];
    
    printf("\n\nVoce deseja:\n");
    printf("1 - Ver a lista de consultas agendadas para um paciente\n");
    printf("2 - Ver a lista de consultas agendadas para um medico\n");
    printf("3 - Ver a lista de pacientes para cada especialidade\n");
    printf("4 - Retornar ao menu\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    getchar(); // Limpar buffer

    switch (escolha) {
        case 1: // Relatório de consultas por paciente
            printf("\nDigite o nome do paciente: ");
            fgets(nome, MAX, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("\nConsultas do paciente %s:\n", nome);
            int encontrou = 0;
            for (int i = 0; i < total_consultas; i++) {
                if (strcmp(C[i].paciente.nome_paciente, nome) == 0) {
                    printf("Consulta n%d com o medico %s, no dia %d/%d/%d, as %s, duracao: %d minutos\n",
                           C[i].numero, C[i].medico.nome_medico, C[i].data.dia, C[i].data.mes, 
                           C[i].data.ano, C[i].horario, C[i].duracao);
                    encontrou = 1;
                }
            }
            if (!encontrou) printf("Nenhuma consulta encontrada para esse paciente.\n");
            break;

        case 2: // Relatório de consultas por médico
            printf("\nDigite o nome do medico: ");
            fgets(nome, MAX, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("\nConsultas do medico %s:\n", nome);
            encontrou = 0;
            for (int i = 0; i < total_consultas; i++) {
                if (strcmp(C[i].medico.nome_medico, nome) == 0) {
                    printf("Consulta n%d do paciente %s, no dia %d/%d/%d, as %s, duracao: %d minutos\n",
                           C[i].numero, C[i].paciente.nome_paciente, C[i].data.dia, C[i].data.mes, 
                           C[i].data.ano, C[i].horario, C[i].duracao);
                    encontrou = 1;
                }
            }
            if (!encontrou) printf("Nenhuma consulta encontrada para esse medico.\n");
            break;

        case 3: // Relatório de pacientes por especialidade médica
            printf("\nDigite a especialidade: ");
            fgets(nome, MAX, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("\nPacientes atendidos por medicos da especialidade %s:\n", nome);
            encontrou = 0;
            for (int i = 0; i < total_consultas; i++) {
                if (strcmp(C[i].medico.especialidade, nome) == 0) {
                    printf("- %s\n", C[i].paciente.nome_paciente);
                    encontrou = 1;
                }
            }
            if (!encontrou) printf("Nenhum paciente encontrado para essa especialidade.\n");
            break;

        case 4:
            printf("Voltando...\n");
            break;
        
        default:
            printf("Escolha um numero valido\n");
            break;
    }
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
        case 1: menuconsulta(); break;

        case 2: menupaciente(); break;

        case 3: menumedico(); break;
        
        case 4: menurelatorio(); break;
        
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
