//árvore genérica aed 2 01/10/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo {
    char info;
    struct tipoNo *prim, *prox;
} tipoNo;

tipoNo* inicializaArvore(tipoNo *raiz) {
    return NULL;
}

tipoNo* cria(char caracter) {
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->info = caracter;
    aux->prim = NULL;
    aux->prox = NULL;
    return aux;
}

void insereNaArv(tipoNo *raiz, tipoNo *filho, char caracter) {
    tipoNo *aux;

    for(aux = raiz->prim; aux != NULL; aux = aux->prox) {
        if(aux->info == caracter) {
            raiz = aux;
            break;
        }
    }
    if(raiz->prim == NULL) {
        raiz->prim = filho;
        raiz->prim->info = filho->info;
        raiz->prox = NULL;
    } else {
        raiz->prim->prox = filho;
        raiz->prim->prox->info = filho->info;
    }
}

void imprime(tipoNo *raiz) {
    tipoNo *aux;
    printf("%c\n", raiz->info);
    for(aux = raiz->prim; aux != NULL; aux = aux->prox) {
        imprime(aux);
    }
}

void libera(tipoNo *raiz) {
    tipoNo *aux;
    aux = raiz->prim;
    while(aux != NULL) {
        tipoNo *temp = aux->prox;
        libera(aux);
        aux = temp;
    }
    free(raiz);
}

/*tipoNo* busca(tipoNo *raiz, char caracter) {
    tipoNo *aux;

    for(aux = raiz->prim; aux != NULL; aux = aux->prox) {
        if(aux->info == caracter) {
            return aux;
        }
    }
}*/

int main () {
    tipoNo *raiz, *filho;
    char charRaiz, charFilho, charBusca;
    raiz = NULL;

    scanf("%c%*[\n]", &charRaiz); //primeiro caracter == raiz da arv
    raiz = cria(charRaiz);

    scanf("%c%*[\t]", &charFilho);
    scanf("%c%*[\n]", &charBusca);

    while(charFilho != '#' && charBusca != '#') {
        filho = cria(charFilho); //cria o filho
        //raiz = busca(raiz, charBusca);
        insereNaArv(raiz, filho, charBusca);
        scanf("%c%*[\t] %c%*[\n]", &charFilho, &charBusca);
    }
    imprime(raiz);
    libera(raiz);
}
