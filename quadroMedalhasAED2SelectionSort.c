//quadro de medalhas selection sort - aed2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPais {
    char pais[20];
    int medOuro, medPrata, medBronze;
} tipoPais;

void reatribuindoValor(tipoPais *vet, int i, int posMaior) {
    int guardaOuro, guardaPrata, guardaBronze;
    char nome[20];

    guardaOuro = vet[i].medOuro;
    guardaPrata = vet[i].medPrata;
    guardaBronze = vet[i].medBronze;
    strcpy(nome, vet[i].pais);

    vet[i].medOuro = vet[posMaior].medOuro; //trocou os valores
    vet[i].medPrata = vet[posMaior].medPrata;
    vet[i].medBronze = vet[posMaior].medBronze;
    strcpy(vet[i].pais, vet[posMaior].pais);

    vet[posMaior].medOuro = guardaOuro;
    vet[posMaior].medPrata = guardaPrata;
    vet[posMaior].medBronze = guardaBronze;
    strcpy(vet[posMaior].pais, nome);
}

void ordenacaoPorSelecao(tipoPais *vet, int tam) {
	unsigned i, cont, posMaior;
    char nome[20];

	/*não pode usar i na comparacao vet[cont] < vet[i]
 	porque no fim ficaria vet[i] > vet[i] */

	for(i = 0; i < tam -1; i++) {
		posMaior = i;
	//inicio o vetor, pego a primeira posicao para comparar com as seguintes
			for(cont = i+1; cont < tam; cont++) {
				//seleciono o resto do vetor e vejo quem é o menor
				if(vet[cont].medOuro > vet[posMaior].medOuro) {
					//o que for menor, eu pego a sua posicao
					posMaior = cont;
				} else if (vet[cont].medOuro == vet[posMaior].medOuro) {
                    if(vet[cont].medPrata > vet[posMaior].medPrata) {
                        posMaior = cont;
                    } else if(vet[cont].medPrata == vet[posMaior].medPrata) {
                        if(vet[cont].medBronze > vet[posMaior].medBronze) {
                            posMaior = cont;
                        } else if (vet[cont].medBronze == vet[posMaior].medBronze) {
                            if(vet[cont].pais > vet[posMaior].pais) {
                                posMaior = cont;
                            }
                        }
                    }
				}
			}
	/*se o primeiro elemento do vetor for
	 menor que o maior elemento no vetor inteiro,
	 eu troco os valores para que o maior elemento esteja
	 na primeira posição do vetor */
		if(vet[i].medOuro < vet[posMaior].medOuro) {
			reatribuindoValor(vet, i, posMaior);
		} else if (vet[i].medOuro == vet[posMaior].medOuro) {
            if(vet[i].medPrata < vet[posMaior].medPrata) {
                reatribuindoValor(vet, i, posMaior);
            } else if(vet[i].medPrata == vet[posMaior].medPrata) {
                if(vet[i].medBronze < vet[posMaior].medBronze) {
                    reatribuindoValor(vet, i, posMaior);
                } else if(vet[i].medBronze == vet[posMaior].medBronze) {
                    if(vet[i].pais[0] > vet[posMaior].pais[0]) {
                        strcpy(nome, vet[i].pais);
                        strcpy(vet[i].pais, vet[posMaior].pais);
                        strcpy(vet[posMaior].pais, nome);
                    }
                }
            }
        }

	}
}

void mostraHash (tipoPais *vet, int tam) {
	unsigned cont;

	for (cont = 0; cont < tam; cont++) {
		printf("%s %d %d %d\n", vet[cont].pais, vet[cont].medOuro, vet[cont].medPrata, vet[cont].medBronze);
	}
}

int main() {
    int num; //numero de países
    scanf("%d%*c", &num);

    tipoPais *tabHash;
    tabHash = (tipoPais*) malloc(num*sizeof(tipoPais));

    tipoPais dado;

    if(num >= 0 && num <= 50) {
        if(num == 0) {
            return 0;
        }
        for(int i = 0; i < num; i++) {
            scanf("%s%*c %d%*c", tabHash[i].pais, &tabHash[i].medOuro);
            scanf("%d%*c %d%*c", &tabHash[i].medPrata, &tabHash[i].medBronze);
        }
    }
    ordenacaoPorSelecao(tabHash, num);
    mostraHash(tabHash, num);
    free(tabHash);
}
