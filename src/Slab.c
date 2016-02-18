#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "Slab.h"
#include "Grid.h"


Slab* create_Slab(int size,int n,int base_value){
	Slab *slab = malloc(sizeof(Slab));
	float* grid = create_grid(size,size);
	slab->grid = grid;
	slab->size = size;
	slab->n = n;
	slab->base_value = base_value;
	return slab;
}


void destroy_Slab(Slab* s){
	free(s->grid);
	free(s);
}


void print_Slab(Slab* s) {
	print_grid(s->grid,s->size,s->size);
}

void print_quarter_Slab(Slab* s){
	printf("\n/****** Top left corner of the slab ******/\n");
	for(int i = 0;i< s->size/2;i++) {
		for(int j = 0;j< s->size/2;j++) {
			printf("%'.1f ",s->grid[i*s->size+j]);
		}
		printf("\n");
	}
	printf("\n");
}

void set_values_center(Slab* m){
	
	int a = 1 << (m->n-1);
	int b = 1 << (m->n-4);

	int from = a-b;
	int to = a+b;
	
	
	for (int i =from ;i<to;i++)
		for (int j =from ;j<to;j++)
			 m->grid[i*m->size+j] = m->base_value;

}





/*
	Realise l'echange de chaleur horizontal de la case de ligne l et de 
	colonne c situee dans prev_grid. Stocke le resultat dans new_grid.
*/
void h_transfert(int l,int c,int size,float* prev_grid,float* new_grid){

	new_grid[l*size+c] += prev_grid[l*size+c] * (4.0/6.0); 

	//On verifie qu'on est toujours sur la meme ligne lorsqu'on augmente de 1 le numero de la colonne
	if ((l*size+c+1)/size == l)
		new_grid[l*size+c+1] += prev_grid[l*size+c]/6.0;

	//On verifie qu'on est toujours sur la meme ligne et qu'on n'est pas au premier element 
	// lorsqu'on diminue de 1 le numero de la colonne
	if ( (l*size+c-1)>0 && (l*size+c-1)/size == l )
		new_grid[l*size+c-1] += prev_grid[l*size+c]/6.0;

}

void v_transfert(int l,int c,int size,float* prev_grid,float* new_grid){
	
	new_grid[l*size+c] += prev_grid[l*size+c] * (4.0/6.0); 

	if (l-1 >=0)
		new_grid[(l-1)*size+c] += prev_grid[l*size+c]/6.0;

	if (l+1 < size)
		new_grid[(l+1)*size+c] += prev_grid[l*size+c]/6.0;


}


