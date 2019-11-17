#include <stdio.h>
#include <stdlib.h>
 
 
int **AlocarMatriz (int m, int n){
  int **v; 
  int   i;
  if (m < 1 || n < 1) {
     printf ("Parametro invalido\n");
     return (NULL);
     }
  v = (int **) calloc (m, sizeof(int *));
  if (v == NULL) {
     printf ("Memoria Insuficiente");
     return (NULL);
     }
  for ( i = 0; i < m; i++ ) {
      v[i] = (int*) calloc (n, sizeof(int));
      if (v[i] == NULL) {
         printf ("Memoria Insuficiente");
         return (NULL);
         }
      }
  return (v); 
}
 
void preencheMatrizAlturas(int **alturasArmazenadas, int casos, int alturas[]){
  int i, j;
  for(i=0; i<casos; i++){

    scanf("%d", &alturas[i]);

    for(j=0; j<alturas[i]; j++){
      scanf("%d", &alturasArmazenadas[i][j]);
    }

  }
 
}
 
void insertionSort(int **matriz, int alturas[], int caso){
  int i, j, k, aux;
 
  for(i=1; i<alturas[caso]; i++){
    j = i - 1;
    aux = matriz[caso][i];
 
    while(j>=0 && matriz[caso][j]>aux){
      matriz[caso][j+1] = matriz[caso][j];
      j--;
    }
 
    matriz[caso][j+1] = aux;    
  }

}
 
void printMatriz(int **alturasArmazenadas, int casos, int alturas[]){
  int i, j;
  for(i=0; i<casos; i++){
    for(j=0; j<alturas[i]; j++){
      printf("%d ", alturasArmazenadas[i][j]);
    }
    printf("\n");
  }
}
 
int main(){
    int qtd, casos;
    int i=0;
    scanf("%d", &casos);
 
    int alturas[casos];
    int **alturasArmazenadas;
    alturasArmazenadas = AlocarMatriz(casos, 1000);
 
    preencheMatrizAlturas(alturasArmazenadas, casos, alturas);
 
    for(i=0; i<casos; i++) {
      insertionSort(alturasArmazenadas, alturas, i);
    }

    printMatriz(alturasArmazenadas, casos, alturas); 
}