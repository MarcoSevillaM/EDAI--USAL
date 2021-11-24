/*
 *      Autor: Marco Sevilla Martín-M.J. Polo
 *	2ºIngeniería Informática
 *	marcosevillam@usal.es
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
	if(p==NULL) return -1;
		
	*p=NULL;
	return 0;
}

int pilaVacia(Pila *p)
{
	if(*p== NULL) return 1;  //Esta vacía
	else if(*p==NULL) return -1;
	else return 0;		//NO esta vacía
    
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
	if(p == NULL){
		fprintf(stderr,"La pila esta vacía");
		return -1;
	}
	Pila temp, aux;
	if(NULL==(temp=(tipoCelda *)malloc(sizeof(tipoCelda)))) return -2;
	else{
		temp->elemento = elemento;
		aux=*p;
		temp->sig=aux;
		*p=temp;
		return 0;
	}
	
}

tipoElemento pilaSuprime(Pila *p)
{
   tipoElemento elemento;
   Pila aux;
   aux= *p;
   if(p==NULL) return -1;
   else if(aux==NULL) return -2;
   else{
   	elemento= aux->elemento;
   	*p=aux->sig;
   	free(aux);
   	return elemento;
   }
}
