//funcao soma - lista tp04 - recursividade

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

int menor(int numero1, int numero2) { //se o numero1 < numero2, numero1 chega em 0 mais rapido
   if(zero(numero1)) {
        return 1;
   }
   if(zero(numero2)) {
        return 0;
   }

   return menor(decrementa(numero1),decrementa(numero2));
}

int igual(int num1, int num2) {
    if(zero(num1)) {
        if(zero(num2)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if(zero(num2)) {
        return 0;
    }
    return igual(decrementa(num1), decrementa(num2));
}

int diferente(int num1, int num2) {
    if(igual(num1, num2)) { //se for verdade
        return 0;
    }
    return 1;
}

int soma(int num1, int num2) {
    if(zero(num2)) {
        return num1;
    }
    return soma(incrementa(num1), decrementa(num2));
}

int main () {
    int num1, num2;
    scanf("%d%*c %d%*c", &num1, &num2);
    while(num1 != 0 && num2 != 0) {
        printf("%d\n", soma(num1, num2));

        scanf("%d%*c %d%*c", &num1, &num2);
    }
}
