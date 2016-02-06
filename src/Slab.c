#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "Slab.h"
#include "Grid.h"

void print_Slab(Slab* s) {
	print_grid(s->grid,s->size,s->size);
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


void destroy_Slab(Slab* m){
	free(m->grid);
}




void h_transfert(Slab* s,int l, int c,float* new_grid){
	int size = s->size;

	new_grid[l*size+c] += s->grid[l*size+c] * (4.0/6.0); 

	if ((l*size+c+1)/size == l)
		new_grid[l*size+c+1] += s->grid[l*size+c]/6.0;

	if ((l*size+c-1)/size == l)
		new_grid[l*size+c-1] += s->grid[l*size+c]/6.0;

}

void v_transfert(Slab* s,int l, int c,float* new_grid){
	int size = s->size;

	new_grid[l*size+c] += s->grid[l*size+c] * (4.0/6.0); 

	if (l-1 >=0)
		new_grid[(l-1)*size+c] += s->grid[l*size+c]/6.0;

	if (l+1 < s->size)
		new_grid[(l+1)*size+c] += s->grid[l*size+c]/6.0;


}


void do_step_iterative(Slab* s,float* grid){
	int size = s->size;

	for (int i =0;i<size;i++) {
		for (int j =0;j<size;j++) {
			h_transfert(s,i,j,grid);
		}
	}

	memcpy(s->grid,grid,sizeof(float)*size*size);

	clear_grid(grid,size);

	for (int i =0;i<size;i++) {
		for (int j =0;j<size;j++) {
			v_transfert(s,i,j,grid);
		}
	}

	memcpy(s->grid,grid,sizeof(float)*size*size);

	clear_grid(grid,size);

	set_values_center(s);

}

