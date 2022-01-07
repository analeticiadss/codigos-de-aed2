//aed2 - lista de vetor e listas encadeadas

#include <stdio.h>
#include <stdlib.h>

void leLista(int *pLista, int qtd){
    for (unsigned i = 0; i < qtd; i++) {
        scanf("%d%*c", &pLista[i]);
    }
}

void concatena(int *pLista3, int *pLista1, int *pLista2,
                int qtd, int qtd1) {
    unsigned i, k = 0;

    for(i = 0; i < qtd1; i++) {
        pLista3[i] = pLista1[i];
    }
    for(i = qtd1; i < qtd; i++) {
        pLista3[i] = pLista2[k];
        k++;
    }
}

void imprime(int *pLista3, int qtd) {
    for(unsigned i = 0; i < qtd; i++) {
        if(i == qtd-1) {
            printf("%d\n", pLista3[i]);
        } else {
            printf("%d ", pLista3[i]);
        }
    }
}

int main() {
    int *lista1, *lista2, *lista3, qtd1, qtd2;

    scanf("%d%*c", &qtd1); //quantidade de elementos lista 1
    lista1 = (int *) malloc(qtd1*sizeof(int));

    leLista(lista1, qtd1);

    scanf("%d%*c", &qtd2); //quantidade de elementos lista 2
    lista2 = (int *) malloc(qtd2*sizeof(int));

    leLista(lista2, qtd2);

    lista3 = (int *) malloc((qtd1+qtd2)*sizeof(int));

    concatena(lista3, lista1, lista2, qtd1+qtd2, qtd1);

    imprime(lista3, qtd1+qtd2);

    free(lista1); free(lista2); free(lista3);
}
