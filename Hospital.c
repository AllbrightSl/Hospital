#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEDICOS 20
#define MAX_PACIENTES 50
#define MAX_CONSULTAS 100

typedef struct {
    int id;
    char nome[50];
    char especialidade[50];
} Medico;

typedef struct {
    int id;
    char nome[50];
    char identidade[20];
    char endereco[100];
    char telefone[20];
    char sexo;
} Paciente;

typedef struct {
    int numero;
    int idMedico;
    int idPaciente;
    char horario[10];
    int duracao;
    char data[11];
} Consulta;

void limparInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if(fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len-1] == '\n')
            buffer[len-1] = '\0';
    }
}

int buscarPacientePorId(Paciente pacientes[], int numPacientes, int id) {
    for (int i = 0; i < numPacientes; i++) {
        if (pacientes[i].id == id)
            return i;
    }
    return -1;
}

int buscarMedicoPorId(Medico medicos[], int numMedicos, int id) {
    for (int i = 0; i < numMedicos; i++) {
        if (medicos[i].id == id)
            return i;
    }
    return -1;
}

int buscarConsultaPorNumero(Consulta consultas[], int numConsultas, int numero) {
    for (int i = 0; i < numConsultas; i++) {
        if (consultas[i].numero == numero)
            return i;
    }
    return -1;
}

void incluirConsulta(Consulta consultas[], int *numConsultas, Paciente pacientes[], int numPacientes, Medico medicos[], int numMedicos) {
    if (*numConsultas >= MAX_CONSULTAS) {
        printf("Limite de consultas atingido.\n");
        return;
    }
    Consulta c;
    printf("\n--- Inclusao de Consulta ---\n");
    printf("Digite o numero da consulta: ");
    scanf("%d", &c.numero);
    limparInputBuffer();

    if (buscarConsultaPorNumero(consultas, *numConsultas, c.numero) != -1) {
        printf("Consulta com este numero ja existe.\n");
        return;
    }
    printf("Digite o identificador do medico: ");
    scanf("%d", &c.idMedico);
    limparInputBuffer();
    if (buscarMedicoPorId(medicos, numMedicos, c.idMedico) == -1) {
        printf("Medico nao encontrado.\n");
        return;
    }
    printf("Digite o identificador do paciente: ");
    scanf("%d", &c.idPaciente);
    limparInputBuffer();
    if (buscarPacientePorId(pacientes, numPacientes, c.idPaciente) == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    lerString("Digite o horario (HH:MM): ", c.horario, 10);
    printf("Digite a duracao da consulta (em minutos): ");
    scanf("%d", &c.duracao);
    limparInputBuffer();
    lerString("Digite a data (DD/MM/AAAA): ", c.data, 11);

    consultas[*numConsultas] = c;
    (*numConsultas)++;
    printf("Consulta incluida com sucesso.\n");
}

void alterarConsulta(Consulta consultas[], int numConsultas, Paciente pacientes[], int numPacientes, Medico medicos[], int numMedicos) {
    int numero;
    printf("\n--- Alteracao de Consulta ---\n");
    printf("Digite o numero da consulta a ser alterada: ");
    scanf("%d", &numero);
    limparInputBuffer();
    int pos = buscarConsultaPorNumero(consultas, numConsultas, numero);
    if (pos == -1) {
        printf("Consulta nao encontrada.\n");
        return;
    }
    Consulta *c = &consultas[pos];
    printf("Consulta atual:\n");
    printf("Numero: %d\n", c->numero);
    printf("Medico: %d\n", c->idMedico);
    printf("Paciente: %d\n", c->idPaciente);
    printf("Horario: %s\n", c->horario);
    printf("Duracao: %d\n", c->duracao);
    printf("Data: %s\n", c->data);

    printf("\nDigite o novo identificador do medico: ");
    scanf("%d", &c->idMedico);
    limparInputBuffer();
    if (buscarMedicoPorId(medicos, numMedicos, c->idMedico) == -1) {
        printf("Medico nao encontrado. Alteracao cancelada.\n");
        return;
    }
    printf("Digite o novo identificador do paciente: ");
    scanf("%d", &c->idPaciente);
    limparInputBuffer();
    if (buscarPacientePorId(pacientes, numPacientes, c->idPaciente) == -1) {
        printf("Paciente nao encontrado. Alteracao cancelada.\n");
        return;
    }
    lerString("Digite o novo horario (HH:MM): ", c->horario, 10);
    printf("Digite a nova duracao (em minutos): ");
    scanf("%d", &c->duracao);
    limparInputBuffer();
    lerString("Digite a nova data (DD/MM/AAAA): ", c->data, 11);

    printf("Consulta alterada com sucesso.\n");
}

void excluirConsulta(Consulta consultas[], int *numConsultas) {
    int numero;
    printf("\n--- Exclusao de Consulta ---\n");
    printf("Digite o numero da consulta a ser excluida: ");
    scanf("%d", &numero);
    limparInputBuffer();
    int pos = buscarConsultaPorNumero(consultas, *numConsultas, numero);
    if (pos == -1) {
        printf("Consulta nao encontrada.\n");
        return;
    }
    Consulta c = consultas[pos];
    printf("\nConsulta excluida:\n");
    printf("Numero: %d\n", c.numero);
    printf("Medico: %d\n", c.idMedico);
    printf("Paciente: %d\n", c.idPaciente);
    printf("Horario: %s\n", c.horario);
    printf("Duracao: %d\n", c.duracao);
    printf("Data: %s\n", c.data);

    for (int i = pos; i < (*numConsultas) - 1; i++) {
        consultas[i] = consultas[i + 1];
    }
    (*numConsultas)--;
    printf("Consulta removida com sucesso.\n");
}

void pesquisarConsulta(Consulta consultas[], int numConsultas, Paciente pacientes[], int numPacientes, Medico medicos[], int numMedicos) {
    int numero;
    printf("\n--- Pesquisa de Consulta ---\n");
    printf("Digite o numero da consulta: ");
    scanf("%d", &numero);
    limparInputBuffer();
    int pos = buscarConsultaPorNumero(consultas, numConsultas, numero);
    if (pos == -1) {
        printf("Consulta nao encontrada.\n");
        return;
    }
    Consulta c = consultas[pos];
    printf("\nConsulta encontrada:\n");
    printf("Numero: %d\n", c.numero);
    printf("Medico: %d", c.idMedico);
    int posMedico = buscarMedicoPorId(medicos, numMedicos, c.idMedico);
    if (posMedico != -1)
        printf(" - Nome: %s\n", medicos[posMedico].nome);
    else
        printf("\n");
    printf("Paciente: %d", c.idPaciente);
    int posPaciente = buscarPacientePorId(pacientes, numPacientes, c.idPaciente);
    if (posPaciente != -1)
        printf(" - Nome: %s\n", pacientes[posPaciente].nome);
    else
        printf("\n");
    printf("Horario: %s\n", c.horario);
    printf("Duracao: %d\n", c.duracao);
    printf("Data: %s\n", c.data);
}

void listarConsultas(Consulta consultas[], int numConsultas) {
    if (numConsultas == 0) {
        printf("Nenhuma consulta cadastrada.\n");
    } else {
        printf("\nLista de Consultas:\n");
        for (int i = 0; i < numConsultas; i++) {
            printf("Numero: %d, Medico: %d, Paciente: %d, Horario: %s, Duracao: %d, Data: %s\n",
                   consultas[i].numero, consultas[i].idMedico, consultas[i].idPaciente,
                   consultas[i].horario, consultas[i].duracao, consultas[i].data);
        }
    }
}

void incluirPaciente(Paciente pacientes[], int *numPacientes) {
    if (*numPacientes >= MAX_PACIENTES) {
        printf("Limite de pacientes atingido.\n");
        return;
    }
    Paciente p;
    printf("\n--- Inclusao de Paciente ---\n");
    printf("Digite o identificador do paciente: ");
    scanf("%d", &p.id);
    limparInputBuffer();
    if (buscarPacientePorId(pacientes, *numPacientes, p.id) != -1) {
        printf("Paciente com este identificador ja existe.\n");
        return;
    }
    lerString("Digite o nome do paciente: ", p.nome, 50);
    lerString("Digite a identidade: ", p.identidade, 20);
    lerString("Digite o endereco: ", p.endereco, 100);
    lerString("Digite o telefone: ", p.telefone, 20);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &p.sexo);
    limparInputBuffer();
    pacientes[*numPacientes] = p;
    (*numPacientes)++;
    printf("Paciente incluido com sucesso.\n");
}

void alterarPaciente(Paciente pacientes[], int numPacientes) {
    int id;
    printf("\n--- Alteracao de Paciente ---\n");
    printf("Digite o identificador do paciente a ser alterado: ");
    scanf("%d", &id);
    limparInputBuffer();
    int pos = buscarPacientePorId(pacientes, numPacientes, id);
    if (pos == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    Paciente *p = &pacientes[pos];
    printf("\nDados atuais do paciente:\n");
    printf("ID: %d\n", p->id);
    printf("Nome: %s\n", p->nome);
    printf("Identidade: %s\n", p->identidade);
    printf("Endereco: %s\n", p->endereco);
    printf("Telefone: %s\n", p->telefone);
    printf("Sexo: %c\n", p->sexo);

    lerString("Digite o novo nome: ", p->nome, 50);
    lerString("Digite a nova identidade: ", p->identidade, 20);
    lerString("Digite o novo endereco: ", p->endereco, 100);
    lerString("Digite o novo telefone: ", p->telefone, 20);
    printf("Digite o novo sexo (M/F): ");
    scanf(" %c", &p->sexo);
    limparInputBuffer();
    printf("Paciente alterado com sucesso.\n");
}

void excluirPaciente(Paciente pacientes[], int *numPacientes, Consulta consultas[], int *numConsultas) {
    int id;
    printf("\n--- Exclusao de Paciente ---\n");
    printf("Digite o identificador do paciente a ser excluido: ");
    scanf("%d", &id);
    limparInputBuffer();
    int pos = buscarPacientePorId(pacientes, *numPacientes, id);
    if (pos == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    Paciente p = pacientes[pos];
    printf("\nPaciente excluido:\n");
    printf("ID: %d\n", p.id);
    printf("Nome: %s\n", p.nome);
    printf("Identidade: %s\n", p.identidade);
    printf("Endereco: %s\n", p.endereco);
    printf("Telefone: %s\n", p.telefone);
    printf("Sexo: %c\n", p.sexo);

    for (int i = pos; i < (*numPacientes) - 1; i++) {
        pacientes[i] = pacientes[i + 1];
    }
    (*numPacientes)--;
    int i = 0;
    while (i < *numConsultas) {
        if (consultas[i].idPaciente == id) {
            printf("Excluindo consulta com numero %d associada ao paciente.\n", consultas[i].numero);
            for (int j = i; j < (*numConsultas) - 1; j++) {
                consultas[j] = consultas[j + 1];
            }
            (*numConsultas)--;
        } else {
            i++;
        }
    }
    printf("Paciente e consultas associadas excluidos com sucesso.\n");
}

void pesquisarPaciente(Paciente pacientes[], int numPacientes) {
    int id;
    printf("\n--- Pesquisa de Paciente ---\n");
    printf("Digite o identificador do paciente: ");
    scanf("%d", &id);
    limparInputBuffer();
    int pos = buscarPacientePorId(pacientes, numPacientes, id);
    if (pos == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }
    Paciente p = pacientes[pos];
    printf("\nPaciente encontrado:\n");
    printf("ID: %d\n", p.id);
    printf("Nome: %s\n", p.nome);
    printf("Identidade: %s\n", p.identidade);
    printf("Endereco: %s\n", p.endereco);
    printf("Telefone: %s\n", p.telefone);
    printf("Sexo: %c\n", p.sexo);
}

void incluirMedico(Medico medicos[], int *numMedicos) {
    if (*numMedicos >= MAX_MEDICOS) {
        printf("Limite de medicos atingido.\n");
        return;
    }
    Medico m;
    printf("\n--- Inclusao de Medico ---\n");
    printf("Digite o identificador do medico: ");
    scanf("%d", &m.id);
    limparInputBuffer();
    if (buscarMedicoPorId(medicos, *numMedicos, m.id) != -1) {
        printf("Medico com este identificador ja existe.\n");
        return;
    }
    lerString("Digite o nome do medico: ", m.nome, 50);
    lerString("Digite a especialidade: ", m.especialidade, 50);

    medicos[*numMedicos] = m;
    (*numMedicos)++;
    printf("Medico incluido com sucesso.\n");
}

void alterarMedico(Medico medicos[], int numMedicos) {
    int id;
    printf("\n--- Alteracao de Medico ---\n");
    printf("Digite o identificador do medico a ser alterado: ");
    scanf("%d", &id);
    limparInputBuffer();
    int pos = buscarMedicoPorId(medicos, numMedicos, id);
    if (pos == -1) {
        printf("Medico nao encontrado.\n");
        return;
    }
    Medico *m = &medicos[pos];
    printf("\nDados atuais do medico:\n");
    printf("ID: %d\n", m->id);
    printf("Nome: %s\n", m->nome);
    printf("Especialidade: %s\n", m->especialidade);
    lerString("Digite o novo nome: ", m->nome, 50);
    lerString("Digite a nova especialidade: ", m->especialidade, 50);
    printf("Medico alterado com sucesso.\n");
}

void excluirMedico(Medico medicos[], int *numMedicos, Consulta consultas[], int *numConsultas) {
    int id;
    printf("\n--- Exclusao de Medico ---\n");
    printf("Digite o identificador do medico a ser excluido: ");
    scanf("%d", &id);
    limparInputBuffer();
    int pos = buscarMedicoPorId(medicos, *numMedicos, id);
    if (pos == -1) {
        printf("Medico nao encontrado.\n");
        return;
    }
    Medico m = medicos[pos];
    printf("\nMedico excluido:\n");
    printf("ID: %d\n", m.id);
    printf("Nome: %s\n", m.nome);
    printf("Especialidade: %s\n", m.especialidade);

    for (int i = pos; i < (*numMedicos) - 1; i++) {
        medicos[i] = medicos[i + 1];
    }
    (*numMedicos)--;

    int i = 0;
    while (i < *numConsultas) {
        if (consultas[i].idMedico == id) {
            printf("Excluindo consulta com numero %d associada ao medico.\n", consultas[i].numero);
            for (int j = i; j < (*numConsultas) - 1; j++) {
                consultas[j] = consultas[j + 1];
            }
            (*numConsultas)--;
        } else {
            i++;
        }
    }
    printf("Medico e consultas associadas excluidos com sucesso.\n");
}

void pesquisarMedico(Medico medicos[], int numMedicos) {
    int id;
    printf("\n--- Pesquisa de Medico ---\n");
    printf("Digite o identificador do medico: ");
    scanf("%d", &id);
    limparInputBuffer();
    int pos = buscarMedicoPorId(medicos, numMedicos, id);
    if (pos == -1) {
        printf("Medico nao encontrado.\n");
        return;
    }
    Medico m = medicos[pos];
    printf("\nMedico encontrado:\n");
    printf("ID: %d\n", m.id);
    printf("Nome: %s\n", m.nome);
    printf("Especialidade: %s\n", m.especialidade);
}

void listarPacientes(Paciente pacientes[], int numPacientes) {
    if (numPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
    } else {
        printf("\nLista de Pacientes:\n");
        for (int i = 0; i < numPacientes; i++) {
            printf("ID: %d, Nome: %s, Identidade: %s, Endereco: %s, Telefone: %s, Sexo: %c\n",
                   pacientes[i].id, pacientes[i].nome, pacientes[i].identidade,
                   pacientes[i].endereco, pacientes[i].telefone, pacientes[i].sexo);
        }
    }
}

void listarMedicos(Medico medicos[], int numMedicos) {
    if (numMedicos == 0) {
        printf("Nenhum medico cadastrado.\n");
    } else {
        printf("\nLista de Medicos:\n");
        for (int i = 0; i < numMedicos; i++) {
            printf("ID: %d, Nome: %s, Especialidade: %s\n",
                   medicos[i].id, medicos[i].nome, medicos[i].especialidade);
        }
    }
}

void consultaMenu(Consulta consultas[], int *numConsultas, Paciente pacientes[], int numPacientes, Medico medicos[], int numMedicos) {
    int opcao;
    do {
        printf("----- Menu de Consulta -----\n");
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Pesquisa\n");
        printf("5 - Listar Consultas\n");
        printf("6 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparInputBuffer();
        switch(opcao) {
            case 1:
                incluirConsulta(consultas, numConsultas, pacientes, numPacientes, medicos, numMedicos);
                break;
            case 2:
                alterarConsulta(consultas, *numConsultas, pacientes, numPacientes, medicos, numMedicos);
                break;
            case 3:
                excluirConsulta(consultas, numConsultas);
                break;
            case 4:
                pesquisarConsulta(consultas, *numConsultas, pacientes, numPacientes, medicos, numMedicos);
                break;
            case 5:
                listarConsultas(consultas, *numConsultas);
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 6);
}

void pacienteMenu(Paciente pacientes[], int *numPacientes, Consulta consultas[], int *numConsultas) {
    int opcao;
    do {
        printf("----- Menu de Paciente -----\n");
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Pesquisa\n");
        printf("5 - Listar Todos\n");
        printf("6 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparInputBuffer();
        switch(opcao) {
            case 1:
                incluirPaciente(pacientes, numPacientes);
                break;
            case 2:
                alterarPaciente(pacientes, *numPacientes);
                break;
            case 3:
                excluirPaciente(pacientes, numPacientes, consultas, numConsultas);
                break;
            case 4:
                pesquisarPaciente(pacientes, *numPacientes);
                break;
            case 5:
                listarPacientes(pacientes, *numPacientes);
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 6);
}

void medicoMenu(Medico medicos[], int *numMedicos, Consulta consultas[], int *numConsultas) {
    int opcao;
    do {
        printf("----- Menu de Medico -----\n");
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Pesquisa\n");
        printf("5 - Listar Todos\n");
        printf("6 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparInputBuffer();
        switch(opcao) {
            case 1:
                incluirMedico(medicos, numMedicos);
                break;
            case 2:
                alterarMedico(medicos, *numMedicos);
                break;
            case 3:
                excluirMedico(medicos, numMedicos, consultas, numConsultas);
                break;
            case 4:
                pesquisarMedico(medicos, *numMedicos);
                break;
            case 5:
                listarMedicos(medicos, *numMedicos);
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 6);
}
void relatoriosMenu(Consulta consultas[], int numConsultas, Paciente pacientes[], int numPacientes, Medico medicos[], int numMedicos) {
    int opcao;
    do {
        printf("----- Menu de Relatorios -----\n");
        printf("1 - Lista de consultas agendadas para um paciente\n");
        printf("2 - Lista de consultas agendadas para um medico\n");
        printf("3 - Lista de pacientes por especialidade\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparInputBuffer();
        switch(opcao) {
            case 1: {
                int idPaciente;
                printf("\nDigite o identificador do paciente: ");
                scanf("%d", &idPaciente);
                limparInputBuffer();
                int achou = 0;
                printf("\nConsultas do paciente %d:\n", idPaciente);
                for (int i = 0; i < numConsultas; i++) {
                    if (consultas[i].idPaciente == idPaciente) {
                        printf("Numero: %d, Medico: %d, Horario: %s, Duracao: %d, Data: %s\n", 
                               consultas[i].numero, consultas[i].idMedico, consultas[i].horario, consultas[i].duracao, consultas[i].data);
                        achou = 1;
                    }
                }
                if (!achou)
                    printf("Nenhuma consulta encontrada para este paciente.\n");
                break;
            }
            case 2: {
                int idMedico;
                printf("\nDigite o identificador do medico: ");
                scanf("%d", &idMedico);
                limparInputBuffer();
                int achou = 0;
                printf("\nConsultas do medico %d:\n", idMedico);
                for (int i = 0; i < numConsultas; i++) {
                    if (consultas[i].idMedico == idMedico) {
                        printf("Numero: %d, Paciente: %d, Horario: %s, Duracao: %d, Data: %s\n", 
                               consultas[i].numero, consultas[i].idPaciente, consultas[i].horario, consultas[i].duracao, consultas[i].data);
                        achou = 1;
                    }
                }
                if (!achou)
                    printf("Nenhuma consulta encontrada para este medico.\n");
                break;
            }
            case 3: {
                char especialidade[50];
                lerString("\nDigite a especialidade: ", especialidade, 50);
                int printed[50] = {0};
                int achou = 0;
                for (int i = 0; i < numConsultas; i++) {
                    int posMedico = buscarMedicoPorId(medicos, numMedicos, consultas[i].idMedico);
                    if (posMedico != -1 && strcmp(medicos[posMedico].especialidade, especialidade) == 0) {
                        int posPaciente = buscarPacientePorId(pacientes, numPacientes, consultas[i].idPaciente);
                        if (posPaciente != -1 && printed[posPaciente] == 0) {
                            printf("Paciente ID: %d, Nome: %s\n", pacientes[posPaciente].id, pacientes[posPaciente].nome);
                            printed[posPaciente] = 1;
                            achou = 1;
                        }
                    }
                }
                if (!achou)
                    printf("Nenhum paciente encontrado para esta especialidade.\n");
                break;
            }
            case 4:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 4);
}
int main() {
    Medico medicos[MAX_MEDICOS];
    Paciente pacientes[MAX_PACIENTES];
    Consulta consultas[MAX_CONSULTAS];
    int numMedicos = 0, numPacientes = 0, numConsultas = 0;
    int opcao;
    do {
        printf("----- Menu Principal -----\n");
        printf("1 - Consulta\n");
        printf("2 - Paciente\n");
        printf("3 - Medico\n");
        printf("4 - Relatorios\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparInputBuffer();
        switch(opcao) {
            case 1:
                consultaMenu(consultas, &numConsultas, pacientes, numPacientes, medicos, numMedicos);
                break;
            case 2:
                pacienteMenu(pacientes, &numPacientes, consultas, &numConsultas);
                break;
            case 3:
                medicoMenu(medicos, &numMedicos, consultas, &numConsultas);
                break;
            case 4:
                relatoriosMenu(consultas, numConsultas, pacientes, numPacientes, medicos, numMedicos);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 5);
    return 0;
}
