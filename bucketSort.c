//aed 2 - ordenação bucket sort

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo {
    int chave;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
    tipoNo *prim;
} tipoLista;

void inicializaLista (tipoLista *pLista) {
    pLista->prim = NULL;
}

int funcaoIndice (int chave, int mBuckets, int nIntervalo) {
    int indice = (chave*mBuckets)/(nIntervalo+1);
    return indice;
}

void inicializaVet (tipoLista *vetB, int mBuckets) {
    for(int i = 0; i < mBuckets; i++) {
        inicializaLista(&vetB[i]);
    }
}

void ordena(tipoLista *pLista) {
    tipoNo *var; int temp;
    var = pLista->prim;
    if(var == NULL) {
        return;
    } else {
    while(var != NULL) {
        tipoNo *aux = var->prox;

        while(aux != NULL) {
            if(var->chave > aux->chave) {
                temp = var->chave;
                var->chave = aux->chave;
                aux->chave = temp;
            }
            aux = aux->prox;
        }
        var = var->prox;
    }
    }
}

void insereLista (tipoLista *pLista, int chave) {
    tipoNo *aux, *temp;
    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->chave = chave;
    aux->prox = pLista->prim;
    pLista->prim = aux;
}

void insereVetorBuckets (tipoLista *vetB, int chave, int j) {
    insereLista(&vetB[j], chave);
}

void ordenaVet(tipoLista *vetB, int mBuckets) {
    for(int i = 0; i < mBuckets; i++) {
        ordena(&vetB[i]);
    }
}

void pegaElementoLista (tipoLista *pLista, int *vet) {
    tipoNo *aux = pLista->prim;
    int i = 0;
    while(aux != NULL) {
        vet[i] = aux->chave;
        printf("%d ", vet[i]);
        i++; aux = aux->prox;
    }
}

void insereVetorChaves (tipoLista *vetB, int mBuckets, int kChaves) {
    int *vet;
    vet = (int*) malloc(sizeof(int)*kChaves);

    for(int i = 0; i < mBuckets; i++) {
        pegaElementoLista(&vetB[i], vet);
    }
    printf("\n");
    free(vet);
}

void imprimeLista (tipoLista *pLista) {
    tipoNo *aux;
    aux = pLista->prim;
    while(aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

void imprimeVetorLista (tipoLista *vetB, int mBuckets) {
    for(int i = 0; i < mBuckets; i++) {
        printf("%d ", i);
        if(vetB[i].prim == NULL) {
            printf("NULL");
        } else {
            imprimeLista(&vetB[i]);
        }
        printf("\n");
    }
}

int main () {
    int mBuckets, kChaves, nIntervalo;
    scanf("%d%*c %d%*c %d%*c", &mBuckets, &kChaves, &nIntervalo);

    tipoLista *vetB;
    vetB = (tipoLista*) malloc(mBuckets*sizeof(tipoLista)); //cria o vetor de buckets

    inicializaVet(vetB, mBuckets);

    int chave;
    for(int i = 0; i < kChaves; i++) {
        scanf("%d%*c", &chave);
        if(chave <= nIntervalo) {
            int j = funcaoIndice(chave, mBuckets, nIntervalo);
            insereVetorBuckets(vetB, chave, j);
        }
    }

    ordenaVet(vetB, mBuckets);
    imprimeVetorLista(vetB, mBuckets);
    insereVetorChaves(vetB, mBuckets, kChaves);
    free(vetB);
}
