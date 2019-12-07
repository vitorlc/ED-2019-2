#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato Contato;
struct contato{
    char nome[10];
    int telefone;
    int qtd_ligacao;
    Contato *proxContato;
};

Contato* lista = NULL; //lista vazia

//cria contato
Contato* criaContato();

//Inserir novo contato
Contato* insereContato(Contato *prox, char nome[], int telefone, int qtd_ligacao);

//Remover contato da lista
void removerContato(Contato *lista, char nome[]);

//Registrar quem da lista de contatos existente, fez uma ligação
void registraLigacao(char nome);

//Ordenar lista por quem ligou mais vezes
void ordenaListaQtdLigacao(Contato *c);

void imprimir(Contato *Lista);

Contato* buscarContato(Contato* Lista, char nome[]);

int main (){
    char tipo, nome[10]; 
    int telefone = 0; 
    int qtd_ligacao = 0;

    strcpy(nome, "Nome1");
    lista = insereContato(lista, nome, 111111111, 4);
    strcpy(nome, "Nome2");
    lista = insereContato(lista, nome, 222222222, 3);
    strcpy(nome, "Nome3");
    lista = insereContato(lista, nome, 333333333, 2);
    strcpy(nome, "Nome4");
    lista = insereContato(lista, nome, 444444444, 1);
    strcpy(nome, "Nome5");
    lista = insereContato(lista, nome, 555555555, 5);
    imprimir(lista);

    // strcpy(nome, "Nome1");
    // removerContato(lista, nome);

    // printf("\n\n NOVA LISTA \n\n");
    // imprimir(lista);
    // printf("\n\n TEMP: %s %d %d", temp->nome, temp->telefone, temp->qtd_ligacao);

    // do{
    //     tipo = getchar();
        
    //     // scanf("%s %d %d", &nome, &telefone, &qtd_ligacao);
    //     // printf("%c %s %d %d",tipo, nome, telefone, qtd_ligacao);
    //     switch(tipo)
    //     {
    //         case 'I':
    //         printf("\nINSERE\n");
    //         scanf("%s %d %d", &nome, &telefone, &qtd_ligacao);
    //         lista = insereContato(lista ,nome, telefone, qtd_ligacao);
    //         break;

    //         case 'R':
    //         printf("\nREMOVE");
    //         break;

    //         case 'L':
    //         printf("\nLIGAÇÃO");
    //         break;

    //     }
    // }while(tipo!='F');
    
    // imprimir(lista);


    return 0;
};

Contato* criaContato(){
    Contato *contato = (Contato*)malloc(sizeof(Contato));
    return contato;
}

Contato* insereContato(Contato *Lista, char nome[], int telefone, int qtd_ligacao){
    Contato *contato = criaContato(); 

    strcpy(contato->nome,nome);
    contato->telefone = telefone;
    contato->qtd_ligacao = qtd_ligacao;
    contato->proxContato = NULL;

    if(Lista == NULL){
        Lista = contato;
    }else{ 
        Contato *temp;
        temp = Lista;
        if(Lista->qtd_ligacao<= contato->qtd_ligacao){
            contato->proxContato = Lista;
            Lista = contato;
            return Lista;
        }           
        while(temp->proxContato != NULL){
            if(temp->qtd_ligacao <= contato->qtd_ligacao){
                contato->proxContato = temp->proxContato;
                break;
            }
            temp = temp->proxContato;
        }
        temp->proxContato = contato;
    }

    return Lista;
}

Contato* buscarContato(Contato* Lista, char nome[]){
    Contato* temp = Lista;
    while (strcmp(temp->nome, nome) != 0){
        temp = temp->proxContato;
    }
    
    return temp;
}

void removerContato(Contato *Lista, char nome[]){

    Contato *temp = buscarContato(lista, nome);

    Contato *anteriorTemp;
    anteriorTemp = lista;
    while( anteriorTemp->proxContato != temp ){
        anteriorTemp = anteriorTemp->proxContato;
    }

    anteriorTemp->proxContato = temp->proxContato;
    free(temp);
}

void registraLigacao(char nome){

}

void ordenaListaQtdLigacao(Contato *Lista){

}

void imprimir(Contato *Lista){
    Contato* aux = Lista;
    while(aux !=NULL){
         printf("\n\nEndereco: %p \nNome: %s \nTelefone: %d \nQtd ligacao: %d \nProx: %p",aux, aux->nome, aux->telefone, aux->qtd_ligacao, aux->proxContato);
         aux=aux->proxContato;
    }
}