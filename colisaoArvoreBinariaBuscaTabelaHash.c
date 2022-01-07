//se colidir deve haver uma arvore binaria de buscarHash

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoDado {
    int chave;
    char nome[20];
} tipoDado;

typedef struct tipoNo {
    tipoDado dado;
    int isEmpty;
    struct tipoNo *esq, *dir;
} tipoNo;

/** inicializa arvore */
tipoNo* inicializaArvore (tipoNo *raiz) {
    raiz = NULL;
    return raiz;
}

int buscaArvore(tipoNo *raiz, int x) {
    if(raiz == NULL) {
        return 0;
    } else if(raiz->dado.chave == x) {
        return x;
    } else if(x < raiz->dado.chave) {
        return buscaArvore(raiz->esq, x);
    } else if (x > raiz->dado.chave) {
        return buscaArvore(raiz->dir, x);
    }
}

char* buscaNomeNaArvore(tipoNo *raiz, int x) {
    if(raiz == NULL) {
        return 0;
    } else if(raiz->dado.chave == x) {
        return raiz->dado.nome;
    } else if(x < raiz->dado.chave) {
        return buscaNomeNaArvore(raiz->esq, x);
    } else if (x > raiz->dado.chave) {
        return buscaNomeNaArvore(raiz->dir, x);
    }
}

/** insere na arvore */
tipoNo* insere (tipoNo *raiz, tipoDado *dado) {
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *dado;
    //strcpy(aux->nome, nome);

    if(buscaArvore(raiz, dado->chave) == 0) {
        if(raiz != NULL) {
            if(aux->dado.chave < raiz->dado.chave) {
                raiz->esq = insere(raiz->esq, dado);
            } else {
                raiz->dir = insere(raiz->dir, dado);
            }
        } else {
            raiz = aux;
            raiz->esq = NULL;
            raiz->dir = NULL;
        }
        raiz->isEmpty = 1; //não tá vazio
        return raiz;
    }
}

/** inicializa a tabela hash com todos os elementos do vetor == null
    já que não tem nenhum elemento inserido e todos os espaços do vetor
    estão vazios
*/
void inicializaHash (tipoNo *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
        pHash[i].dado.chave = 0;
    }
}

/** função hash */
int funcHash (int dado, int tamanho) {
    int funcao;
    funcao = dado%tamanho;
    return funcao;
}

/** insere na tabHash se estiver vazio apenas */
void insereHash (tipoNo *pHash, tipoDado *dado, int i) {
    insere(&pHash[i], dado);
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
    if(raiz->isEmpty == 1) {
        if(raiz->dado.chave != 0) {
            printf("%d %s ", raiz->dado.chave, raiz->dado.nome);
        }

    } else if (raiz->isEmpty != 1) {
        printf("null ");
    }
    infixa (raiz->dir);
}

/** função de imprimir a tabela hash */
void imprimeHash (tipoNo *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
            printf("%u ", i);
            infixa(&pHash[i]);
            printf("\n");
    }
}

int buscarChaveNaHash (tipoNo *pHash, int dado, int i) {
    int valor = buscaArvore(&pHash[i], dado);

    if(valor == 0) {
        return 0;
    } else {
        return valor;
    }
}

int main () {
    int tamHash, posicaoHash;
    tipoNo *tabHash; tipoDado dado;

    scanf("%d%*c", &tamHash); //tamanho da tabela Hash
    tabHash = (tipoNo*) malloc(sizeof(tipoNo)*tamHash);
    inicializaHash(tabHash, tamHash);

    scanf("%d%*c", &dado.chave);
    while(dado.chave != 0) {
        scanf("%[^\n]%*c", dado.nome);
        posicaoHash = funcHash(dado.chave, tamHash);
        insereHash(tabHash, &dado, posicaoHash);

        scanf("%d%*c", &dado.chave);
    }
    imprimeHash(tabHash, tamHash);
    printf("- - -\n");

    int valor;
    scanf("%d%*c", &valor);
    while(valor != 0) {
        posicaoHash = funcHash(valor, tamHash);
        if(buscarChaveNaHash(tabHash, valor, posicaoHash) != 0) {
            printf("%d %d %s\n", posicaoHash, valor, buscaNomeNaArvore(&tabHash[posicaoHash], valor));
        } else {
            printf("%d not found\n", valor);
        }
        scanf("%d%*c", &valor);
    }
}
