#include <stdio.h>
double pot (double a, int b){
    double acum = 1;

    for(int i = 1; i <= b; i++)
    acum = acum * a;

    return acum;
    
}
int main(){
    double potencia;
    for (int i = 2; i <= 10; i++){   //i é a base que será elevado
        for (int x = 0; x<= 10; x++){ // x é o expoente
        potencia = pot (i, x);

        printf("%d^%d = %.0lf\n", i, x, potencia);
}
    }
    return 0;
}