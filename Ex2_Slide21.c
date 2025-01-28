#include <stdio.h>
#include <stdlib.h>

// Caminho do arquivo que armazenará os números
#define ARQUIVO "numeros.bin"

// Função para inicializar o arquivo
void INIC() {
    // Cria ou limpa o arquivo
    FILE *f = fopen(ARQUIVO, "wb");
    if (f == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }
    fclose(f);
}

// Função para inserir um número positivo no arquivo
void INSERIR(int numero) {
    if (numero <= 0) {
        printf("Somente números positivos podem ser inseridos.\n");
        return;
    }

    // Abrir o arquivo para leitura e escrita
    FILE *f = fopen(ARQUIVO, "rb+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(f);
        exit(1);
    }

    int valor, imparesInseridos = 0;

    // Primeiro, insere os ímpares no início do arquivo temporário
    rewind(f);
    while (fread(&valor, sizeof(int), 1, f)) {
        if (valor % 2 != 0) {
            fwrite(&valor, sizeof(int), 1, temp);
            imparesInseridos++;
        }
    }

    // Insere o novo número (caso seja ímpar) após os ímpares
    if (numero % 2 != 0) {
        fwrite(&numero, sizeof(int), 1, temp);
        imparesInseridos++;
    }

    // Insere os pares após os ímpares
    rewind(f);
    while (fread(&valor, sizeof(int), 1, f)) {
        if (valor % 2 == 0) {
            fwrite(&valor, sizeof(int), 1, temp);
        }
    }

    // Insere o novo número (caso seja par)
    if (numero % 2 == 0) {
        fwrite(&numero, sizeof(int), 1, temp);
    }

    fclose(f);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove(ARQUIVO);
    rename("temp.bin", ARQUIVO);
}

// Função para listar todos os números do arquivo
void LISTAR() {
    FILE *f = fopen(ARQUIVO, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int valor;
    printf("Numeros na lista:\n");
    while (fread(&valor, sizeof(int), 1, f)) {
        printf("%d ", valor);
    }
    printf("\n");

    fclose(f);
}

// Função para retirar a primeira ocorrência de um número do arquivo
void RETIRAR(int numero) {
    FILE *f = fopen(ARQUIVO, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporario.\n");
        fclose(f);
        return;
    }

    int valor;
    int encontrado = 0;

    // Copia os números para o arquivo temporário, exceto o número a ser removido
    while (fread(&valor, sizeof(int), 1, f)) {
        if (valor == numero && !encontrado) {
            encontrado = 1; // Marca como encontrado e não copia este número
        } else {
            fwrite(&valor, sizeof(int), 1, temp);
        }
    }

    fclose(f);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove(ARQUIVO);
    rename("temp.bin", ARQUIVO);

    if (encontrado) {
        printf("Numero %d removido com sucesso.\n", numero);
    } else {
        printf("Numero %d não encontrado.\n", numero);
    }
}

// Função principal para interação com o usuário
int main() {
    int opcao, numero;

    INIC(); // Inicializa o arquivo

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir numero\n");
        printf("2. Listar numeros\n");
        printf("3. Retirar numero\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um numero positivo para inserir: ");
                scanf("%d", &numero);
                INSERIR(numero);
                break;

            case 2:
                LISTAR();
                break;

            case 3:
                printf("Digite o numero a ser retirado: ");
                scanf("%d", &numero);
                RETIRAR(numero);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
