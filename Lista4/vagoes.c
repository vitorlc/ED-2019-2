#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int m, int n){

    int **v;
    int i;
    if (m < 1 || n < 1)
    {
        printf("Parametro invalido\n");
        return (NULL);
    }

    v = (int **)calloc(m, sizeof(int *));
    if (v == NULL)
    {
        printf("Memória Insuficiente");
        return (NULL);
    }

    for (i = 0; i < m; i++)
    {
        v[i] = (int *)calloc(n, sizeof(int));
        if (v[i] == NULL)
        {
            printf("Memória Insuficiente ");
            return (NULL);
        }
    }
    return (v);
}

int insertionSort(int matriz, int alturas[], int caso){

    int i, j, k, aux, cont = 0;

    for (i = 1; i < alturas[caso]; i++)
    {
        j = i - 1;
        aux = matriz[caso][i];
        while (j >= 0 && matriz[caso][j] > aux)
        {
            matriz[caso][j + 1] = matriz[caso][j];
            j--;
            cont++;
        }

        matriz[caso][j + 1] = aux;
    }
    return cont;
}

int main()
{

    int i, j, cont, qtd, casos;

    scanf("%d", &casos);

    int matrizNumeros;

    matrizNumeros = alocarMatriz(casos, 1000);

    int vetQtdNumeros[casos];
    int vetCont[casos];

    for (i = 0; i < casos; i++)
    {
        scanf("%d", &vetQtdNumeros[i]);
        for (j = 0; j < vetQtdNumeros[i]; j++)
        {
            scanf("%d", &matrizNumeros[i][j]);
        }
    }

    for (i = 0; i < casos; i++)
    {
        vetCont[i] = insertionSort(matrizNumeros, vetQtdNumeros, i);
    }

    for (i = 0; i < casos; i++)
    {
        printf("%d", vetCont[i]);
        printf("\n");
    }
}