#include <stdio.h>
#define MAX 100
int menu(){
    int escolha;
    printf("O que voce deseja?\n");
    printf("1 - Criar um usuario\n");
    printf("2 - Incluir usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar através do CPF um usuario\n");
    printf("5 - Sair\n");
    scanf("%d", &escolha);
    getchar();
    return escolha;
}
typedef struct usuarios{
    char nome[MAX];
    char cpf[15];
    char curso[MAX];
}USUARIO;
void criar(){

}

int main(){
    while(1){
    printf("Ola. Seja bem vindo(a) à biblioteca de Eng. Comp do CEFET MG\n");
    switch(menu()){
        USUARIO *ptr; 
        ptr = malloc(sizeof(USUARIO));
        case 1:
        printf("Escreva seu nome completo:\n");
        scanf("%[^\n]", &ptr->nome);
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        printf("Informe o CPF desejado:\n");
        char CPF[15];
        fgets(CPF, 15, stdin);
        break;
        case 5:
        printf("Saindo...");
        return 0;

        default:
        printf("Erro: Escolha um opcao valida\n");
        break;
        }
    }
}