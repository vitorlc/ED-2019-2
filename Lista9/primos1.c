#include <stdio.h>
#include <stdlib.h>

int retornaPrimo(int num);

int main (){
    int n=0, x=0, y=0, i=0, count=0, var_primo;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);

    for (i=2; i<=n; i++){
        var_primo = retornaPrimo(i);
        if(var_primo != 0)
            count++;
        if(count>=x && count<=y && var_primo!=0){
            printf("%d ", var_primo);
        }
    }

}

int retornaPrimo(int num){

    int i=0, resultado = 0;

    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            resultado++;
            break;
        }
    }

    if (resultado == 0)
    {
        return num;
    }
    else
        return 0;
}