//soma de elementos de uma matriz - aed2 - recursividade

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

int menor(int numero1, int numero2) { //se o numero1 < numero2, numero1 chega em 0 mais rapido
   if(zero(numero1)) {
        return 1;
   }
   if(zero(numero2)) {
        return 0;
   }
   return menor(decrementa(numero1),decrementa(numero2));
}

int igual(int num1, int num2) {
    if(zero(num1)) {
        if(zero(num2)) {
            return 1;
        }
        return 0;
    }
    if(zero(num2)) {
        return 0;
    }
    return igual(decrementa(num1), decrementa(num2));
}

int diferente(int num1, int num2) {
    if(igual(num1, num2)) { //se for verdade
        return 0;
    }
    return 1;
}

int soma(int num1, int num2) {
    if(zero(num2)) {
        return num1;
    }
    return soma(incrementa(num1), decrementa(num2));
}



int main () {
    int M, N; //M = linhas, N = colunas
    scanf("%d%*c %d%*c", &M, &N);

    int **matriz = (int*) malloc(M*sizeof(int*));
    for(unsigned k = 0; k < M; k++) {
        matriz[k] = (int*) malloc(N*sizeof(int));
    }

    for(unsigned i = 0; i < M; i++) {
        for(unsigned j = 0; j < N; j++) {
            scanf("%d%*c", matriz[i][j]);
        }
    }

    if(M < 20 && N < 20) {
        somatorio(M, N);
    }
}
