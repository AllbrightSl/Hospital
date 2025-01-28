#include <stdio.h>

/*Utilizei "unsigned long long" porque 20! estava ultrapassando 
a quantia de memória quando usando apenas "long" e dando o resultado negativo */

unsigned long long fat (long n){

unsigned long long acum = 1;
while (n >= 1){
acum = acum*(n);
n--;
}

return acum;
}

int main(){

    for (long i = 1; i <= 20; i++){
        printf("%ld! = %llu\n", i, fat(i));
    }
    return 0;
}