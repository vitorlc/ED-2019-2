#include <stdio.h>
#include <stdlib.h>

int main (){
    int c, *ptr;
    c = 5;
    ptr = (int*) malloc(c * sizeof(int));


    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
 
    printf(">%d\n", c);
    printf(">%d", sizeof(ptr));

    return 0;
}