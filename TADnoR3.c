//aed 2 - TAD de um ponto no R3 - implementando o tad
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad.h"

typedef struct tipoPonto {
    float x, y, z;
} tipoPonto;

tipoPonto* cria (float x, float y, float z) {
    tipoPonto *ponto;
    ponto = (tipoPonto*) malloc(sizeof(tipoPonto)); //criei um espaco pro ponto
    if(ponto == NULL) {
        printf("erro ao alocar memoria\n");
        exit(1);
    }
    //criando o Ponto1
    ponto->x = x;
    ponto->y = y;
    ponto->z = z;

    return ponto;
}

void acessa(tipoPonto *ponto, float *x, float *y, float *z) {
    *x = ponto->x; //conteudo de x eh valor armazenado no endereco apontado por ponto
    *y = ponto->y;
    *z = ponto->z;
}

void atribui(tipoPonto *ponto, float x, float y, float z){
    ponto->x = x; //ponto->x recebe o valor de x
    ponto->y = y;
    ponto->z = z;
}

void distancia(tipoPonto *ponto1, tipoPonto *ponto2) {
    float distancia, x1, x2, y1, y2, z1, z2;
    x1 = ponto1->x;
    x2 = ponto2->x;

    y1 = ponto1->y;
    y2 = ponto2->y;

    z1 = ponto1->z;
    z2 = ponto2->z;

    distancia = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
    printf("%.2f\n", distancia);
}
