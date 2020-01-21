/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */


#include "ordenacion.h"

/***************************************************/
/* Funcion: InsertSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int InsertSort(int* tabla, int ip, int iu) {
	int i, j, a, aux;

	for(i = ip + 1, aux = 0;i <= iu; i++) {
		a = tabla[i];
		j = i - 1;
		aux++;
		while(j >= ip && tabla[j] > a) {
			tabla[j+1] = tabla[j];
			j--;
			aux++;
		}
		tabla[j+1] = a;
	}
	return aux;
}

int InsertSortInv(int* tabla, int ip, int iu)
{
int i, j, a, aux;

	for(i = ip + 1, aux = 0;i <= iu; i++) {
		a = tabla[i];
		j = i - 1;
		aux++;
		while(j >= ip && tabla[j] < a) {
			tabla[j+1] = tabla[j];
			j--;
			aux++;
		}
		tabla[j+1] = a;
	}
	return aux;	
}


