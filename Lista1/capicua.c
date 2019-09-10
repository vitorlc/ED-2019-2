#include <stdio.h>

int main(){

    int n=0, i=0;
    int nReverse = 0, nOriginal = 0;
    
    scanf("%d", &n);
    
    int array[n];
    for(i = 0; i < n; ++i){
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; ++i){
        nReverse = 0;
        nOriginal= array[i];
        while (array[i] != 0)
        {
            nReverse = nReverse * 10;
            nReverse = nReverse + array[i]%10;
            array[i] = array[i]/10;
        }   
        if( nOriginal == nReverse){
            printf("yes ");

        }else {
            printf("no ");
        }
    }
    
    return 0;
}
