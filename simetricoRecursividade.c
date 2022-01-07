//funcao simetrica - lista tp04 - recursividade

#include <stdio.h>

int zero(int num) {
   return (num == 0);
}

int incrementa(int num) {
    return (num+1);
}

int decrementa(int num) {
    return (num-1);
}

int negativo(int num) {
    return(num < 0);
}


int simetrico(int num1, int cont) {
    if(zero(num1) || negativo(num1)) {
        if(zero(cont)) {
            return num1;
        }
        return simetrico(decrementa(num1), decrementa(cont));
    }
    return(simetrico(decrementa(num1), incrementa(cont)));
}

int main () {
    int num, cont = 0;
    scanf("%d%*c", &num);
    while(num != 0) {
        num = simetrico(num, cont);
        printf("%d\n", num);
        scanf("%d%*c", &num);
    }
}
