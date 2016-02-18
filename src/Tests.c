#include <malloc.h>

#include "Tests.h"
#include "Grid.h"

void do_step_iterative(Slab* s,float* grid){
	int size = s->size;

	for (int i =0;i<size;i++) {
		for (int j =0;j<size;j++) {
			h_transfert(i,j,size,s->grid,grid);
		}
	}


	clear_grid(s->grid,size);

	for (int i =0;i<size;i++) {
		for (int j =0;j<size;j++) {
			v_transfert(i,j,size,grid,s->grid);
		}
	}


	clear_grid(grid,size);

	set_values_center(s);

}

/**
	Realise n etapes de diffusion de chaleur de façon iterative, t est le nombre de threads 
	Ici t est inutile mais il sert pour povoir declarer un pointeur sur fonction dans le main
*/
void do_N_steps_iterative(Slab* s,int n,int t) {
	if (t) {}; //pour supprimer les warnings

	float* new_grid = create_grid(s->size,s->size);

	for (int i = 0;i<n;i++) {
		do_step_iterative(s,new_grid);
	}

	free(new_grid);

}