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
#include "busqueda.h"

#define _GNU_SOURCE

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
	
	int i, *array, ob, max, min, sum,total=0;
	double total_time = 0.0;
	clock_t start, stop;

	for(i = 0, max = min = sum= 0; i < n_perms; i++) {
		array = genera_perm(N);
		if(array==NULL) return ERR;
		start= clock();
		ob = metodo(array, 0, N-1);
		stop=clock();
		
		if(max == 0 && min == 0) {
			max = min = ob;
		}
		if(ob > max)
			max = ob;
		if(ob < min)
			min = ob;
		sum += ob;
		total+= stop-start;


		free(array);
	}
	
	

	total_time=(double)(total/n_perms)/(double)CLOCKS_PER_SEC;

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
		  fprintf(f, "N= %d Tiempo= %.12f  MedioOb= %.3f MinOB= %d MaxOB= %d \n", tiempo[i].N,tiempo[i].tiempo,tiempo[i].medio_ob,tiempo[i].min_ob,tiempo[i].max_ob); 


		 i++;
	}

	fclose(f);

	return OK;
	
}



short genera_tiempos_busqueda(pfunc_busqueda metodo, pfunc_generador_claves generador, int orden, char* fichero,  int num_min, int num_max,    int incr, int n_veces){


	PTIEMPO tiempo = NULL;
	int i;
	int espacio;

	espacio=((num_max-num_min)/incr) +1;
	tiempo=(PTIEMPO)malloc(espacio * sizeof(TIEMPO));

	if(!tiempo)
		return ERR;

	for(i = 0; num_min <= num_max; i++) {
		tiempo_medio_busqueda(metodo, generador,orden,num_min,n_veces, &tiempo[i]);
		num_min += incr;
	}

	if(guarda_tabla_tiempos(fichero, tiempo, i)==ERR) return ERR;

	free(tiempo);

	return OK;


}












short tiempo_medio_busqueda(pfunc_busqueda metodo, pfunc_generador_claves generador,
int orden,int N,int n_veces,PTIEMPO ptiempo){

	int i,ob,min,max,sum,num=n_veces*N;
	PDICC dicc=NULL;
	int* perm;
	int* pos;
	int* claves;
	clock_t start, stop;
	double total_time,total=0;
	
	pos=(int*)malloc(sizeof(int));

	if(!pos)return ERR;
	
	claves=(int*)malloc(num*sizeof(int));
	
	if(!claves)return ERR;


	for(i=0;i<n_veces;i++){


		
		
		dicc=ini_diccionario(N, orden);

		
		perm=genera_perm(N);

		

		insercion_masiva_diccionario(dicc,perm, N);

		

		if(!claves)return ERR;

		generador(claves,num,N);



		for(i=0,min=0,max=0,sum=0,ob=0;i<num;i++){
				
				
				start= clock();
			
				ob=busca_diccionario(dicc,claves[i], pos,  metodo);
				
				stop=clock();

			

				if(max == 0 && min == 0) {
					max = min = ob;
				}
				if(ob > max)
					max = ob;
				if(ob < min)
					min = ob;

				sum += ob;

				
				total+= stop-start;
		}

		free(perm);
		libera_diccionario(dicc);
	}

	total_time=(double)(total/num)/(double)CLOCKS_PER_SEC;

	ptiempo->N = N;
	ptiempo->n_elems = num;
	ptiempo->min_ob = min;
	ptiempo->max_ob = max;
	ptiempo->medio_ob = 1.*sum/i;
	ptiempo->tiempo = total_time;

	free(claves);
	free(pos);
	

	return OK;
}


