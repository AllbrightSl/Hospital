#include <stdio.h>
#include <string.h>
int main(){
    int N, K;
    char str1[21], str2[2];
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++){
    scanf("%d", &K);
    getchar();
        for (int j = 0; j < K; j++){
            if (j == 0){
            fgets(str1, sizeof(str1), stdin);
            getchar();

            if (K == 1){
            printf("Nao ha comparacao\n");
            break;
            }

            fgets(str2, sizeof(str2), stdin);
            getchar();
            }

            if (strcmp(str2, str1) != 0){
                printf("ingles\n");
                break;
            }
            strcpy(str1, str2);

            fgets(str2, sizeof(str2), stdin);
                
        }
        if (strcmp(str1, str2) == 0){
            printf("%s\n", str1);
        }
    }
    return 0;
}