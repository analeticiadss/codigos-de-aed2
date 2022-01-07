//merge lista encadeada

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNumero {
    float num;
} tipoNumero;

typedef struct tipoNo {
    tipoNumero valor;
    struct tipoNo *proxLista;
} tipoNo;

typedef struct tipoLista {
    tipoNo *primLista, *ultLista;
} tipoLista;

void criaLista(tipoLista *pLista) {
    pLista->primLista = NULL;
    pLista->ultLista = NULL;
}

void insereFinalLista(tipoLista *pLista, float valor) { //insere final
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->valor.num = valor;
    aux->proxLista = NULL;
    if(pLista->ultLista != NULL) {
        pLista->ultLista->proxLista = aux;
    } else {
        pLista->primLista = aux;
    }
    pLista->ultLista = aux;
}

void insereNaLista(tipoLista *pLista, float valor) {
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->valor.num = valor;
    aux->proxLista = pLista->primLista;
    pLista->primLista = aux;
}

void preencheLista (tipoLista *pLista, int tam) {
    float valor;
    for(unsigned i = 0; i < tam; i++) {
        scanf("%f%*c", &valor);
        insereNaLista(pLista, valor);
    }
}

void limpaLista(tipoLista *pLista) {
    tipoNo *aux, *temp;
    aux = pLista->primLista;
    while(aux != NULL) {
        pLista->primLista = aux->proxLista;
        free(aux);
        aux = pLista->primLista;
    }
}

void imprime(tipoLista *pLista) {
    tipoNo *aux;
    aux = pLista->primLista;
    while(aux != NULL) {
        printf("%.1f ", aux->valor.num);
        aux = aux->proxLista;
    }
    printf("\n");
}

void merge(tipoLista *pLista1, tipoLista *pLista2) {
    tipoNo *aux1, *aux2;
    aux1 = pLista1->primLista;
    aux2 = pLista2->primLista;

    tipoLista lista3;
    criaLista(&lista3);

    while(aux1 != NULL && aux2 != NULL) {
        insereFinalLista(&lista3, aux1->valor.num);
        insereFinalLista(&lista3, aux2->valor.num);
        aux1 = aux1->proxLista;
        aux2 = aux2->proxLista;
    }

    while(aux1 != NULL) { //se a lista2 acabar primeiro
        insereFinalLista(&lista3, aux1->valor.num);
        aux1 = aux1->proxLista;
    }
    while(aux2 != NULL) { //se a lista 1 acabar primeiro
        insereFinalLista(&lista3, aux2->valor.num);
        aux2 = aux2->proxLista;
    }

    limpaLista(&lista1);
    limpaLista(&lista2);
    imprime(&lista3);

}

int main () {
    int num1, num2;
    scanf("%d%*c", &num1);

    tipoLista lista1, lista2;
    criaLista(&lista1);

    preencheLista(&lista1, num1); //insere na lista1 os numeros

    scanf("%d%*c", &num2);
    criaLista(&lista2);

    preencheLista(&lista2, num2); //insere na lista2 os numeros
    merge(&lista1, &lista2);

}
