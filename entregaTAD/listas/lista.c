/*
 *      Autor: Marco Sevilla Martín-M.J. Polo
 *	2ºIngeniería Informática
 *	marcosevillam@usal.es
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"


/////FUNCIONES PROPORCIONADAS/////
int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}
////////FUNCIONES REALIZADAS POR EL USUARIO//////////////

tipoPosicion
primero(Lista *l)
{
	if(l==NULL){
		fprintf(stderr,"La lista no existe!!!\n ");	
		return NULL;
	} else if(l->raiz == NULL){
		fprintf(stderr,"Lista no inicializada!!!\n");
		return NULL;
	}else
		return l->raiz;
}



tipoPosicion
fin(Lista *l)
{
	if(l==NULL) return NULL;
	else if(l->ultimo == NULL)return NULL;
	else return l->ultimo;
	
}




int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
    tipoCelda *aux;
    if(l== NULL) return -1; //La lista no existe
    else if (l->raiz==NULL){
    	fprintf(stderr,"La lista no existe!!\n");
    	return -2; //No existe el nodo ficticio
    } 
    else if (p==NULL){
    	fprintf(stderr,"Posición no válida!!\n");
    	return -3; //La posicion no es válida
    }
    else if (NULL == (aux= (tipoCelda*)malloc(sizeof(tipoCelda)))){
    	fprintf(stderr,"Fallo en la reserva de memoria!!\n");
    	return -4; //Error en la reserva de memoria
    }
    else{
    	aux->elemento = x;
    	aux->sig=p->sig;
    	p->sig=aux;
    	if(p == l->ultimo)
    	   l->ultimo = aux;
    	return 0;
    }
}


int
suprime (tipoPosicion p, Lista *l)
{
    tipoCelda * borrar;
    if(l == NULL) return -1; //Lista no existe
    if(l->raiz == NULL) return -2; //La lista esta vacía
    if(p == NULL) return -3; //La posicion no existe
    else{
    	borrar=p->sig;
    	p->sig=borrar->sig;
    	free(borrar);
    	if(p->sig == NULL) l->ultimo =p;
    	return 0;
    }
}


tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    if (l==NULL){
    	fprintf(stderr,"La lista no existe!!");
    	return NULL;
    }else if (p==NULL){
    	fprintf(stderr,"Posición inválida!!");
    	return NULL;
    }
    else if(p == fin(l)) return fin(l);
    else
    	return p->sig; 
}




tipoPosicion
localiza (tipoElemento x, Lista *l)
{
	tipoCelda * localiza;
	if(l==NULL) return NULL; //No existe la lista
	else if(l->raiz==NULL) return NULL; //Lista vacía
	else{
		localiza= l->raiz->sig;
		while(localiza != NULL){
			if(localiza->sig->elemento ==x) return localiza;
			else localiza=localiza->sig;
		}
	}
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{
    if (l==NULL){
    	fprintf(stderr,"La lista no existe!!");
    	return -1;
    }else if (p==NULL){
    	fprintf(stderr,"Posición inválida!!");
    	return -2;
    }else if(l->raiz== NULL){
    	fprintf(stderr,"La lista está vacía");
     	return -3;
    }
    else{
    	return p->sig->elemento;
    }
}


int
anula(Lista *l)
{
    tipoCelda *borrar;
    if(l == NULL || l->raiz == NULL) //La lista o esta vacía o no existe
    	return -1;
    else{
    	while(l->raiz->sig != NULL){
    		borrar= l->raiz->sig;
    		l->raiz->sig = borrar->sig;
    		free(borrar);
    	}
    	return 0;
    }
}

int
concatena(Lista *lA, Lista *lB)
{
	if (lA == NULL || lA->raiz == NULL) return -1; //Compuebo que la lista lA este creada y no esté vacía
	if (lB == NULL || lB->raiz == NULL) return -2; //Compuebo que la lista lA este creada y no esté vacía
		lA->ultimo->sig = lB->raiz->sig; // Uno el ultimo elemento de lA con el primero de lB
		lA->ultimo = lB->ultimo; //Ahora el ultimo elemento de lB es el ultimo de lA que es la lista final
		//Dejamos la lista lB vacía
		lB->raiz->sig = NULL;
		lB->ultimo = NULL;
    		return 0;
}



