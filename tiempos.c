/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */
#include <time.h>

#include "tiempos.h"
#include "ordenacion.h"

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short tiempo_medio_ordenacion(pfunc_ordena metodo, 
                              int n_perms,
                              int N, 
                              PTIEMPO ptiempo)
{
	clock_t start_t, end_t, total_t;
	int i, *array, ob, max, min, sum, sumT;
	double avgT;

	for(i = 0, max = min = sum = sumT = total_t = 0; i < n_perms; i++) {
		array = genera_perm(N);
		start_t = clock();
		ob = InsertSort(array, 0, N-1);
		end_t = clock();
		if(max == 0 && min == 0) {
			max = min = ob;
		}
		if(ob > max)
			max = ob;
		if(ob < min)
			min = ob;
		sum += ob;
		total_t += (double)(end_t - start_t);
	}

	avgT = total_t/i;

	ptiempo->N = N;
	ptiempo->n_elems = n_perms;
	ptiempo->min_ob = min;
	ptiempo->max_ob = max;
	ptiempo->max_ob = max;
	ptiempo->medio_ob = sum/i;
	ptiempo->tiempo = avgT;

	return OK;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{
	PTIEMPO tiempo = NULL;

	
	while(num_min <= num_max) {
		guarda_tabla_tiempos(fichero, tiempo, n_perms);
		num_min += incr;
	}
	return OK;
}

/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos)
{
	/*FILE *f = NULL;

	f = fopen(fichero, "w");
	if(!f)
		return ERR;

	fclose(f);*/
}


