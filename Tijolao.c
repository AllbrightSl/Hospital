#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tecla(char anterior, char atual) {
   char teclas[11][9] = {
        "0",
        "abcABC", 
        "defDEF", 
        "ghiGHI", 
        "jklJKL", 
        "mnoMNO", 
        "pqrsPQRS", 
        "tuvTUV", 
        "wxyzWXYZ",
        " ", 
        /*"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",*/
    };

    for (int i = 0; i < 11; i++) {
        if (strchr(teclas[i], anterior) && strchr(teclas[i], atual)) {
            return 1;
            break; // Estão na mesma tecla
        }
    }
    return 0;
}

    int seq(char letra){
    if (letra == 'a') return 2;
    else if (letra == 'b') return 22;
    else if (letra == 'c') return 222;
    else if (letra == 'd') return 3;
    else if (letra == 'e') return 33;
    else if (letra == 'f') return 333;
    else if (letra == 'g') return 4;
    else if (letra == 'h') return 44;
    else if (letra == 'i') return 444;
    else if (letra == 'j') return 5;
    else if (letra == 'k') return 55;
    else if (letra == 'l') return 555;
    else if (letra == 'm') return 6;
    else if (letra == 'n') return 66;
    else if (letra == 'o') return 666;
    else if (letra == 'p') return 7;
    else if (letra == 'q') return 77;
    else if (letra == 'r') return 777;
    else if (letra == 's') return 7777;
    else if (letra == 't') return 8;
    else if (letra == 'u') return 88;
    else if (letra == 'v') return 888;
    else if (letra == 'w') return 9;
    else if (letra == 'x') return 99;
    else if (letra == 'y') return 999;
    else if (letra == 'z') return 9999;
    else if (letra == ' ') return 0;
}
int main(){
    int N;
    char str[141], atual, anterior;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){ // Só para receber os casos
        fgets(str, 141, stdin);
        str[strcspn(str, "\n")] = '\0';
        int tam = strlen(str);
        int diferentes = 1;
        for(int j = 0; j < tam; j++){ // Passar cada caracter de um unico caso
        if (j == 0)
        anterior = str[0];
        atual = str[j];
            if (j > 0){
                if (tecla(anterior, atual) && islower(str[j]) != 0)
                    printf("*");
        }
            if (isupper(str[j]) != 0){
                printf("#");
                str[j] = tolower(str[j]);
            }
        char letra = str[j];
        printf("%d", seq(letra));
        anterior = atual;
        }
        printf("\n");
    }
    return 0;
}