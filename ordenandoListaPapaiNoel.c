//lista do papai noel aed2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoCrianca {
    char nome[20];
    char comportamento;
} tipoCrianca;

void quickSortR(tipoCrianca *vet, int inicio, int fim) {
	char pivot[20];
	char guardaNome[20], guardaComportamento;
	int i, j;

	if(inicio < fim) {
		strcpy(pivot, vet[(inicio+fim)/2].nome); //divide o vetor ao meio
		i = inicio;
		j = fim;

		while(i <= j) {
			while(strcasecmp(vet[i].nome, pivot) < 0) { //elementos menores que o pivot
				i++;
			}
			while(strcasecmp(vet[j].nome, pivot) > 0) {//elementos maiores que o pivot
				j--;
			}

		/* só vai acontecer o if se não entrar nos whiles, ou seja,
		se vet[i] > pivot ou vet[j] < pivot	*/
			if(i <= j) {
				strcpy(guardaNome, vet[i].nome);
				guardaComportamento = vet[i].comportamento;

				strcpy(vet[i].nome, vet[j].nome);
				vet[i].comportamento = vet[j].comportamento;

				strcpy(vet[j].nome, guardaNome);
				vet[j].comportamento = guardaComportamento;
				i++;
				j--;
			}
		}
		quickSortR(vet, inicio, j);
		quickSortR(vet, i, fim);
	}
}

void quickSort(tipoCrianca *vet, int tamVet) {
	quickSortR(vet, 0, tamVet-1);
}

void mostraVetor(tipoCrianca *vet, int tamVet) {
	int cont;
	for(cont = 0; cont < tamVet; cont++) {
		printf("%s\n", vet[cont].nome);
	}
}

int main() {
    int qtd;
    scanf("%d%*c", &qtd);

    tipoCrianca *vet;
    vet = (tipoCrianca*) malloc(qtd*sizeof(tipoCrianca));
    int simComportada = 0, naoComportada = 0;

    for (int i = 0; i < qtd; i++) {
        scanf("%c%*[\t] %[^\n]%*c", &vet[i].comportamento, vet[i].nome);
    }

    for (int j = 0; j < qtd; j++) {
        if(vet[j].comportamento == '+') {
            simComportada++;
        } else {
            naoComportada++;
        }
    }
    quickSort(vet, qtd);
    mostraVetor(vet, qtd);
    printf("Se comportaram: %d | Nao se comportaram: %d\n", simComportada, naoComportada);
    free(vet);
}
