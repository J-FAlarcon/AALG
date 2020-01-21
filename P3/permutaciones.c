/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */

#include <stdio.h>
#include "permutaciones.h"

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
	return rand()%(sup-inf)+inf;
}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/

int* genera_perm(int N) {
	int* array = NULL;
	int i, tmp, aux;
	

	
	array = (int*)malloc(N*sizeof(int));


	if(!array)
		return NULL;

	for(i = 0; i < N; i++) {
		array[i] = i;
	} 

	for(i = 0; i < N; i++) {
		aux = aleat_num(i,N);
		tmp = array[i];
		array[i] = array[aux];
		array[aux] = tmp;
	}



	return array;
}



/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N) {
	int** array = NULL;
	int i;

	
	array = (int**)malloc(n_perms  *sizeof(int*));

	if(!array)
		return NULL;

	for(i = 0; i < n_perms; i++) {
			array[i] = genera_perm(N);
			if(array[i]==NULL) return NULL;
	}

	return array;
}
