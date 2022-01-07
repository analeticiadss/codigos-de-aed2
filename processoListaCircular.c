//lista de processos lista circular tp07

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPrograma {
    char nome[80];
    unsigned tempo;
} tipoPrograma;

typedef struct tipoNo {
    tipoPrograma programa;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
    tipoNo *prim, *ult;
    unsigned qtd;
} tipoLista;

void criaLista (tipoLista *pLista) {
    pLista->prim = NULL;
    pLista->ult = NULL;
    pLista->qtd = 0;
}

void insereLista (tipoLista *pLista, tipoPrograma *programa) {
    tipoNo *aux;
    aux = (tipoNo *) malloc(sizeof(tipoNo));

    aux->programa = *programa;
    pLista->qtd++;
    if(pLista->prim == NULL) {
        pLista->prim = aux;
        pLista->ult = aux;
        aux->prox = aux;
    } else {
        pLista->ult->prox = aux;
        aux->prox = pLista->prim;
        pLista->ult = aux;
    }
}

int processo (tipoLista *pLista, tipoPrograma *programa, int Q) {
    tipoNo *aux = pLista->prim;
    unsigned tempo = 0, soma = 0;

    while(1) {
        tempo++;
        soma++;
        aux->programa.tempo--;
        if(aux->programa.tempo == 0) {
            printf("%u us: %s finalizou\n", soma, aux->programa.nome);
            tempo = 0;
            aux = aux->prox;
            while(aux->programa.tempo == 0) {
                aux = aux->prox;
                if(aux == pLista->ult && aux->programa.tempo == 0) {
                    return 1;
                }
            }
        }
        else if(tempo == Q) {
            tempo = 0;
            aux = aux->prox;
            while(aux->programa.tempo == 0) {
                aux = aux->prox;
            }
        }
    }
}

int main () {
    int Q, N; // Q = tempo e N = numero de programas
    tipoLista lista;
    tipoPrograma programa;
    criaLista(&lista);
    scanf("%d%*c %d%*c", &Q, &N);

    while(N != 0) {
        scanf("%s%*c", programa.nome);
        scanf("%u%*c", &programa.tempo);
        insereLista(&lista, &programa);
        N--;
    }

    processo(&lista, &programa, Q);
}
