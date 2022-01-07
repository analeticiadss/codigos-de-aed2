//listas duplamente encadeadas TP07

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoCarta {
    int carta;
} tipoCarta;

typedef struct tipoNo {
    tipoCarta numeracao;
    struct tipoNo *proxLista, *antLista;
} tipoNo;

typedef struct tipoLista {
    tipoNo *primLista, *ultLista;
    int qtd;
} tipoLista;

void criaLista (tipoLista *pLista) {
    pLista->primLista = NULL;
    pLista->ultLista = NULL;
    pLista->qtd = 0;
}

//vai inserir no final
void insereLista (tipoLista *pLista) {
    tipoNo *aux;

    aux = (tipoNo *) malloc(sizeof(tipoNo));
    aux->numeracao.carta = ++pLista->qtd;
    aux->proxLista = NULL; //prox do primeiro elemento aponta pra NULL
    if(pLista->primLista == NULL) { //se tiver so um elemento na lista
        pLista->primLista = aux;
        pLista->ultLista = aux;
        aux->antLista = NULL; //anterior do primeiro elemento == NULL
    } else { //se tiver mais de um elemento na lista
        pLista->ultLista->proxLista = aux; //o antigo aux q tinha proxLista == NULL, agora aponta p novo aux
        aux->antLista = pLista->ultLista; //aponta pro antigo ultimo
        pLista->ultLista = aux;
    }
}

int retiraCarta (tipoLista *pLista) {
    tipoNo *aux, *temp, *topo;
    temp = pLista->primLista;

    if(temp->proxLista == NULL) {
        printf("\n");
        printf("Restou: %d\n", temp->numeracao.carta);
    }

    while(temp->proxLista != NULL) {
        aux = pLista->primLista;

        //RETIRANDO A PRIMEIRA CARTA DO TOPO
        if(aux->proxLista->proxLista != NULL) {
            printf("%d, ", aux->numeracao.carta);
        } else {
            printf("%d\n", aux->numeracao.carta);
        }



        temp = temp->proxLista; //temp agora eh temp->prox
        free(aux); //libera o pLista->prim


        //REALOCANDO A CARTA PRO FIM
        if(temp->proxLista != NULL) {
            pLista->primLista = temp->proxLista;
            temp->proxLista->antLista = NULL;
            pLista->ultLista->proxLista = temp; //antigo ult->prox eh null entao agr o ult->prox eh aux

            temp->antLista = pLista->ultLista; //aux->ant vai ser o antigo ult
            pLista->ultLista = temp;
            pLista->ultLista->proxLista = NULL;
        } else {
            printf("Restou: %d\n", temp->numeracao.carta);
            return 0;
        }
        temp = pLista->primLista;
    }


}

int main () {
    tipoLista lista;
    int num;

    scanf("%d%*c", &num);

    while(num != 0) {
        criaLista(&lista);

            for(unsigned i = 0; i < num; i++) {
               insereLista(&lista);
            }
            printf("Descartadas: ");
            retiraCarta(&lista);

        scanf("%d%*c", &num);

    }
}
