//tabelas hash

#include <stdio.h>
#include <stdlib.h>

/** inicializa a tabela hash com todos os elementos do vetor == null
    já que não tem nenhum elemento inserido e todos os espaços do vetor
    estão vazios
*/
void inicializaHash (int *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
        pHash[i] = 0;
        /** -1 significa que tá vazio, logo, é NULL */
    }
}

/** função hash */
int funcHash (int dado, int tamanho) {
    int funcao;
    funcao = dado%tamanho;
    return funcao;
}

/** função inserir na tabela hash de forma linear */
void insereHash (int *pHash, unsigned i, int dado, int tam) {
    if(pHash[i] == 0) {
        pHash[i] = dado;
    }
    else if(pHash[i] != 0) {
        i++;
        if(i == tam) {
            insereHash(pHash, 0, dado, tam); //volta pra posição 0
        } else {
            insereHash(pHash, i, dado, tam);
        }
    }
}

void imprimeHash (int *pHash, int tam) {
    unsigned i;
    for(i = 0; i < tam; i++) {
        if(pHash[i] != 0) {
            printf("%u %u\n", i, pHash[i]);
        } else {
            printf("%u null\n", i);
        }
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
    while(dado != 0) {
        posicaoHash = funcHash(dado, tamanho);
        insereHash(tabHash, posicaoHash, dado, tamanho);
        scanf("%d%*c", &dado);
    }
    imprimeHash(tabHash, tamanho);
    free(tabHash);
}
