#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

//Cria, de maneira dinâmica, uma data a partir dos valores para dia, mês e ano fornecidos.
Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano);

//Cria uma cópia da data d, retornando-a.
Data * copiaData (Data d);

//Destrói a data indicada por d.
void liberaData (Data * d);

//Retorna uma data que é dias dias posteriores à data d. Por exemplo, fornecendo a data d = 12/11/2019 e dias = 5, retornará a data 17/11/2019.
Data * somaDiasData (Data d, unsigned int dias);

//Retorna uma data que é dias dias anteriores à data d. Por exemplo, fornecendo a data d = 12/11/2019 e dias = 15, retornará a data 28/10/2019.
Data * subtrairDiasData (Data d, unsigned int dias);

//Atribui, à data d, a data dia/mes/ano especificada. Se não for possível, então faz com que d seja alterada para NULL.
void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);

//Retorna a componente dia da data d.
unsigned int obtemDiaData (Data d);

//Retorna a componente mes da data d.
unsigned int obtemMesData (Data d);

//Retorna a componente ano da data d.
unsigned int obtemAnoData (Data d);

//Retorna TRUE se a data pertence a um ano bissexto. Do contrário, retorna FALSE.
unsigned int bissextoData (Data d);

//Retorna MENOR se d1 < d2, retorna IGUAL se d1 = d2 ou retorna MAIOR, se d1 > d2.
int comparaData (Data d1, Data d2);

//Retorna o número de dias que existe entre as datas d1 e d2.
// Se d1 = d2, então o número de dias é igual a 0 (zero). Do contrário, será um número estritamente
// positivo.
unsigned int numeroDiasDatas (Data d1, Data d2);

// Se d1 e d2 estão no mesmo mês/ano, então o número de meses é igual a 0 (zero). Do contrário, será
// um número estritamente positivo.
unsigned int numeroMesesDatas (Data d1, Data d2);

// Se d1 e d2 estão no mesmo ano, então o número de anos é igual a 0 (zero). Do contrário, será um
// número estritamente positivo.
unsigned int numeroAnosDatas (Data d1, Data d2);

// Retorna o dia da semana correspodente à data d. Considerando que DOMINGO = 1; SEGUNDA-FEIRA
// = 2; ... ; SÁBADO = 7.
unsigned int obtemDiaSemanaData (Data d);

char * imprimeData (Data d, char * formato);


int main (){
    Data *data = NULL;

    data = criaData(6,11,1111);

    printf("%d", *data);

    return 0;
};

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano){
    Data *data= malloc(sizeof(Data));
    scanf ("%d %d %d", &data.dia, &data.mes, &data.ano);
    return data;
};
