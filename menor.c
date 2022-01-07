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

int menor(int numero1, int numero2) { //se o numero1 < numero2, numero1 chega em 0 mais rapido
   if(zero(numero1) == 1) {
        return 1;
   }
   if(zero(numero2) == 1) {
        return 0;
   }

   return menor(decrementa(numero1),decrementa(numero2));
}

int main () {
    int num1, num2;
    scanf("%d%*c %d%*c", &num1, &num2);
    while(num1 != 0 && num2 != 0) {
        if(num1 == num2) {
            printf("NAO\n");
        }
        else if(menor(num1, num2) == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        scanf("%d%*c %d%*c", &num1, &num2);
    }
}
