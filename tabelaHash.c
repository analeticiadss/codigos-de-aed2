//TABELA HASH - AED2 - 18/10/2021

/**
    Tamanho do vetor > Numero máximo de emlementos
    Fator de carga = qtd de elementos colocados/tamanho do vetor
        -> quanto mais proximo de 1 (o fator de carga), mais fácil é
        de se ter colisões, porque o numero de elementos colocados está mais
        próximo do tamanho do vetor
        -> quanto mais próximo de 0, mais o vetor terá espaços vazios, o que
        significa que mais espaço será ocupado
        -> não existe um fator de carga ideal, só não pode ser perto de 0
        nem de 1
*/

#include <stdio.h>
#include <stdlib.h>


/** cria a tabela hash de acordo com o tamanho que for entrado no main */
void criaHash (tipoHash *pHash, int tamanho){
    pHash = (tipoHash*) malloc(tamanho*sizeof(tipoHash));
    /** criei a tabela */
}

/** inicializa a tabela hash com todos os elementos do vetor == null
    já que não tem nenhum elemento inserido e todos os espaços do vetor
    estão vazios
*/
void inicializaHash (tipoHash *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
        pHash[i] = NULL;
    }
}

/** função hash */
int funcHash (int dado, int tamanho) {
    int funcao;
    funcao = dado%tamanho;
    return funcao;
}
/** função para calcular tamanho do vetor para facilitar outras funções */
int tamanhoHash(tipoHash *pHash) {
    int tam;
    tam = sizeof(pHash)/sizeof(int);
    return tam;
}

/** função inserir na tabela hash de forma linear */
void insereHash (tipoHash *pHash, unsigned i, int dado, int tam) {
    if(pHash[i] == NULL) {
        pHash[i] = dado;
    }
    else if(pHash[i] != NULL) {
        i++;

        if(i == tam) {
            insereHash(pHash, 0, dado); //volta pra posição 0
        } else {
            insereHash(pHash, i, dado);
        }
    }
}

/** função buscar na tabela hash e retorna verdadeiro ou falso */
int buscarHash (tipoHash *pHash, int dado) {

}

/** função deletar na tabela hash */
void removeDaHash (tipoHash *pHash, int i) {
    pHash[i] = -2; //foi removido
}

/** função de imprimir a tabela hash */
void imprimeHash (tipoHash *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
        printf("%u\n", pHash[i]);
    }
}

int main() {
    int *tabHash, tamanho, posicaoHash;
    int dado;
    scanf("%d%*c", &tamanho);

    /** criar a quantidade de espaço no vetor */
    tabHash = (int*) malloc(tamanho*sizeof(int));
    /** inicializar todos os espaços com null já que estão vazios */
    inicializaHash(tabHash, tamanho);

    scanf("%d%*c", &dado);
    while(dado.valor != 0) {
        posicaoHash = funcHash(dado, tamanho);
        insereHash(tabHash, posicaoHash, dado, tamanho);
        scanf("%d%*c", &dado);
    }
    int i = buscarHash(tabHash, dado);
    deletaHash(tabHash, i);
    imprimeHash(tabHash, tamanho);
    free(tabHash);
}
