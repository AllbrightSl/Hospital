#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[30]; 
    int codigo;    
    float preco;  
};

int main() {
    struct Produto *produtos = malloc(10 * sizeof(struct Produto));
    if (produtos == NULL)
        return -1;
        
    strcpy(produtos[0].nome, "Pe de Moleque");
    produtos[0].codigo = 13205;
    produtos[0].preco = 0.20;

    strcpy(produtos[1].nome, "Cocada Baiana");
    produtos[1].codigo = 15202;
    produtos[1].preco = 0.50;


    printf("Produto 0:\n");
    printf("Nome: %s\n", produtos[0].nome);
    printf("Codigo: %d\n", produtos[0].codigo);
    printf("Preco: R$%.2f\n", produtos[0].preco);

    printf("\nProduto 1:\n");
    printf("Nome: %s\n", produtos[1].nome);
    printf("Codigo: %d\n", produtos[1].codigo);
    printf("Preco: R$%.2f\n", produtos[1].preco);

    free(produtos);

    return 0;
}
