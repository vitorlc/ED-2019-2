#include <stdio.h>

int main(){

    int ref=1986;
    int anoDado=0;
    int diferenca=0;
    int ultimoAno=0;
    int aparicoes=0;
    int restoDiv=0;
    int anosPassados=0;
    int restantes=0;
    int next=0;

    scanf("%d", &anoDado);

    if(anoDado > ref){
        diferenca =  anoDado - ref;
        aparicoes = diferenca / 76;
        ultimoAno = ref + (aparicoes * 76);
        anosPassados = anoDado - ultimoAno;
        restantes = 76 - anosPassados;
        if (diferenca/4 > 365){
            printf( "%d", restantes+ anoDado - (diferenca/4)/365);
        } 
        printf( "%d", restantes+ anoDado);
    }
    else if(anoDado < ref){
        diferenca = ref - anoDado;
        aparicoes = diferenca / 76;
        if (diferenca/4 > 365){
            printf( "%d", ref - aparicoes * 76 - (diferenca/4)/365 );
        }else{    
            printf( "%d", ref - aparicoes * 76);
        }
    }
    return 0;
}