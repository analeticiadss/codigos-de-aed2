//multiplicacao recursividade - lista tp04 - aed2

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

int soma(int num1, int num2) {
    if(zero(num2)) {
        return num1;
    }
    return soma(incrementa(num1), decrementa(num2));
}


int multiplica(int num1, int num2) {
    num1 = decrementa(num1);
    if(zero(num1)) {
        return num2;
    }
    return soma(num2,multiplica(num1, num2));
}

int main () {
    int num1, num2;
    scanf("%d%*c %d%*c", &num1, &num2);
    while(num1 != 0 && num2 != 0) {
        printf("%d\n", multiplica(num1, num2));
        scanf("%d%*c %d%*c", &num1, &num2);
    }
}
