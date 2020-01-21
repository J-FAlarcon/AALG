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
#include <stdio.h>


/***************************************************/
/* Funcion: InsertSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int InsertSort(int* tabla, int ip, int iu) {
	int i, j, a, aux;

	if(!tabla||ip<0||iu<ip)return ERR;
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

int InsertSortInv(int* tabla, int ip, int iu){
		
	int i, j, a, aux;
	if(!tabla||ip<0||iu<ip)return ERR;
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


int mergesort(int* tabla, int ip, int iu){

	int m,ob=0;

	if(!tabla||ip<0||iu<ip)return ERR;

	if(ip==iu) return OK;

	else{
		m=(ip+iu)/2;

		ob+=mergesort(tabla,ip,m);

		ob+=mergesort(tabla,m+1,iu);

		ob+=merge(tabla,ip,iu,m);

	}

	return ob;
}


int merge(int* tabla, int ip, int iu, int imedio){

	int *tablaAux=NULL;
	int i,j,k,ob;

	if(!tabla||ip<0||iu<ip||imedio<0)return ERR;

	tablaAux=(int*)calloc(iu+1,sizeof(int));

	if(tablaAux==NULL)return ERR;


	

	for(i=ip,j=imedio+1,k=ip,ob=0;(i<=imedio) && (j<=iu);k++){

		if(tabla[i]<tabla[j]){
			tablaAux[k]=tabla[i];
			i++;
		}
		else{
			tablaAux[k]=tabla[j];
			j++;
		}
		ob++;
	}

	

	if(i>imedio){

		while(j<=iu){
			tablaAux[k]=tabla[j];
			j++;
			k++;
		}

	}

	else if(j>iu){
		while(i<=imedio){
			tablaAux[k]=tabla[i];
			i++;
			k++;
		}
	}


	for(i=ip;i<=iu;i++){ 
		tabla[i]=tablaAux[i];
	}

	free(tablaAux);

	

	return ob;

} 

 int quicksort(int* tabla, int ip, int iu){

	 int *m=NULL;
	 int OB=0;

	 if(!tabla||ip<0||iu<ip)return ERR;

	 if(ip==iu) return OK;


	m=(int*)malloc(sizeof(int));

	OB+=partir(tabla,ip,iu,m);

	if(ip<*m-1){

		OB+=quicksort(tabla,ip,*m-1);
	}

	if(*m+1<iu){

		OB+=quicksort(tabla,*m+1,iu);
	}

	free(m);
	return OB;

 }

int partir(int* tabla, int ip, int iu,int *pos){

	int OB=0,k,i;
	
	if(!tabla||ip<0||iu<ip||!pos)return ERR;

	OB+=medio(tabla,ip,iu,pos);

	k=tabla[*pos];

	swap(&tabla[ip],&tabla[*pos]);

	*pos=ip;

	for(i=ip+1;i<=iu;i++){

		OB++;
		if(tabla[i]<k){
			(*pos)++;
			swap(&tabla[i],&tabla[*pos]);
			
		}

	}

	swap(&tabla[ip],&tabla[*pos]);

	return OB;

}

int partir_avg(int* tabla, int ip, int iu,int *pos){

	int OB=0,k,i;

	if(!tabla||ip<0||iu<ip||!pos)return ERR;

	OB+=medio_stat(tabla,ip,iu,pos);

	k=tabla[*pos];

	swap(&tabla[ip],&tabla[*pos]);

	*pos=ip;

	for(i=ip+1;i<=iu;i++){

		OB++;
		if(tabla[i]<k){
			(*pos)++;
			swap(&tabla[i],&tabla[*pos]);
			
		}

	}

	swap(&tabla[ip],&tabla[*pos]);

	return OB;

}

int partir_medio(int* tabla, int ip, int iu,int *pos){

	int OB=0,k,i;

	if(!tabla||ip<0||iu<ip||!pos)return ERR;

	OB+=medio_avg(tabla,ip,iu,pos);

	k=tabla[*pos];

	swap(&tabla[ip],&tabla[*pos]);

	*pos=ip;

	for(i=ip+1;i<=iu;i++){

		OB++;
		if(tabla[i]<k){
			(*pos)++;
			swap(&tabla[i],&tabla[*pos]);
			
		}

	}

	swap(&tabla[ip],&tabla[*pos]);

	return OB;

}

 int medio(int *tabla, int ip, int iu,int *pos){

	 if(!tabla||ip<0||iu<ip||!pos)return ERR;

	 if(ip>iu)return ERR;

	 *pos=ip;

	 return 0;

 }

int medio_avg(int *tabla, int ip, int iu, int *pos){

	 if(!tabla||ip<0||iu<ip||!pos)return ERR;

	 if(ip>iu)return ERR;

	 *pos=(ip+iu)/2;

	return 0;
}

int medio_stat(int*tabla, int ip, int iu, int *pos) {

	int x,y,z;

	if(!tabla||ip<0||iu<ip||!pos)return ERR;

	if(ip>iu)return ERR;

	medio_avg(tabla, ip,iu,pos);

	x=tabla[ip];
	
	y=tabla[iu];

	z=tabla[*pos];


	
	if(x>y){
		if(y>z){
			*pos=iu;
		}
		if(x<z){
			*pos=ip;
		}

		
	} 

	
	
	return 3;
	
}












 void swap(int*x, int*y){

	 int aux;

	aux=*x;
	*x=*y;
	*y=aux;

	return;

 }