#include <stdio.h>

int main(){

    int N = 0, N1 = 0, N2 = 0, resultado;
    char C;

    scanf("%d", &N);
    scanf("%d %c %d", &N1, &C, &N2);
    
    if(C == 'x'){
        resultado = N1*N2;
        if (resultado>N)
            printf("overflow");
        else
            printf("no overflow");
    }else {
        resultado = N1+N2;
        if (resultado>N)
            printf("overflow");
        else
            printf("no overflow");
    }        
    return 0;
}

