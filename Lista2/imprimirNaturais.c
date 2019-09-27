#include <stdio.h>

void imprimeNaturais(int prim, int ult);

int main(){
    int n = 1, m = 1;
    scanf("%d", &m);
    imprimeNaturais(n, m);
    return 0;
}

void imprimeNaturais (int prim, int ult){
    if (prim <= ult){
        printf("%i ",  prim);
        return imprimeNaturais (prim +1, ult);
    }
    return ;
}
