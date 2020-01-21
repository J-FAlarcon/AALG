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
#include <stdio.h>

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
	
	int i, *array, ob, max, min, sum, sumT;
	double total_time = 0.0;
	clock_t time1, time2;

	for(i = 0, max = min = sum = sumT = 0; i < n_perms; i++) {
		array = genera_perm(N);
		if(array==NULL) return ERR;
		time1 = clock();
		ob = metodo(array, 0, N-1);
		time2 = clock();
		if(max == 0 && min == 0) {
			max = min = ob;
		}
		if(ob > max)
			max = ob;
		if(ob < min)
			min = ob;
		sum += ob;
		
		free(array);
	}
	total_time = 1000000*(time2 - time1)/CLOCKS_PER_SEC;
	
	

	ptiempo->N = N;
	ptiempo->n_elems = n_perms;
	ptiempo->min_ob = min;
	ptiempo->max_ob = max;
	ptiempo->medio_ob = 1.*sum/i;
	ptiempo->tiempo = total_time;

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
	int i;
	
	tiempo=(PTIEMPO)malloc(n_perms * sizeof(TIEMPO));

	if(!tiempo)
		return ERR;

	for(i = 0; num_min <= num_max; i++) {
		tiempo_medio_ordenacion(metodo, n_perms,num_min, &tiempo[i]);
		num_min += incr;
	}

	if(guarda_tabla_tiempos(fichero, tiempo, i)==ERR) return ERR;

	free(tiempo);

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
	FILE *f = NULL;
	int i=0;

	f = fopen(fichero, "w");
	if(!f)
		return ERR;

	while(i<n_tiempos){
		fprintf(f, "N= %d Tiempo= %lf ns MedioOb= %.3lf MinOB= %d MaxOB= %d \n", tiempo[i].N,tiempo[i].tiempo,tiempo[i].medio_ob,tiempo[i].min_ob,tiempo[i].max_ob);
		i++;
	}

	fclose(f);

	return OK;
	
}


