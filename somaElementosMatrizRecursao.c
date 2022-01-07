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
    int M, N, soma = 0, **matriz;
    unsigned i, x, y;
    scanf("%d%*c %d%*c", &M, &N); //M == LINHAS N == COLUNAS

    matriz = (int**) malloc(M*sizeof(int*));
    for(i = 0; i < M; i++) {
        matriz[i] = (int*) malloc(N*sizeof(int));
    }

    for(x = 0; x < M; x++) {
        for(y = 0; y < N; y++) {
            scanf("%d%*c", &matriz[x][y]);
        }
    }

    for(x = 0; x < M; x++) {
        for(y = 0; y < N; y++) {
            if(negativo(matriz[x][y])) {
                soma = somaNegativo(soma, matriz[x][y]);
            } else {
                soma = somaPositivo(soma, matriz[x][y]);
            }
        }
    }
    printf("%d\n", soma);
}
