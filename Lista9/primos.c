#include <stdio.h>

int primo(int num);

int main(){

    int i, x, y, val, cont = 0;
    scanf("%d", &x);

    scanf("%d", &y);

    for (i = x; i < y + 1; i++){
        val = primo(i);
        if (val != 0){
            cont++;
        }
    }

    printf("%d", cont);
}

int primo(int num){

    int i, resultado = 0, cont = 1;

    if (num == 1){
        return 0;
    }

    for (i = 2; i <= num / 2; i++){
        if (num % i == 0 || num == 1){
            resultado++;
            break;
        }
    }

    if (resultado == 0){
        return 1;
    }
    else{
        return 0;
    }
}