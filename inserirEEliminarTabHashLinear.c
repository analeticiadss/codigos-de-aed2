//inser��o e elimina��o de tabelas hash de forma linear

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoDado {
    int matricula, original;
    char nome[20];
} tipoDado;

typedef struct tipoHash {
    tipoDado dado;
} tipoHash;

/** inicializa a tabela hash com todos os elementos do vetor == null
    j� que n�o tem nenhum elemento inserido e todos os espa�os do vetor
    est�o vazios
*/
void inicializaHash (tipoHash *pHash, int tamanho) {
    unsigned i;
    for(i = 0; i < tamanho; i++) {
        pHash[i].dado.matricula = 0;
        strcpy(pHash[i].dado.nome, "NULL");
        pHash[i].dado.original = -1;
        /** -1 significa que t� vazio, logo, � NULL */
    }
}

/** fun��o hash */
int funcHash (int dado, int tamanho) {
    int funcao;
    funcao = dado%tamanho;
    return funcao;
}

/** fun��o inserir na tabela hash de forma linear */
void insereHash (tipoHash *pHash, unsigned i, tipoDado *dado, int tam) {
    if(pHash[i].dado.matricula == 0) {
        pHash[i].dado = *dado;
    }
    else if(pHash[i].dado.matricula != 0) {
        i++;
        if(i == tam) {
            insereHash(pHash, 0, dado, tam); //volta pra posi��o 0
        } else {
            insereHash(pHash, i, dado, tam);
        }
    }
}

int buscarHash (tipoHash *pHash, int i, int valor, int tam) {
    /** caso esteja vazio*/
    if(pHash[i].dado.matricula == 0) {
        return -1;
    }
    /** caso n�o esteja vazio*/
    else {
        if(pHash[i].dado.matricula == valor) {
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

void deletaHash (tipoHash *pHash, int i) {
    pHash[i].dado.matricula = 0; //esvazia a posi��o da tabela == null
    strcpy(pHash[i].dado.nome, "NULL");
    pHash[i].dado.original = -2; //foi removido
}

void reorganizaHash (tipoHash *pHash, int tam) {
    int indice, i, numOriginal;

    for(i = 0; i < tam; i++) {
        /** se o original estiver em outra posi��o que n�o a dele */
        if(pHash[i].dado.original != i) {
            indice = pHash[i].dado.original; //posi��o que deveria estar

            if(pHash[indice].dado.original == -2) {
                pHash[indice].dado.matricula = pHash[i].dado.matricula;
                strcpy(pHash[indice].dado.nome, pHash[i].dado.nome);
                pHash[indice].dado.original = pHash[i].dado.original;
                deletaHash(pHash, i);
            }
            else {
                /** se estiver ocupado */
                if(pHash[indice].dado.original > -1) {
                    indice++;
                /** se estiver dispon�vel a posi��o depois do indice */
                    if(pHash[indice].dado.original == -2) {
                        pHash[indice].dado.matricula = pHash[i].dado.matricula;
                        strcpy(pHash[indice].dado.nome, pHash[i].dado.nome);
                        pHash[indice].dado.original = pHash[i].dado.original;
                        deletaHash(pHash, i);
                    }
                }
            }
        }
    }
}


void imprimeHash (tipoHash *pHash, int tam) {
    unsigned i;
    for(i = 0; i < tam; i++) {
        if(pHash[i].dado.matricula != 0) {
            printf("%u %d %d\n", i, pHash[i].dado.matricula, pHash[i].dado.original);
        } else {
            printf("%u \\\n", i);
        }
    }
}

int main() {
    int posicaoHash;
    int tamanho, qtdChaves;
    tipoHash *tabHash;
    tipoDado dado;

    scanf("%d%*c", &tamanho); /** tamanho da tabela hash */

    /** criar a tabela Hash */
    tabHash = (tipoHash*) malloc(tamanho*sizeof(tipoHash));

    /** qtd de chaves da tabela hash */
    scanf("%d%*c", &qtdChaves);

    while(qtdChaves != 0) {
        scanf("%d%*c", &dado.matricula); /** matricula � a chave inserida */
        scanf("%[^\n]%*c", &dado.nome);

        posicaoHash = funcHash(dado.matricula, tamanho);
        dado.original = posicaoHash;
        insereHash(tabHash, posicaoHash, &dado, tamanho);
        qtdChaves--;
    }
    imprimeHash(tabHash, tamanho);

    /** qtd de chaves da tabela hash que ser�o removidas */
    scanf("%d%*c", &qtdChaves);

    while(qtdChaves != 0) {
        scanf("%d%*c", &dado.matricula);
        posicaoHash = funcHash(dado.matricula, tamanho);

        /**encontrar a posi��o na fun��o de busca*/
        int i = buscarHash(tabHash, posicaoHash, dado.matricula, tamanho);

        /** se i for diferente de nulo */
        if(i != -1) {
            deletaHash(tabHash, i);
        }

        /** precisa reorganizar a partir do primeiro inserido, pro caso
        de ter ocorrido colis�es */
        reorganizaHash(tabHash, tamanho);

        qtdChaves--;
    }
    imprimeHash(tabHash, tamanho);

    /** qtd de chaves da tabela hash que ser�o buscadas */
    scanf("%d%*c", &qtdChaves);

    while(qtdChaves != 0) {
        scanf("%d%*c", &dado.matricula);
        posicaoHash = funcHash(dado.matricula, tamanho);
        int i = buscarHash(tabHash, posicaoHash, dado.matricula, tamanho);

        if(i != -1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        qtdChaves--;
    }
}
