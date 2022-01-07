//listas nao disjuntas recursividade aed2

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoValor {
    unsigned num;
} tipoValor;

typedef struct tipoNo {
    tipoValor dado;
    struct tipoNo *proxLista;
} tipoNo;

typedef struct tipoLista {
    tipoNo *primLista;
} tipoLista;

void criaLista(tipoLista *pLista) {
    pLista->primLista = NULL;
}

void insereElementoLista(tipoLista *pLista, tipoValor *valor) {
    tipoNo *aux;
    aux = (tipoNo *) malloc(sizeof(tipoNo));

    aux->dado = *valor;
    aux->proxLista = pLista->primLista;
    pLista->primLista = aux;
}

void leLista (tipoLista *pLista) {
    tipoValor valor;
    scanf("%u%*c", &valor.num);
    while(valor.num != 0) {
        insereElementoLista(pLista, &valor);
        scanf("%u%*c", &valor.num);
    }
}

int elementoComum(tipoLista *pLista1, tipoLista *pLista2) {
    tipoNo *aux1, *aux2;
    aux1 = pLista1->primLista;
    aux2 = pLista2->primLista;

    while(aux1->proxLista != NULL) {
        while(aux2->proxLista != NULL) {
            if(aux1->dado.num == aux2->dado.num) { //se for igual
                return 1; // retorna true
            }
            aux2 = aux2->proxLista; //avança com aux2
        }
        if(aux2->proxLista == NULL) { //quando sair do segundo while porque aux2->proxLista == NULL
            if(aux1->dado.num == aux2->dado.num) {
                return 1;
            }
        }
        aux1 = aux1->proxLista;
        aux2 = pLista2->primLista; //volta pro prim elemento da lista

        if(aux1->proxLista == NULL) { //tá no ultimo elemento da lista1
            while(aux2->proxLista != NULL) { //verifica quais da lista2 são iguais ao ultimo da lista1
                if(aux2->dado.num == aux1->dado.num) {
                    return 1;
                }
                aux2 = aux2->proxLista;
            }
            if(aux2->proxLista == NULL) {
                if(aux2->dado.num == aux1->dado.num) {
                    return 1;
                }
            }
        }
    }
    return 0; //caso saia do while
}

int main () {
    tipoValor valor1, valor2;
    tipoLista lista1, lista2;

    criaLista(&lista1);
    criaLista(&lista2);

    leLista(&lista1);
    leLista(&lista2);

    if(elementoComum(&lista1, &lista2)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

}
