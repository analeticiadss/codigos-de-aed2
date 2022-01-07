//soma de um vetor de N elementos - recursividade - aed2

#include <stdio.h>
#include <stdlib.h>

int zero(int num) {
   return (num == 0);
}

int incrementa(int num) {
    return (num+1);
}

int decrementa(int num) {
    return (num-1);
}

int negativo(int num) {
    if(num < 0) {
        return 1;
    }
    return 0;
}

int somaPositivo(int num1, int num2) {
    if(zero(num2)) {
        return num1;
    }
    return somaPositivo(incrementa(num1), decrementa(num2));
}

int somaNegativo(int num1, int num2) {
    if(zero(num2)) {
        return num1;
    }
    return somaNegativo(decrementa(num1), incrementa(num2));
}

int main() {
    int i, *vet, cont = 0;
    scanf("%d%*c", &i); //quantidade de elementos

    vet = (int*) malloc(i*sizeof(int));
    for(int x = 0; x < i; x++) {
        scanf("%d%*c", &vet[x]);
        if(negativo(vet[x])) {
            cont = somaNegativo(cont, vet[x]);
        }else {
            cont = somaPositivo(cont, vet[x]);
        }
    }
    printf("%d\n", cont);
}
