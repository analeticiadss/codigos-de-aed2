//inversão de lista usando recursividade aed2

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNum {
    int num;
} tipoNum;

typedef struct tipoNo {
    tipoNum numeros;
    struct tipoNo *proxLista;
} tipoNo;

typedef struct tipoLista {
    tipoNo *primLista;
} tipoLista;

void criaLista(tipoLista *pLista) {
    pLista->primLista = NULL;
}

void insereElementoLista(tipoLista *pLista, tipoNum *numero) {
    tipoNo *aux;

    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->numeros = *numero;
    aux->proxLista = pLista->primLista;
    pLista->primLista = aux;
}

void leLista(tipoLista *pLista) {
    tipoNum numero;
    scanf("%d%*c", &numero.num);
    insereElementoLista(pLista, &numero);
    while(numero.num != 0) {
        scanf("%d%*c", &numero.num);
        insereElementoLista(pLista, &numero);
    }
}

void imprime(tipoLista *pLista) {
    tipoNo *aux;

    aux = pLista->primLista;
    while(aux->proxLista != NULL) {
        printf("%d ", aux->proxLista->numeros.num);
        aux = aux->proxLista;
    }
}

int main() {

    tipoLista lista1, lista2;

    criaLista(&lista1);
    leLista(&lista1);
    imprime(&lista1);
}
