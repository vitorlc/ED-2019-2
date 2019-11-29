#include <stdio.h>
#include <stdlib.h>

int main (){
    int c, *pt;
    c =5;
    pt = &c;
    printf(">%d\n", c);
    printf(">%d", *pt);

    return 0;
}