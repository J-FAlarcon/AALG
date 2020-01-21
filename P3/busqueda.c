/**
 *
 * Descripcion: Implementacion funciones para busqueda 
 *
 * Fichero: busqueda.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 11-11-2016
 *
 */

#include "busqueda.h"


#include <stdlib.h>
#include <math.h>
#include <stdio.h>


/**
 *  Funciones de geracion de claves
 *
 *  Descripcion: Recibe el numero de claves que hay que generar
 *               en el parametro n_claves. Las claves generadas
 *               iran de 1 a max. Las claves se devuelven en 
 *               el parametro claves que se debe reservar externamente
 *               a la funcion.
 */
  
/**
 *  Funcion: generador_claves_uniforme
 *               Esta fucnion genera todas las claves de 1 a max de forma 
 *               secuencial. Si n_claves==max entonces se generan cada clave
 *               una unica vez.
 */
void generador_claves_uniforme(int *claves, int n_claves, int max)
{
  int i;


  for(i = 0; i < n_claves; i++) {
    
    

    claves[i] = (i % max);

   

  }
  
  return;
}

/**
 *  Funcion: generador_claves_potencial
 *               Esta funcion genera siguiendo una distribucion aproximadamente
 *               potencial. Siendo los valores mas pequenos mucho mas probables
 *               que los mas grandes. El valor 1 tiene una probabilidad del 50%,
 *               el dos del 17%, el tres el 9%, etc.
 */
void generador_claves_potencial(int *claves, int n_claves, int max){
  int i;

  for(i = 0; i < n_claves; i++) {
    claves[i] =  (.5+max/(1 + max*(double)rand()/(RAND_MAX)))-1;
  }

  return;
}

PDICC ini_diccionario (int tamanio, char orden){
	/* vuestro codigo */
  PDICC dicc = NULL;

  dicc=(PDICC)malloc(tamanio*sizeof(DICC));

  if(!dicc)return NULL;


  dicc->tamanio=tamanio;

  dicc->n_datos=0;

  dicc->orden= orden;


  dicc->tabla=(int*)malloc(tamanio*sizeof(int));

  if(!dicc->tabla)return NULL;

  return dicc;

}

void libera_diccionario(PDICC pdicc){
	/* vuestro codigo */

 free(pdicc->tabla);

 free(pdicc); 

}

int inserta_diccionario(PDICC pdicc, int clave){
	/* vuestro codigo */
  int ob=0;
  /*int A,j; */
  if(!pdicc->tabla || clave < 0)
		return ERR;

	pdicc->tabla[pdicc->n_datos] = clave;

  
	

  
	if(pdicc->orden == ORDENADO) {

		ob= InsertSort(pdicc->tabla, 0, pdicc->n_datos);

    /* A=pdicc->tabla[pdicc->n_datos];
    j=pdicc->n_datos-1;

    while (j >= 0 && pdicc->tabla[j]>A){
      pdicc->tabla[j+1]=pdicc->tabla[j];
      j--;
      
    }
    pdicc->tabla[j+1]=A;
    */
    
  } 
  
  else if(pdicc->orden == NO_ORDENADO){
    pdicc->n_datos++;
		return ob;
  }
    else {
		  return ERR;
  }
  
  pdicc->n_datos++;

  return ob;
}

int insercion_masiva_diccionario (PDICC pdicc,int *claves, int n_claves){
	/* vuestro codigo */

  int i;

	if(!pdicc->tabla || !claves || n_claves < 1)
		return ERR;

	for(i = 0; i < n_claves; i++) {
		if(inserta_diccionario(pdicc, claves[i]) == ERR) 
			return ERR;
	}

  
	
	return OK;

}

int busca_diccionario(PDICC pdicc, int clave, int *ppos, pfunc_busqueda metodo){
	/* vuestro codigo */


  return metodo(pdicc->tabla,0,pdicc->n_datos,clave,ppos);

}


/* Funciones de busqueda del TAD Diccionario */
int bbin(int *tabla,int P,int U,int clave,int *ppos){
	/* vuestro codigo */
  int mitad,i=0;

  
  while(P<=U){

  
    mitad=(P+U)/2;
    i++;

     
      if(tabla[mitad]==clave){

        *ppos=mitad;
        return i;
        
      } 

      else if(tabla[mitad]>clave){
        
          U=mitad-1;
      }

      else{

         
          P=mitad+1;
      }

  
     
  }

    *ppos= NO_ENCONTRADO;

    return i;

}

int blin(int *tabla,int P,int U,int clave,int *ppos){

	/* vuestro codigo */

  int i;

	if(!tabla || P < 0 || U < P || clave < 0 || !ppos)
		return ERR;

	for(i = 0; i < U; i++) {
	
  	if(clave == tabla[i]){
			*ppos = i;
			return i + 1;
		}

	}

  *ppos= NO_ENCONTRADO;
	return i; 

}

int blin_auto(int *tabla,int P,int U,int clave,int *ppos){
	/* vuestro codigo */


	int i;

  
	if(!tabla || P < 0 || U < P || clave < 0 || !ppos)
		return ERR;


    for(i = 0; i < U; i++) {

      if(clave == tabla[i]){

        if (i > 0) {
          swap(&tabla[i],&tabla[i-1]);
        }

        *ppos = i;
        return i + 1;

      }
      
    }

	*ppos= NO_ENCONTRADO;
	return i; 

}


