#include <stdio.h>
 
int main()
{
    void insertionSort(int arr[], int tam);
    void printResultado(int arr[], int tam);
    void verificaPosicaoPrimo(int arr[],int primos[], int tam);
    int vetorPrimo(int tam);
    
    int tam, i;
    scanf("%d", &tam);
    int arr[tam], resultado[tam];
    
    for (i=0; i<tam; i++){
        scanf("%d ", &arr[i]);
    }
 
    int primos[1000];
    primos = vetorPrimo()
    resultado = verificaPosicaoPrimo(arr, primos, tam);
    insertionSort(resultado, tam);
    printResultado(resultado, tam);
    
    return 0;
}
 
void insertionSort(int arr[], int tam){
    int i= 0, j=0, aux=0;
    
    for (i=1;i<tam; i++){
        aux = arr[i];
        j= i-1;
        while((j>=0) && (arr[j]>aux)){
            arr[j+1]= arr[j];
            j=j-1;
        }
        arr[j+1]=aux;
    }
}
 
void printResultado(int arr[], int tam){
    int i;
    for (i=0; i<tam; i++){
        printf("%d ", arr[i]);
    }
 
}
 
void verificaPosicaoPrimo(int arr[], int primos[], int tam){
    
    int resultado[tam];
    
    for(j=1; j<tam;j++){
        resultado[j]= primos[arr[j]];        
    }
    
    return resultado;
}
 
int vetorPrimo (){
    
    int primos[1000];
    
    
    return primos;
 
}