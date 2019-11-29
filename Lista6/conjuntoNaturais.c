#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int elementos[50];
}conjunto;


// criar um conjunto C, inicialmente vazio:
int criaConjunto(C);

// verificar se o conjunto C é vazio:
int conjuntoVazio(C);

// incluir o elemento x no conjunto C:
int insereElementoConjunto(x, C);

// excluir o elemento x do conjunto C:
int excluirElementoConjunto(x, C);

// calcular a cardinalidade do conjunto C:
int tamanhoConjunto(C);

// determinar a quantidade de elementos do conjunto C que são maiores que x:
int maior(x, C);

// determinar a quantidade de elementos do conjunto C que são menores que x:
int menor(x, C);

// verificar se o elemento x pertence ao conjunto C:
int pertenceConjunto(x, C);

// comparar se dois conjuntos, C1 e C2 são idênticos:
int conjuntosIdenticos(C1, C2);

// identificar se o conjunto C1 é subconjunto do conjunto C2:
int subconjunto(C1, C2);

// gerar o complemento do conjunto C1 em relação ao conjunto C2:
Conjunto complemento(C1, C2);

// gerar a união do conjunto C1 com o conjunto C2:
Conjunto uniao(C1, C2);

// gerar a intersecção do conjunto C1 com o conjunto C2:
Conjunto interseccao(C1, C2);

// gerar a diferença entre o conjunto C1 e o conjunto C2:
Conjunto diferenca(C1, C2);

// gerar o conjunto das partes do conjunto C:
Conjunto conjuntoPartes(C);

mostrar os elementos presentes no conjunto C:
void mostraConjunto(C, ordem);

// copiar o conjunto C1 para o conjunto C2:
int copiarConjunto(C1, C2);

// destruir o conjunto C:
int destroiConjunto(C);



int main(){
    int n, i;
    scanf("%d", &n);
    
    Conjunto c1[n];
    Conjunto c2[n];
    for(i = 0; i < n; ++i){
        printf("\nDigite os elementos do conjunto 1: ");
        scanf("%d", &(c1[i]));
    }
    for(i = 0; i < n; ++i){
        printf("Digite o elementos do conjunto 2: ");
        scanf("%d", &(c2[i]));
    }

    for(i = 0; i < n; ++i){
        printf("\nConjunto 1: ");
        printf("%d ", c1[i]);
    }
    
    for(i = 0; i < n; ++i){
        printf("\nConjunto 2: ");
        printf("%d ", c2[i]);
    }
    
    return 0;
}
