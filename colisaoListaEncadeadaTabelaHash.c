//colisao em lista encadeada

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoDado {
    int chave;
    char nome[20];
} tipoDado;

typedef struct tipoNo {
    tipoDado dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
    tipoNo *prim, *ult;
    int tam;
} tipoLista;

void criaLista (tipoLista *pLista) {
    pLista->prim = NULL;
    pLista->ult = NULL;
}

int verificaValorRepetido (tipoLista *pLista, tipoDado *dado) {
    tipoNo *aux;
    aux = pLista->prim;
    while(aux != NULL) {
        if(aux->dado.chave == dado->chave) {
            return 1; //já tem esse valor
        }
        aux = aux->prox;
    }
    return 0; //não tem o valor
}

void insereFinal (tipoLista *pLista, tipoDado *dado) {
    tipoNo *aux;
    if(verificaValorRepetido(pLista, dado) == 0) {
        aux = (tipoNo*) malloc(sizeof(tipoNo));
        aux->dado = *dado;
        aux->prox = NULL;

        if(pLista->ult == NULL) {
            pLista->prim = aux;
        } else {
            pLista->ult->prox = aux;
        }
        pLista->ult = aux;
    }
    return;
}

void imprimeLista (tipoLista *pLista, unsigned i) {
    tipoNo *aux;
    aux = pLista->prim;
    while(aux != NULL) {
        printf("%d %d %s\n", i, aux->dado.chave, aux->dado.nome);
        aux = aux->prox;
    }
}

int buscarNaLista (tipoLista *pLista, int dado) {
    tipoNo *aux;
    aux = pLista->prim;

    while(aux->prox != NULL && aux->dado.chave != dado) {
        aux = aux->prox;
        if(aux->dado.chave == dado) {
            return aux->dado.chave;
        }
    }
    /** aux->prox é NULL por isso sai do while */
    if(aux->dado.chave != dado) {
            return -1;
    }

}

char* buscarNomeNaLista (tipoLista *pLista, int dado) {
    tipoNo *aux;
    aux = pLista->prim;
    while(aux != NULL && aux->dado.chave != dado) {
        aux = aux->prox;
    }
    if(aux->dado.chave == dado) {
        return aux->dado.nome;
    }
}

void inicializaHash (tipoLista *pHash, int tam) {
    unsigned i;
    for(i = 0; i < tam; i++) {
        criaLista(&pHash[i]);
    }
}

/** função hash */
int funcHash (int dado, int tamanho) {
    int funcao;
    funcao = dado%tamanho;
    return funcao;
}

void insereHash (tipoLista *pHash, tipoDado *dado, int i) {
    insereFinal(&pHash[i], dado);
}

int verificaHash(tipoLista *pHash, int tam) {
    int qtd = 0;
    for(int i = 0; i < tam; i++) {
        if(pHash[i].prim == NULL) {
            return 0;
        }
        qtd++;
    }
    if(qtd == tam) {
        return 1;
    }
}

int buscarChaveNaHash (tipoLista *pHash, int dado, int i) {
    int valor = buscarNaLista(&pHash[i], dado);

    if(valor == -1) {
        return -1;
    } else {
        return valor;
    }
}

int buscarChaveNaHashNaoCheia (tipoLista *pHash, int dado, int i) {

    if(pHash[i].prim == NULL) {
        return -1;
    } else {
        int valor = buscarNaLista(&pHash[i], dado);
        return valor;
    }
}

void imprimeHash(tipoLista *pHash, int tam) {
    unsigned i;
    for(i = 0; i < tam; i++) {
        if(pHash[i].prim != NULL) {
            imprimeLista(&pHash[i], i);
        }
        else {
            printf("%u ", i);
            printf("null null\n");
        }
    }
}

int main() {
    int tam, i;
    scanf("%d%*c", &tam);

    tipoLista *tabHash, lista;
    tabHash = (tipoLista*) malloc(sizeof(tipoLista)*tam);
    inicializaHash(tabHash, tam);

    tipoDado dado;
    scanf("%d%*c", &dado.chave);
    while(dado.chave != 0) {
        scanf("%[^\n]%*c", dado.nome);
        i = funcHash(dado.chave, tam);
            insereHash(tabHash, &dado, i);
        scanf("%d%*c", &dado.chave);
    }
    imprimeHash(tabHash, tam);
    printf("- - -\n");

    int valor;
    scanf("%d%*c", &valor);
    while(valor != 0) {
        i = funcHash(valor, tam);
        int verif = verificaHash(tabHash, tam);

        if(verif == 1) {
            if(buscarChaveNaHash(tabHash, valor, i) != -1) {
                printf("%d %d %s\n", i, valor, buscarNomeNaLista(&tabHash[i], valor));
            }
            else if(buscarChaveNaHash(tabHash, valor, i) == -1) {
                printf("%d not found\n", valor);
            }
        }
        else {
            if(buscarChaveNaHashNaoCheia(tabHash, valor, i) != -1) {
                printf("%d %d %s\n", i, valor, buscarNomeNaLista(&tabHash[i], valor));
            } else {
                printf("%d not found\n", dado);
            }
        }
        scanf("%d%*c", &valor);
    }
    free(tabHash);
}
