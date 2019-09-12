#include <stdio.h>

int main(){

    int marcas=1;
    int i,j, qtdR;
    int cont = 0;
    int resultado = 0;

    scanf("%d", &qtdR);
    
    int colecionado[qtdR];
    int vetorMarca[qtdR];
    scanf("%d", &marcas);

    if( qtdR >= 1 && qtdR <=1000 && marcas >=1 && marcas <=20)
{
    for(i=1 ; i<qtdR+1; i++){
    scanf("%d", &colecionado[i]);
    }

    for (i=1 ; i<marcas+1; i++){
    for(j=1; j< qtdR+1 ; j++){

    if(colecionado[j] == marcas) {
    cont++;
    }
    }
     vetorMarca[i] = cont;
     marcas++;
     cont=0;
    }

for (i=1 ; i<marcas+1; i++){
    resultado = resultado + vetorMarca[i];
    }

    printf("%d", resultado);
    return 0;
    } else
    
    return 0;
}