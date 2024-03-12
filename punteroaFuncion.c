#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
//Prototipo de las funciones
void comprobar(char *a, char *b, int (*cmp)(const char *, const char *));
int numcmp(const char *a, const char *b);

//Funcion principal
int main(int argc, char const *argv[])
{
	char c1[80], c2[80];
	int (*p)(const char *, const char *); //Inicializamos puntero a una funcion

	p = strcmp; //Asignamos a p la direccion de strcmp

	//Pedimos los valores
	printf("Introduce dos cadenas o valores\n");
	gets(c1); //Entrada de datos 
	gets(c2);

	// Comprobamos si es un digito o cadena
	/* isdigit viene en la libreria ctype y nos retorna un valor distinto a cero cuando es verdadero (!=0) 
	o cero si es falso (0) */ 	
	/* Tambien es importante recordar que un arreglo viene siendo un puntero, por eso a continuacion se usa "*c1"
	para dirigirse dentro de lo que hay en ese dato */
	if(isdigit(*c1)){
		printf("Probando la igualdad de valores.\n");
		comprobar(c1, c2, numcmp); //llamamos a la funcion para numeros
	}else{
		printf("Probando la igualdad de las cadenas.\n");
		comprobar(c1, c2, p); //Llamamos a la funcion para cadenas
		
	} 
	
	return 0;
}

/* Hacemos uso del puntero a la funcion en este caso p como strcmp, en el que strcmp sirve para comparar dos cadenas de texto y
devuelve 0 si es igual, en este caso los esta negando al poner el simbolo ! */
void comprobar(char *a, char *b, int (*cmp)(const char *, const char *)){
	printf("Comprobando igualdad.\n");
	if (!(*cmp)(a,b)) printf("iguales");
	else printf("No iguales\n");
}

int numcmp(const char *a, const char *b){
	if(atoi(a) == atoi(b)) return 0; //atoi convierte una cadena en valores numericos enteros	
	else return 1;
}