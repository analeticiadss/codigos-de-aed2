//tabela hash questao 2 buscar

#include <stdio.h>
#include <stdlib.h>

/** inicializa a tabela hash com todos os elementos do vetor == null
    j� que n�o tem nenhum elemento inserido e todos os espa�os do vetor
    est�o vazios
*/
void inicializaHash (int *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
        pHash[i] = 0;
        /** -1 significa que t� vazio, logo, � NULL */
    }
}

/** fun��o hash */
int funcHash (int dado, int tamanho) {
    int funcao;
    funcao = dado%tamanho;
    return funcao;
}

int verificaValorRepetido (int *pHash, int tam, int dado) {
    unsigned i;
    for(i = 0; i < tam; i++) {
        if(pHash[i] == dado) {
            return 1;
        }
    }
    return -1;
}

/** fun��o inserir na tabela hash de forma linear */
void insereHash (int *pHash, unsigned i, int dado, int tam) {
    if(pHash[i] == 0) {
        pHash[i] = dado;
    }
    else if(pHash[i] != 0) {
        i++;
        if(i == tam) {
            insereHash(pHash, 0, dado, tam); //volta pra posi��o 0
        } else {
            insereHash(pHash, i, dado, tam);
        }
    }
}

/** verifica se todos os espa�os est�o ocupados */
int verificaHash (int *pHash, int tam, int dado) {
    unsigned i = 0, qtd = 0;
    while(i < tam) {
        if(pHash[i] == dado) {
            return i;
        }
       qtd++;
       i++;
    }
    /** chegou ao fim e n�o encontrou um valor igual */
    if(qtd == tam) {
        return -2; /** tabela cheia */
    }
}

int buscarHash (int *pHash, int i, int valor, int tam) {
    /** caso esteja vazio*/
    if(pHash[i] == 0) {
        return -1;
    } else if (verificaHash(pHash, tam, valor) == -2) {
        return -2;
    }
    /** caso n�o esteja vazio*/
    else if (pHash[i] != 0 && verificaHash(pHash, tam, valor) != -2) {
        if(pHash[i] == valor) {
            return i;
        } else { //caso n�o seja igual
            i++;
            if(i == tam) {
                i = 0; //volta pra posi��o 0
            }
            buscarHash(pHash, i, valor, tam);
        }
    }
}

void imprimeHash (int *pHash, int tam) {
    unsigned i;
    for(i = 0; i < tam; i++) {
        if(pHash[i] != 0) {
            printf("%u %d\n", i, pHash[i]);
        } else {
            printf("%u null\n", i);
        }
    }
}

int main() {
    int *tabHash, tamanho, posicaoHash;
    int dado;
    scanf("%d%*c", &tamanho);

    /** criar a quantidade de espa�o no vetor */
    tabHash = (int*) malloc(tamanho*sizeof(int));

    /** inicializar todos os espa�os com null j� que est�o vazios */
    inicializaHash(tabHash, tamanho);

    scanf("%d%*c", &dado);
    while(dado != 0) {
        posicaoHash = funcHash(dado, tamanho);
        if(verificaValorRepetido(tabHash, tamanho, dado) == -1) {
            insereHash(tabHash, posicaoHash, dado, tamanho);
        }
        scanf("%d%*c", &dado);
    }

    int novaPos;
    scanf("%d%*c", &dado);
    while(dado != 0) {
        posicaoHash = funcHash(dado, tamanho);
        novaPos = buscarHash(tabHash, posicaoHash, dado, tamanho);

        if(novaPos == -1) { //-1 == null
            printf("%d not found\n", dado);
        } else if (novaPos > -1) {
            printf("%d %d\n", dado, novaPos);
        }
        else if(novaPos == -2) {
            printf("%d not found\n", dado);
        }
        scanf("%d%*c", &dado);
    }
    free(tabHash);
}
