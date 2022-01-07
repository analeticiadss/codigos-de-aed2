//arvore binaria de busca

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo {
    int valor;
    struct tipoNo *esq, *dir;
} tipoNo;

tipoNo* inicializa (tipoNo *raiz) {
    raiz = NULL;
    return raiz;
}

tipoNo* busca(tipoNo *raiz, int x) {
    if(raiz == NULL) {
        return 0;
    } else if(raiz->valor == x) {
        return raiz;
    } else if(x <= raiz->valor) {
        return busca(raiz->esq, x);
    } else if (x > raiz->valor) {
        return busca(raiz->dir, x);
    }
}

tipoNo* insere (tipoNo *raiz, int valor) {
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->valor = valor;
    if(raiz != NULL) {
        if(aux->valor <= raiz->valor) {
            raiz->esq = insere(raiz->esq, valor);
        } else {
            raiz->dir = insere(raiz->dir, valor);
        }
    } else {
        raiz = aux;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    return raiz;
}

void enxerto(tipoNo *raiz, tipoNo *raizEnxertada) {
    if(raizEnxertada->valor <= raiz->valor) {
        raiz->esq = raizEnxertada;
    } else if(raizEnxertada->valor > raiz->valor) {
        raiz->dir = raizEnxertada;
    }
}

void libera (tipoNo *raiz) {
    if(raiz == NULL) {
        return;
    }
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

void infixa (tipoNo *raiz) {
    if(raiz == NULL) {
        return;
    }
    infixa (raiz->esq);
    printf("%d\n", raiz->valor);
    infixa (raiz->dir);
}

int main() {
    tipoNo *raiz1, *raiz2;
    raiz1 = inicializa(raiz1);
    raiz2 = inicializa(raiz2);

    tipoNo num;
    scanf("%d%*c", &num.valor);

    while(num.valor != 0) {
        raiz1 = insere(raiz1, num.valor);
        scanf("%d%*c", &num.valor);
    }

    scanf("%d%*c", &num.valor);
    while(num.valor != 0) {
        raiz2 = insere(raiz2, num.valor);
        scanf("%d%*c", &num.valor);
    }

    scanf("%d%*c", &num.valor);
    tipoNo *raiz3 = busca(raiz1, num.valor);

    enxerto(raiz3, raiz2);

    infixa(raiz1);
    libera(raiz1); libera(raiz2);

}
