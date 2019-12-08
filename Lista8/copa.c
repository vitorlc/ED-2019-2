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

void removerPessoaFila(Fila *fila, int identificador);

void imprimirFila(Fila *fila);

int main(){
    Fila *InicioFila = NULL;
    int qtd_pessoas= 0, qtd_deixaram=0, i, j;

    scanf("%d", &qtd_pessoas);
    int identificadores[qtd_pessoas];

    for(i = 1;i <=qtd_pessoas; i++){
        scanf("%d", &identificadores[i]);
        InicioFila = adicionarPessoasFila(InicioFila, identificadores[i]);
    }


    //REMOVER'
    scanf("%d", &qtd_deixaram);
    int identificadores_deixaram[qtd_deixaram];

    for(i = 1;i <=qtd_deixaram; i++){
        scanf("%d", &identificadores_deixaram[i]);
    }
    for(i = 1;i <=qtd_pessoas; i++){
        for(j = 1;j <=qtd_deixaram; j++){
            if(identificadores[i]==identificadores_deixaram[j]){
                removerPessoaFila(InicioFila, identificadores_deixaram[i]);
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


void removerPessoaFila(Fila *fila, int identificador){
    Fila* temp = buscarPessoa(fila, identificador);

    Fila* anterior;
    anterior = fila;
    while (anterior->prox != temp ){
        anterior = anterior->prox;
    }
    anterior->prox = temp->prox;
    free(temp);
}

void imprimirFila(Fila *fila){
    Fila* aux = fila;
    while(aux !=NULL){
        // printf("\n\nEndereco: %p\n Valor: %d \nProx: %p", aux,aux->identificador, aux->prox);
        printf("%d ",aux->identificador);
        aux=aux->prox;
    }
    printf("\n");
}