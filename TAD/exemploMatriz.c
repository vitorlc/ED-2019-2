#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h>  /* printf */

typedef struct matriz{
    int linha;
    int coluna;
    float *v;
} Matriz;

/* Funções Exportadas */

/* Função cria - Aloca e retorna matriz m por n */
Matriz* cria (int m, int n);
/* Função libera - Libera a memória de uma matriz */
void libera (Matriz* mat); 
/* Função acessa - Retorna o valor do elemento [i][j] */
float acessa (Matriz* mat, int i, int j);
/* Função atribui - Atribui valor ao elemento [i][j] */
void atribui (Matriz* mat, int i, int j, float v);
/* Função linhas - Retorna o no. de linhas da matriz */
int linhas (Matriz* mat);
/* Função colunas - Retorna o no. de colunas da matriz */
int colunas (Matriz* mat);


int main(){
    float a, b, c, d;
    Matriz *M;
    // criação de uma matriz
    M = cria(5, 5);
    // inserção de valores na matriz
    atribui(M, 1, 2, 40);
    atribui(M, 2, 3, 3);
    atribui(M, 3, 0, 15);
    atribui(M, 4, 1, 21);
    // verificando se a inserção foi feita corretamente
    a = acessa(M, 1, 2);
    b = acessa(M, 2, 3);
    c = acessa(M, 3, 0);
    d = acessa(M, 4, 1);
    printf("M[1][2]: %4.2f \n", a);
    printf("M[2][3]: %4.2f \n", b);
    printf("M[3][0]: %4.2f \n", c);
    printf("M[4][1]: %4.2f \n", d);
    system("PAUSE");

    return 0;
}


void libera(Matriz *mat){
    free(mat->v);
    free(mat);
};

Matriz *cria(int m, int n){
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat == NULL)
    {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    mat->linha = m;
    mat->coluna = n;
    mat->v = (float *)malloc(m * n * sizeof(float));
    return mat;
}

float acessa(Matriz *mat, int i, int j){
    int k; /* índice do elemento no vetor */
    if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna)
    {
        printf("Acesso inválido!\n");
        exit(1);
    }
    k = i * mat->coluna + j;
    
        // armazenamento por linha
    
    return mat->v[k];
}

int linhas(Matriz *mat){
    return mat->linha;
}

void atribui(Matriz *mat, int i, int j, float v){
    int k; /* índice do elemento no vetor */
    if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna)
    {
        printf("Atribuição inválida!\n");
        exit(1);
    }
    k = i * mat->coluna + j;
    mat->v[k] = v;
}

int colunas(Matriz *mat){
    return mat->coluna;
}