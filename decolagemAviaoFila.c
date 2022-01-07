//aed2 - filas e pilhas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoAviao {
    char id[3];
    int numId;
} tipoAviao;

typedef struct tipoNo {
    tipoAviao dado;
    struct tipoNo *proxFila;
} tipoNo;

typedef struct tipoFila {
    tipoNo *primFila, *ultFila;
} tipoFila;

void criaFila (tipoFila *pFila) {
    pFila->primFila = NULL;
    pFila->ultFila = NULL;
}

void insereElementoFinalFila(tipoFila *pFila, tipoAviao *dado) {
	tipoNo *aux;

	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *dado;
	aux->proxFila = NULL;
	if(pFila->ultFila != NULL) {
		pFila->ultFila->proxFila = aux;
	}else { // caso esteja vazia
		pFila->primFila = aux;
	}
	pFila->ultFila = aux;
}

int quantidade (tipoFila *pFila) {
    tipoNo *aux; int qtd = 0;
    aux = pFila->primFila;

    while(aux != NULL) {
        qtd++;
        aux = aux->proxFila;
    }
    return qtd;
}

void removeElementoFila(tipoFila *pFila) {
	tipoNo *temp;

	if(pFila->primFila != NULL) { //se tiver pelo menos um elemento na Fila
        temp = pFila->primFila;
        pFila->primFila = temp->proxFila;
        if(pFila->primFila == NULL) {
            pFila->ultFila = NULL;
        }
        free(temp);
	}
}

void imprime(tipoFila *pFila) {
    tipoNo *aux;

    aux = pFila->primFila;
    while(aux != NULL) {
        printf("%s ", aux->dado.id);
        printf("%d\n", aux->dado.numId);
        aux = aux->proxFila;
    }
}

void imprimePrimeiroAviao (tipoFila *pFila) {
    tipoNo *aux;
    aux = pFila->primFila;
    printf("%s %d\n", aux->dado.id, aux->dado.numId);
}

void limpaFila (tipoFila *pFila) {
    tipoNo *aux;
    aux = pFila->primFila;
    while(aux != NULL) {
        pFila->primFila = aux->proxFila;
        free(aux);
        aux = pFila->primFila;
    }
}

int main() {
    tipoFila fila;
    criaFila (&fila);

    tipoAviao aviao;
     char comando;
    //comando = (char*) malloc(sizeof(char));
    scanf("%c%*c", &comando);

    while(comando != 'S') {
        if(comando == 'Q') {
            printf("%d\n", quantidade(&fila));
        } else if(comando == 'D') {
            removeElementoFila(&fila);
        } else if (comando == 'A') {
            scanf("%s%*c %d%*c", aviao.id, &aviao.numId);
            insereElementoFinalFila(&fila, &aviao);
        } else if(comando == 'L') {
            imprime(&fila);
        } else if(comando == 'P') {
            imprimePrimeiroAviao(&fila);
        }
        //comando = (char*) malloc(sizeof(char));
        scanf("%c%*c", &comando);
    }
    if(comando == 'S') {
        limpaFila(&fila);
    }

}
