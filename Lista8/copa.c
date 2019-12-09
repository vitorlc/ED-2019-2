#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila Fila;
struct fila{
    int identificador;
    Fila *prox;
};

Fila * adicionarPessoasFila(Fila *fila, int identificador);

Fila* buscarPessoa(Fila* Lista, int identificador);

Fila* removerPessoaFila(Fila *fila, int identificador);

void imprimirFila(Fila *fila);

int main(){
    Fila *InicioFila = NULL;
    int qtd_pessoas= 0, qtd_deixaram=0, i, j, k;

    scanf("%d", &qtd_pessoas);
    int identificadores[qtd_pessoas];

    for(k = 1;k <=qtd_pessoas; k++){
        scanf("%d", &identificadores[k]);
        InicioFila = adicionarPessoasFila(InicioFila, identificadores[k]);
    }


    //REMOVER'
    scanf("%d", &qtd_deixaram);
    int identificadores_deixaram[qtd_deixaram];

    for(i = 1;i <=qtd_deixaram; i++){
        scanf("%d", &identificadores_deixaram[i]);
    }
    for(i = 1;i <=qtd_pessoas; i++){
        for(j = 1;j <=qtd_deixaram; j++){
            if(identificadores[i] == identificadores_deixaram[j]){
                InicioFila = removerPessoaFila(InicioFila, identificadores_deixaram[j]);
            }
        }
    }

    imprimirFila(InicioFila);

    return 0;
}


Fila * adicionarPessoasFila(Fila *fila, int identificador){
    Fila *pessoa = (Fila*)malloc(sizeof(Fila));
    pessoa->identificador = identificador;
    pessoa->prox = NULL;
    
    if(fila == NULL){
        fila = pessoa;
    }else {
        Fila *temp;
        temp = fila;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = pessoa;
    }
    return fila;
}

Fila* buscarPessoa(Fila* Lista, int identificador){
    Fila* temp = Lista;
    while (temp->identificador != identificador){
        temp = temp->prox;
    }
    return temp;
}


Fila* removerPessoaFila(Fila *fila, int identificador){
    Fila* temp = buscarPessoa(fila, identificador);

    Fila* anterior;
    anterior = fila;
    if (anterior == temp){
        fila = anterior->prox;
        free(temp);
        return fila;
    }else {
        while (anterior->prox != temp ){
            anterior = anterior->prox;
        }
        anterior->prox = temp->prox;
        free(temp);
        return fila;
    }
}

void imprimirFila(Fila *fila){
    Fila* aux = fila;
    while(aux !=NULL){
        // printf("\n\nEndereco: %p\n Valor: %d \nProx: %p", aux,aux->identificador, aux->prox);
        printf("%d ",aux->identificador);
        // printf("\n\nEndereco: %p \nIdentificador:%d \nProx: %p", aux, aux->identificador, aux->prox);
        aux=aux->prox;
    }
    printf("\n");
}