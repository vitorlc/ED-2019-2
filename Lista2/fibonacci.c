#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n);

int main(){
    int qtd , i;

    scanf("%d", &qtd);
    for (i=-1; i<qtd; i++){
        printf("%d ",fibonacci(i+1));
    }

    return 0;
}

int fibonacci (int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else {
        return (fibonacci (n - 1)+fibonacci (n - 2));
    }
}
