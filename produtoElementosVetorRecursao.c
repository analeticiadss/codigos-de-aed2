//multiplicação dos elementos de um vetor - recursividade - aed2

#include <stdio.h>
#include <stdlib.h>

int zero(int numero) {
   return (numero == 0);
}

int incrementa(int numero) {
    return (numero+1);
}

int decrementa(int numero) {
    return (numero-1);
}

int soma(int num1, int num2) {
    if(zero(num2)) {
        return num1;
    }
    return soma(incrementa(num1), decrementa(num2));
}

int multiplica(int num1, int num2) {
    num1 = decrementa(num1);
    if(zero(num1)) {
        return num2;
    }
    return soma(num2,multiplica(num1, num2));
}

int main() {
    int i;
    int *vet, produto = 1;
    unsigned x;

    scanf("%d%*c", &i); //qtd de elementos

    vet = (int*) malloc(i*sizeof(int));

    for(x = 0; x < i; x++) {
       scanf("%d%*c", &vet[x]);
       produto = multiplica(vet[x], produto);
    }

    printf("%d\n", produto);
}
