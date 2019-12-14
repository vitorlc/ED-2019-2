//
// cubo.h
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cubo Cubo; 

Cubo*   cubo_cria(float a); 

void    cubo_libera(Cubo* c); 

float   cubo_acessa(Cubo* c);

void    cubo_atribui(Cubo* c, float a);

float   cubo_perimetro(Cubo* c);

float   cubo_area(Cubo* c);

float   cubo_volume(Cubo* c);

float   cubo_diagonal(Cubo* c);

struct cubo {
   float a;
};

//
// Cria um cubo
//
Cubo* cubo_cria (float a) {
	Cubo* c = (Cubo*) malloc(sizeof(Cubo));
	if (c != NULL) {
		c->a = a;
	}
	return (c);
}

//
// Libera (desaloca) o cubo
//
void cubo_libera (Cubo* c) {
     if (c != NULL) {
	    free(c);
	 }
}

//
// Acessa um cubo
//
float cubo_acessa (Cubo* c) {
	return (c->a);
}

//
// Atribui um valor a aresta do cubo
//
void cubo_atribui (Cubo* c, float a) {
	if (c != NULL) {
	   c->a = a;
	}
}

//
// Retorna o perimetro do cubo
//
float cubo_perimetro (Cubo* c) {
	if (c != NULL) {
	   return(12 * c->a);
	}
}
//
// Retorna a area total do cubo
//
float cubo_area (Cubo* c) {
	if (c != NULL) {
	   return(6 * c->a * c->a);
	}
}
//
// Retorna volume do cubo
//
float cubo_volume (Cubo* c) {
	if (c != NULL) {
	   return(c->a * c->a * c->a);
	}
}
//
// Retorna a diagonal do cubo
//
float cubo_diagonal (Cubo* c) {
	if (c != NULL) {
	   return(sqrt(3) * c->a);
	}
}

//
// Corpo principal do programa
// 
int main(){
	float aresta, diagonal, perimetro, area, volume;	
	Cubo* variavelCubo;
	
	printf("digite o valor da aresta do cubo: ");
	scanf("%f",&aresta);
	variavelCubo = cubo_cria(aresta);
	printf("aresta    = %.2f\n", cubo_acessa(variavelCubo));
    printf("perimetro = %.2f\n", cubo_perimetro(variavelCubo));
	printf("diagonal  = %.2f\n", cubo_diagonal(variavelCubo));
    printf("area      = %.2f\n", cubo_area(variavelCubo));
	printf("volume    = %.2f\n", cubo_volume(variavelCubo));  		
	cubo_libera(variavelCubo); 
	return (0);
}


