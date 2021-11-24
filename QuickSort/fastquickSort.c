#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
#define M 0

int quickSort(int *vector, int base, int tope);
int ordenar(int *vector, int base, int tope);

int main(){
	int tam, x;
	int * vector;
	int * vectorOrdenado;
	int base, tope;
	float tiempo_resultado;
	clock_t tiempo_inicial, tiempo_final;
	srand(time(NULL));
	

	printf("\t\t Algoritmo de ordenacion QuickSort\n\n");

//======================================
//Primero generaré un vector aleatorio.
//======================================
	printf("Introduce el tamanno del vector aleatorio a ordenar: ");
	scanf("%d", &tam);

	// Creo el vector del tamaño introducido por el usuario.
	vector = (int *) malloc(tam * sizeof(int));

	// Relleno el vector con números alatorios.
	for(x=0; x<tam; x++){
		vector[x] = rand() % (N-M+1) + M;
	}

	//Muestro el vector creado aleatoriamente.
	/*for(x=0; x<tam; x++){
		printf("%d ", vector[x]);
	}*/

//======================================
/*Algoritmo de ordenación QuickSort*/
//======================================
	tiempo_inicial = clock();
	base = 0;
	tope = tam;
	quickSort(vector, base, tam-1);
	tiempo_final = clock();
	tiempo_resultado = (tiempo_final - tiempo_inicial) / (double) CLOCKS_PER_SEC;
		
	//Muestro el vector creado aleatoriamente.
	/*printf("\n\n");
	for(x=0; x<tam; x++){
		printf("%d ", vector[x]);
	}*/
	printf("\n\n");
	printf("El tiempo de ejecucion ha sido %f segundos.", tiempo_resultado);
	printf("\n\n");
	
	free(vector);
	system("pause");
	return 0;
}


//====================================================================================================================//


/*int quickSort(int *vector, int base, int tope){
	int pivote;
	printf("Entro bucle QuickSort\n");
	pivote = ordenar(vector, base, tope);
	quickSort(vector, base, pivote-1);
	quickSort(vector, pivote+1, tope);

	return 0;
}*/

int quickSort(int *vector, int base, int tope){
	int i, j, indiceP, pivote, aux; 
	i = base;
	j = tope;
	indiceP = (base + tope) / 2;
	pivote = vector[indiceP];
	
	//printf("Entro bucle Ordenar\n");
	do{
		while(vector[i] < pivote){
			i = i + 1;
		}
		while(vector[j] > pivote){
			j = j - 1;
		}
		if(i <= j){
			//Intercambio
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;

			i = i + 1;
			j = j - 1;
		}
	}while(i < j);
	if(base < j){
		quickSort(vector, base, j);
	}
	if(tope > i){
		quickSort(vector, i, tope);
	}

	return 0;
}
