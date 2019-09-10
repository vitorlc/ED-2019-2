#include <stdio.h>

int main(){

    int numero1=0;
    int numero2=0;
    int maior = 0;
    int n1reverse = 0;
    int n2reverse = 0;
    
    scanf("%d", &numero1);
    scanf("%d", &numero2);

    if ((numero1%10) > (numero2%10)){
        maior = numero1;
    } else if ((numero1%10) < (numero2%10)) {
        maior = numero2;
    } else if ((numero1%10)==(numero2%10)){
        if ((numero1%100) > (numero2%100)){
        maior = numero1;
        } else if ((numero1%100) < (numero2%100)) {
        maior = numero2;
        } else if ((numero1%100)==(numero2%100)){
            if ((numero1%1000) > (numero2%1000)){
            maior = numero1;
            } else if ((numero1%1000) < (numero2%1000)) {
            maior = numero2;
            } 
        }
    }
    
    while (maior != 0)
    {
      n1reverse = n1reverse * 10;
      n1reverse = n1reverse + maior%10;
      maior = maior/10;
    }
    printf("%d",n1reverse);

    return 0;
}
