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

    Data *data_ptr = criaData(1,1,2011);
    printf("%d/%d/%d", data_ptr->dia, data_ptr->mes, data_ptr->ano);
    
    Data *dataCopia = copiaData(*data_ptr);
    printf("\n%d/%d/%d", dataCopia->dia, dataCopia->mes, dataCopia->ano);

    liberaData(dataCopia);

    Data *dataSoma = somaDiasData(*data_ptr, 10);
    printf("\nSoma: %d/%d/%d", dataSoma->dia, dataSoma->mes, dataSoma->ano);

    Data *dataSubtrair = subtrairDiasData(*data_ptr, 2);
    printf("\nSubtrair: %d/%d/%d", dataSubtrair->dia, dataSubtrair->mes, dataSubtrair->ano);

    return 0;
};

Data *criaData (unsigned int dia, unsigned int mes, unsigned int ano){
    Data *data_ptr = malloc(sizeof(Data));
    if (data_ptr != NULL) {
        data_ptr->dia = dia;
        data_ptr->mes = mes;
        data_ptr->ano = ano;
        return data_ptr; // Retorno ponteiro
    }
};

Data * copiaData (Data d){
    Data *dataCopia= (Data*) malloc(sizeof(Data));
    if (dataCopia != NULL) {
        dataCopia->dia = d.dia;
        dataCopia->mes = d.mes;
        dataCopia->ano = d.ano;
        return dataCopia;
    }
}

void liberaData (Data * d){
    if (d != NULL) {
	    free(d);
	 }
};

Data * somaDiasData (Data d, unsigned int dias){
    Data *soma = (Data*) malloc(sizeof(Data));
    if(d.dia + dias < 30){
        soma->dia= d.dia + dias;
        soma->mes=d.mes;
        soma->ano=d.ano;
    }else{
        soma->dia= (d.dia + dias) - 30;
        if(d.mes+1 < 12){
            soma->mes=d.mes+1;
            soma->ano=d.ano;
        }
        else{
            soma->mes=1;
            soma->ano=d.ano+1;
        }
    }
    return soma;
};

Data * subtrairDiasData (Data d, unsigned int dias){
    Data *subtrair = (Data*) malloc(sizeof(Data));
    if((d.dia - dias) >= 0){
        subtrair->dia= (30 - dias)+d.dia;
        if(d.mes-1<=0){
            subtrair->mes=12;
            subtrair->ano=d.ano-1;
        }else {
            subtrair->mes=d.mes-1;
            subtrair->ano=d.ano;
        }
    }
    else{
        subtrair->dia= d.dia-dias;
        subtrair->mes=d.mes;
        subtrair->ano=d.ano;
    }
    return subtrair;
};