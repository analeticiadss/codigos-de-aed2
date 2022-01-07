//funcao diferenca - lista tp04 - recursividade

#include <stdio.h>

int zero(int numero) {
   return (numero == 0);
}

int incrementa(int numero) {
    return (numero+1);
}

int decrementa(int numero) {
    return (numero-1);
}

int igual(int num1, int num2) {
    if(zero(num1) == 1) {
        if(zero(num2) == 1) {
            return 1;
        }
        return 0;
    }
    if(zero(num2) == 1) {
        return 0;
    }
    return igual(decrementa(num1), decrementa(num2));
}

int diferente(int num1, int num2) {
    if(igual(num1, num2) == 1) {
        return 0;
    }
    return 1;
}

int main () {
    int num1, num2;
    scanf("%d%*c %d%*c", &num1, &num2);
    while(num1 != 0 && num2 != 0) {
        if(diferente(num1, num2) == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        scanf("%d%*c %d%*c", &num1, &num2);
    }
}
