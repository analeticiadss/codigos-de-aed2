//funcao igual aed2 - lista tp04 - recursividade

//AED II - lista TP04 - recursividade - questao 1

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
    if(zero(num1) {
        if(zero(num2)) {
            return 1;
        }
        return 0;
    }
    if(zero(num2) == 1) {
        return 0;
    }
    return igual(decrementa(num1), decrementa(num2));
}

int main () {
    int num1, num2;
    scanf("%d%*c %d%*c", &num1, &num2);
    while(num1 != 0 && num2 != 0) {
        if(igual(num1, num2) == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        scanf("%d%*c %d%*c", &num1, &num2);
    }
}
