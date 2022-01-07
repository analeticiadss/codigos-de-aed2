//tp05 - listas e vetor encadeadas - aed2 - questao1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoDados {
    char nome[15];
    char endereco[20];
    float altura;
} tipoDados;

typedef struct tipoNo {
    tipoDados dados;
    struct tipoNo *proxLista;
} tipoNo;

typedef struct tipoLista {
    tipoNo *primLista;
} tipoLista;

void criaLista(tipoLista *pLista) {
    pLista->primLista = NULL;
}

void insereElementoLista(tipoLista *pLista, tipoDados *dados) {
    tipoNo *aux;

    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->dados = *dados;
    aux->proxLista = pLista->primLista;
    pLista->primLista = aux;
}

float media(tipoLista *pLista) {
    tipoNo *aux;
    float somaAltura = 0, qtd = 0;

    aux = pLista->primLista;
    while(aux != NULL) {
        qtd++;
        somaAltura += aux->dados.altura;
        aux = aux->proxLista;
    }
    printf("%.2f\n", somaAltura/qtd);
}

int main() {
    tipoLista lista1;
    tipoDados dados;
    int qtd = 0;

    criaLista(&lista1);
    while(1) {
        scanf("%[^\n]%*c", dados.nome); //nome
        qtd++;
        if(strcmp(dados.nome, "XXX") == 0){
                if(qtd == 1) {
                    return 0;
                }
                return media(&lista1);
        }
        scanf("%[^\n]%*c", dados.endereco);  //endereco da pessoa
        scanf("%f%*c", &dados.altura); //altura da pessoa

        insereElementoLista(&lista1, &dados);
    }
    return 0;
}
