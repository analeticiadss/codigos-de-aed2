//IMPLEMENTA��O ARVORE BINARIA 30/09/2021 - AED2

/*  Aloca��o est�tica:
    -> usa array;
    -> usa 2 fun��es para retornar a posi��o dos filhos � esquerda
    e � direita de um pai:
        -> filho � esquerda: 2*PAI + 1;
        -> filho � direita: 2*PAI + 2;
    -> � bom usar quando a �rvore � bin�ria completa.

    Aloca��o din�mica (lista encadeada):
    -> cada n� da �rvore � tratado como um ponteiro alocado dinamicamente �
    medida que os dados s�o inseridos;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo {
    int info;
    struct tipoNo *esq, *dir;
} tipoNo;

tipoNo* inicializaArv () {
    return NULL;
}

void libera (tipoNo *raiz) {
    if(raiz == NULL) {
        return;
    }
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

tipoNo *insereNaArv (tipoNo *raiz, int x) {
    //se for o primeiro elemento
    if(raiz == NULL) { //se a raiz for igual a NULL
        tipoNo *aux;
        aux = (tipoNo*) malloc(sizeof(tipoNo));
        aux->info = x;
        aux->esq = NULL;
        aux->dir = NULL;
        raiz = aux;
    } else {
        /*se x for maior que o elemento ja inserido,
         insere na direita, caso contr�rio, insere na esquerda */
        if(x > raiz->info) {
            raiz->dir = insereNaArv(raiz->dir, x);
        } else if (x <= raiz->info) {
            raiz->esq = insereNaArv(raiz->esq, x);
        }
    }
    return raiz;
}

int busca(tipoNo *raiz, int x) {
    if(raiz == NULL) {
        return 0;
    } else if(raiz->info == x) {
        return 1;
    } else if(x <= raiz->info) {
        return busca(raiz->esq, x);
    } else if (x > raiz->info) {
        return busca(raiz->dir, x);
    }
}
