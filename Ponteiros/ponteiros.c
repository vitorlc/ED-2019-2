#include <stdio.h>
#include <stdlib.h>

void hora();

int main (){
    int c, *pt;
    c =5;
    pt = &c;

    printf("===========PONTEIROS===========\n");
    printf("> Valor da variavel c: %d\n", c);
    printf("> Endereco da variavel c: %d\n", &c);
    printf("> Valor da variavel c pelo pt: %d\n", *pt);
    printf("> Valor do ponteiro pt: %d\n", pt);
    printf("> Endereco da ponteiro pt: %d\n", &pt);

    hora();

    return 0;
}

void hora (){

    printf("===========EXEMPLO COM STRUCT===========");
    typedef struct horario {
        int hora;
        int minuto;
        int segundo;
    } Horario;
    
    Horario agora, *depois;
    depois=&agora; //aponto meu ponteiro para o endereço da minha struct agora

    // Atribuo valores a minha struct agora usando meu ponteiro
    depois->hora = 20;
    depois->minuto = 20;
    depois->segundo = 20;

    printf("\n%i:%i:%i", depois->hora, agora.minuto, agora.segundo);

}