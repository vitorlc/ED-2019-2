#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_MAX 100


typedef struct conjunto
{
    int comprimento;
    int elementos[TAMANHO_MAX];
} Conjunto;



typedef struct conjunto Conjunto;

Conjunto *criaConjunto();

int conjuntoVazio(Conjunto *c);

int insereElementoConjunto(Conjunto *c, int elemento);

int tamanhoConjunto(Conjunto *c);

int maior(Conjunto *c, int elemento);

int menor(Conjunto *c, int elemento);

int pertenceConjunto(Conjunto *c, int elemento);

int conjuntosIdenticos(Conjunto *c1, Conjunto *c2);

int subconjunto(Conjunto *c1, Conjunto *c2);

Conjunto *complemento(Conjunto *c1, Conjunto *c2);

Conjunto *uniao(Conjunto *c1, Conjunto *c2);

Conjunto *interseccao(Conjunto *c1, Conjunto *c2);

Conjunto *diferenca(Conjunto *c1, Conjunto *c2);

int conjuntoPartes(Conjunto *c1);

void mostraConjunto(Conjunto *c1, char *ordem);

int copiarConjunto(Conjunto *c1, Conjunto *c2);

int destroiConjunto(Conjunto *c1);

Conjunto *criaConjunto()
{

    Conjunto *c = (Conjunto *)malloc(sizeof(Conjunto));
    if (c != NULL)
    {
        c->comprimento = 0;
    }
    return c;
}

int conjuntoVazio(Conjunto *c)
{

    if (c == NULL)
    {
        return 0;
    }
    if (c->comprimento == 0)
        printf("conjunto vazio\n");
    return 1;
}

int insereElementoConjunto(Conjunto *c, int elemento)
{
    if (c == NULL)
        return 0;

    int i = 0;

    for (i = 0; i < c->comprimento; i++)
    {
        if (c->elementos[i] == elemento)
        {
            printf("Falha ao adicionar elemento já existente\n");
            return 0;
        }
    }
    c->elementos[c->comprimento] = elemento;
    c->comprimento++;
    return 1;
}

int excluirElementoConjunto(Conjunto *c, int elemento)
{
    int i = 0, cont = 0;

    if (c == NULL)
        return 0;
    if (c->comprimento == 0)
        return 0;

    for (i = 0; i < c->comprimento; i++)
    {
        if (c->elementos[i] == elemento)
        {
            cont++;
            c->elementos[i] = c->elementos[i + 1];
            c->comprimento--;
        }
    }

    if (cont == 0)
    {
        printf("Numero inexistente no conjunto");
        return 0;
    }
    else
        return 1;
}

int tamanhoConjunto(Conjunto *c)
{
    int i, cont = 0;

    if (c == NULL)
        return 0;

    if (c->comprimento == 0)
    {
        printf("tamanho 0");
        return 0;
    }
    else
        for (i = 0; i < c->comprimento; i++)
        {
            cont++;
        }
    return cont;
}

int maior(Conjunto *c, int elemento)
{

    int i = 0, cont = 0;

    if (c == NULL)
        return 0;
    if (c->comprimento == 0)
        return 0;

    for (i = 0; i < c->comprimento; i++)
    {
        if (c->elementos[i] > elemento)
        {
            cont++;
        }
    }
    return cont;
}

int menor(Conjunto *c, int elemento)
{

    int i = 0, cont = 0;

    if (c == NULL)
        return 0;
    if (c->comprimento == 0)
        return 0;

    for (i = 0; i < c->comprimento; i++)
    {
        if (c->elementos[i] < elemento)
        {
            cont++;
        }
    }
    return cont;
}

int pertenceConjunto(Conjunto *c, int elemento)
{

    int i = 0, cont = 0;

    if (c == NULL)
        return 0;

    for (i = 0; i < c->comprimento; i++)
    {
        if (c->elementos[i] == elemento)
        {
            cont++;
        }
    }
    if (cont != 0)
    {
        printf("TRUE\n");
        return 1;
    }
    else
        printf("FALSE\n");
    return 0;
}

int conjuntosIdenticos(Conjunto *c1, Conjunto *c2)
{

    int i, j, cont = 0;

    if (c1->comprimento != c2->comprimento)
    {
        printf("FALSE\n");
        return 0;
    }
    else

        for (i = 0; i < c1->comprimento; i++)
        {
            for (j = 0; j < c2->comprimento; j++)
            {
                if (c1->elementos[i] == c2->elementos[j])
                {
                    cont++;
                }
            }
        }
    if (cont == c1->comprimento)
    {
        printf("TRUE\n");
        return 1;
    }
    else
        printf("FALSE\n");
    return 0;
}

int subconjunto(Conjunto *c1, Conjunto *c2)
{

    int i, j, cont = 0;
    if (c1->comprimento > c2->comprimento)
    {
        printf("FALSE\n");
        return 0;
    }
    else
        for (i = 0; i < c1->comprimento; i++)
        {
            for (j = 0; j < c2->comprimento; j++)
            {
                if (c1->elementos[i] == c2->elementos[j])
                {
                    cont++;
                }
            }
        }
    if (cont == c1->comprimento)
    {
        printf("TRUE\n");
        return 1;
    }
    else
        printf("FALSE\n");
    return 0;
}

Conjunto *complemento(Conjunto *c1, Conjunto *c2)
{

    int i, j, cont = 0;
    Conjunto *c3 = criaConjunto();

    if (c3 == NULL || c1 == NULL || c2 == NULL)
        return NULL;

    for (i = 0; i < c2->comprimento; i++)
    {
        cont = 0;
        for (j = 0; j < c1->comprimento; j++)
        {
            if (c1->elementos[j] == c2->elementos[i])
            {
                cont++;
            }
        }
        if (cont == 0)
        {
            insereElementoConjunto(c3, c2->elementos[i]);
        }
    }
    return c3;
}

Conjunto *uniao(Conjunto *c1, Conjunto *c2)
{

    int i;
    Conjunto *c3 = criaConjunto();

    if (c3 == NULL || c1 == NULL || c2 == NULL)
        return NULL;

    c3 = complemento(c1, c2);

    for (i = 0; i < c1->comprimento; i++)
    {
        insereElementoConjunto(c3, c1->elementos[i]);
    }
    return c3;
}

Conjunto *interseccao(Conjunto *c1, Conjunto *c2)
{

    int i, j, cont = 0;
    Conjunto *c3 = criaConjunto();

    if (c3 == NULL || c1 == NULL || c2 == NULL)
        return NULL;

    for (i = 0; i < c2->comprimento; i++)
    {
        cont = 0;
        for (j = 0; j < c1->comprimento; j++)
        {
            if (c1->elementos[j] == c2->elementos[i])
            {
                cont++;
            }
        }
        if (cont == 1)
        {
            insereElementoConjunto(c3, c2->elementos[i]);
        }
    }
    return c3;
}

Conjunto *diferenca(Conjunto *c1, Conjunto *c2)
{

    int i, j, cont = 0;
    Conjunto *c3 = criaConjunto();

    if (c3 == NULL || c1 == NULL || c2 == NULL)
        return NULL;

    for (i = 0; i < c1->comprimento; i++)
    {
        cont = 0;
        for (j = 0; j < c2->comprimento; j++)
        {
            if (c2->elementos[j] == c1->elementos[i])
            {
                cont++;
            }
        }
        if (cont == 0)
        {
            insereElementoConjunto(c3, c1->elementos[i]);
        }
    }
    return c3;
}

int conjuntoPartes(Conjunto *c1)
{

    if (c1 == NULL)
        return 0;
    if (c1->comprimento == 0)
        return 0;

    int i;

    for (i = 0; i < c1->comprimento; i++)
    {
        printf("[%d]", c1->elementos[i]);
        if (i < c1->comprimento - 1)
            printf(", ");
    }
    printf("\n");
}

void mostraConjunto(Conjunto *c1, char *ordem)
{
    int i, j, aux;
    char cre[11] = "CRESCENTE";
    char dec[11] = "DECRESCENTE";

    if (c1 == NULL)
        return;
    if (c1->comprimento == 0)
    {
        printf("VAZIO");
        return;
    }
    for (i = 0; i < c1->comprimento; i++)
    {
        aux = c1->elementos[i];
        j = i - 1;
        if (strcmp(cre, ordem) == 0)
        {
            while ((j >= 0) && (c1->elementos[j] > aux))
            {
                c1->elementos[j + 1] = c1->elementos[j];
                j--;
            }
        }
        else if (strcmp(dec, ordem) == 0)
        {
            while ((j >= 0) && (c1->elementos[j] < aux))
            {
                c1->elementos[j + 1] = c1->elementos[j];
                j--;
            }
        }
        c1->elementos[j + 1] = aux;
    }

    printf("[");
    for (int i = 0; i < c1->comprimento; i++)
    {
        printf("%d", c1->elementos[i]);
        if (i < c1->comprimento - 1)
            printf(", ");
    }
    printf("]\n");
}

int copiarConjunto(Conjunto *c1, Conjunto *c2)
{

    int i, j, cont = 0;
    Conjunto *c3 = criaConjunto();

    if (c3 == NULL || c1 == NULL || c2 == NULL)
    {
        printf("FALHA");
        return 0;
    }

    c3 = diferenca(c1, c2);

    for (i = 0; i < c3->comprimento; i++)
    {
        insereElementoConjunto(c2, c3->elementos[i]);
    }
    printf("SUCESSO: ");
    return 1;
}

int destroiConjunto(Conjunto *c1)
{

    if (c1 == NULL)
    {
        printf("FALHA");
        return 0;
    }
    else
        free(c1);
    printf("SUCESSO");
    return 1;
}

int main()
{
    int n;
    Conjunto *c1 = criaConjunto();
    Conjunto *c2 = criaConjunto();
    Conjunto *c3 = criaConjunto();
    Conjunto *c4 = criaConjunto();
    Conjunto *c5 = criaConjunto();
    Conjunto *c6 = criaConjunto();
    Conjunto *c7 = criaConjunto();

    insereElementoConjunto(c1, 1);
    insereElementoConjunto(c1, 2);
    insereElementoConjunto(c1, 3);

    insereElementoConjunto(c2, 3);
    insereElementoConjunto(c2, 4);
    insereElementoConjunto(c2, 5);
    insereElementoConjunto(c2, 6);

    insereElementoConjunto(c3, 1);
    insereElementoConjunto(c3, 2);
    insereElementoConjunto(c3, 3);
    
    insereElementoConjunto(c4, 4);
    insereElementoConjunto(c4, 5);

    int opcao;
    do
    {
        printf(" \n =======> Opcoes: ");
        printf(" \n 1. Conjunto das Partes" );
        printf(" \n 2. Tamanho dos Conjuntos");
        printf(" \n 3. Conjuntos em ordem crescente");
        printf(" \n 4. Conjuntos em ordem decrescente");
        printf(" \n 5. Diferencas entre os Conjuntos");
        printf(" \n 6. Interseccao entre os Conjuntos");
        printf(" \n 7. Qtd de elementos maior/menor que o nº informado");
        printf(" \n 0. Finalizar Programa ");
        scanf("\n%d%*c", &opcao);
        switch(opcao)
        {
            case 1:
                printf("\nConjunto das partes de c1: ");
                conjuntoPartes(c1);
                printf("\nConjunto das partes de c2: ");
                conjuntoPartes(c2);
                printf("\nConjunto das partes de c3: ");
                conjuntoPartes(c3);
                printf("\nConjunto das partes de c4: ");
                conjuntoPartes(c4);
            break;
            case 2:
                printf("\nTamanho c1: %d \n", tamanhoConjunto(c1));
                printf("Tamanho c1: %d \n", tamanhoConjunto(c2));
                printf("Tamanho c1: %d \n", tamanhoConjunto(c3));
                printf("Tamanho c1: %d \n", tamanhoConjunto(c4));
            break;
            case 3:
                printf("\nConjunto C1 em ordem crescente: ");
                mostraConjunto(c1, "CRESCENTE");
                printf("Conjunto C2 em ordem crescente: ");
                mostraConjunto(c2, "CRESCENTE");
                printf("Conjunto C3 em ordem crescente: ");
                mostraConjunto(c3, "CRESCENTE");
                printf("Conjunto C4 em ordem crescente: ");
                mostraConjunto(c4, "CRESCENTE");
            break;   
            case 4:
                printf("\nConjunto C1 em ordem decrescente: ");
                mostraConjunto(c1, "DECRESCENTE");
                printf("Conjunto C2 em ordem decrescente: ");
                mostraConjunto(c2, "DECRESCENTE");
                printf("Conjunto C3 em ordem decrescente: ");
                mostraConjunto(c3, "DECRESCENTE");
                printf("Conjunto C4 em ordem decrescente: ");
                mostraConjunto(c4, "DECRESCENTE");
            break;
            case 5:
                printf("Diferenca entre o conjunto c1 e c2: ");
                c7 = diferenca(c1, c2);
                for (int i = 0; i < c7->comprimento; i++)
                {
                    printf("%d, ", c7->elementos[i]);
                }
                printf("\n");
                printf("Diferenca entre o conjunto c2 e c3: ");
                c7 = diferenca(c2, c3);
                for (int i = 0; i < c7->comprimento; i++)
                {
                    printf("%d, ", c7->elementos[i]);
                }
                printf("\n");
                printf("Diferenca entre o conjunto c3 e c4: ");
                c7 = diferenca(c3, c4);
                for (int i = 0; i < c7->comprimento; i++)
                {
                    printf("%d, ", c7->elementos[i]);
                }
                printf("\n");
                printf("Diferenca entre o conjunto c1 e c4: ");
                c7 = diferenca(c1, c4);
                for (int i = 0; i < c7->comprimento; i++)
                {
                    printf("%d, ", c7->elementos[i]);
                }
                printf("\n");
                printf("Diferenca entre o conjunto c2 e c4: ");
                c7 = diferenca(c2, c4);
                for (int i = 0; i < c7->comprimento; i++)
                {
                    printf("%d, ", c7->elementos[i]);
                }
                printf("\n");
                printf("Diferenca entre o conjunto c1 e c3: ");
                c7 = diferenca(c1, c3);
                for (int i = 0; i < c7->comprimento; i++)
                {
                    printf("%d, ", c7->elementos[i]);
                }
                printf("\n");   
            break;
            case 6:
                printf("interseccao de c1 e c2: ");
                c6 = interseccao(c1, c2);
                for (int i = 0; i < c6->comprimento; i++)
                {
                    printf("%d, ", c6->elementos[i]);
                }
                printf("\n");
                printf("interseccao de c2 e c3: ");
                c6 = interseccao(c2, c3);
                for (int i = 0; i < c6->comprimento; i++)
                {
                    printf("%d, ", c6->elementos[i]);
                }
                printf("\n");
                printf("interseccao de c1 e c3: ");
                c6 = interseccao(c1, c3);
                for (int i = 0; i < c6->comprimento; i++)
                {
                    printf("%d, ", c6->elementos[i]);
                }
                printf("\n");
                printf("interseccao de c3 e c4: ");
                c6 = interseccao(c3, c4);
                for (int i = 0; i < c6->comprimento; i++)
                {
                    printf("%d, ", c6->elementos[i]);
                }
                printf("\n");
                printf("interseccao de c2 e c4: ");
                c6 = interseccao(c2, c4);
                for (int i = 0; i < c6->comprimento; i++)
                {
                    printf("%d, ", c6->elementos[i]);
                }
                printf("\n");
                printf("interseccao de c1 e c4: ");
                c6 = interseccao(c1, c4);
                for (int i = 0; i < c6->comprimento; i++)
                {
                    printf("%d, ", c6->elementos[i]);
                }
                printf("\n");
               
            break;
            case 7:
            printf("\nDigite o numero: ");
            scanf("%d", &n);
            printf("Qtd de elementos do conjunto C1 que sao maiores que %d : %d\n",n, maior(c1, n));
            printf("Qtd de elementos do conjunto C2 que sao maiores que %d : %d\n",n, maior(c2, n));
            printf("Qtd de elementos do conjunto C3 que sao maiores que %d : %d\n",n, maior(c3, n));
            printf("Qtd de elementos do conjunto C4 que sao maiores que %d : %d\n",n, maior(c4, n));
            printf("Qtd de elementos do conjunto C1 que sao menores que %d : %d\n",n, menor(c1, n));
            printf("Qtd de elementos do conjunto C2 que sao menores que %d : %d\n",n, menor(c2, n));
            printf("Qtd de elementos do conjunto C3 que sao menores que %d : %d\n",n, menor(c3, n));
            printf("Qtd de elementos do conjunto C4 que sao menores que %d : %d\n",n, menor(c4, n));
            break;
        }
    }
    while(opcao!=0);
    

    printf("verificando se 7 pertence a c2: ");
    pertenceConjunto(c2, 7);

    printf("verificando se c1 e identico a c3: ");
    conjuntosIdenticos(c1, c3);

    printf("verificando se c4 e subconjunto de c2: ");
    subconjunto(c4, c2);

    printf("complemento de c4 em relacao a c2: ");
    c5 = complemento(c4, c2);
    for (int i = 0; i < c5->comprimento; i++)
    {
        printf("%d, ", c5->elementos[i]);
    }
    printf("\n");

    printf("uniao de c1 em relacao a c2: ");
    c2 = uniao(c1, c2);
    for (int i = 0; i < c2->comprimento; i++)
    {
        printf("%d, ", c2->elementos[i]);
    }
    printf("\n");

    printf("quantidade de elementos do conjunto que são maiores que 5 : %d\n", maior(c2, 5));
    printf("quantidade de elementos do conjunto que são menores que 5 : %d\n", menor(c2, 5));

    printf("copiar conjunto c2 para c3: ");
    copiarConjunto(c2, c3);
    for (int i = 0; i < c3->comprimento; i++)
    {
        printf("%d, ", c3->elementos[i]);
    }
    printf("\n");

    printf("destruindo conjunto: ");
    destroiConjunto(c1);
    printf("\n");
    printf("mostrando conjunto destruido: \n");
    mostraConjunto(c1, "CRESCENTE");
}