#include <stdio.h>
int buscaBinRec(int vetor[], int ini, int fim, int pesq){
    while (ini <= fim)
    {
        int meio;
        meio = (ini + fim) / 2;
        if (vetor[meio] == pesq)
        {
            return meio;
        }
        else if (vetor[meio] < pesq)
        {
            return buscaBinRec(vetor, meio + 1, fim, pesq);
        }
        else
        {
            return buscaBinRec(vetor, ini, meio - 1, pesq);
        }
    }
    return -1;
}

int main(){
    
    int v[50],i=0, j=0, t=0, k=0, fun, x;
    int count=0, tam = 0, vRespostas[30];
    scanf("%d", &t);

    for(i=0; i<t; i++){
        scanf("%d", &x);
        for(j=0;j<30;j++){
            scanf("%d", &v[j]);
            count ++;
            if(v[j]==-1){
                tam=count;
                break;
            }
        }
        vRespostas[i] = buscaBinRec(v, 0, tam - 1, x);
    }
    
    // printf("\nTamanho Vetor: %d\n", tam);
    // for(i=0; i<tam; i++){
    //     printf("%d ", v[i]);
    // }
    // printf("\nPesquisar por: %d\n", x);

    for(i=0; i<t; i++){
        if(vRespostas[i]==-1){
            printf("\nausente");

        }else{
            vRespostas[i] = vRespostas[i] +1;
            printf("\n%d", vRespostas[i]);
        }
    }

    return 0;
}