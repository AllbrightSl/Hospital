#include <stdio.h>
#include <string.h>
int main(){
    char str[100], *p;
    int tam;
    printf("Escreva sua string:\n");
    fgets(str, sizeof(str), stdin);

    tam = strlen(str);
    if (str[tam-1] == '\n'){
        str[tam - 1] = '\0';
        tam--;
    }

    p = str;

    printf("\nNormal:\n");

    while(*p != '\0'){ 
    printf("%c", *p);
    p++;
    }

    printf("\nContrario:\n");

    do{
    p--;
    printf("%c", *p);
    }
    while (p != str);

    printf("\n");
    return 0;
}