#include <stdio.h>
#include <string.h>

void achadorC(char str[], char carac, char *p, int achou){
    if(*p == '\0'){
        if (achou == 0){
            printf("Nao ha caracter em comum\n");
            return;
        }
        printf("\n");
        return;
    }

    if (*p == carac){
        achou = 1;
    }
    if (achou){
        printf("%c", *p);
    }
    p++;
    achadorC(str, carac, p, achou);
}

int main(){
    char str[100], carac, *p;
    int achou = 0;
    printf("Escreva sua string:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    p = str;
    printf("Escreva seu caracter: ");
    scanf("%c", &carac);
    achadorC(str, carac, str, achou);
    return 0;
}