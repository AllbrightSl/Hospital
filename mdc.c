#include <stdio.h>
int main(){
    int maiorDiv = 0, contDiv = 0, num_div = 1;

    for(int num = 1; num <= 10000; num++){
        contDiv = 0;

        for (int i = 1; i <= num; i++){
            if (num % i == 0){
                contDiv++;
            }
        }

    if (contDiv > maiorDiv){
        maiorDiv = contDiv;
        num_div = num;
    }
    }
    printf("O numero com mais divisores eh %d, com %d divisores\n", num_div, maiorDiv);


    for (int i = 1; i <= num_div; i++){
        if (num_div % i == 0){
            printf("%d, ", i);
        }
    }


    return 0;
}