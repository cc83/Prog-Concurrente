#include <malloc.h>

#include "Grid.h"
#include "Slab.h"


int get_size_from_n(int s){
	return 1 << s;
}


int main(){
	Slab *slab = malloc(sizeof(Slab));
	int n = 0;
	n=n+4;
	int size = get_size_from_n(n); //correspondra a une grille de taille 16

	
	float* grid = create_grid(size,size);
	slab->grid = grid;
	slab->size = size;
	slab->n = n;
	slab->base_value = 256.0;

	set_values_center(slab);

	float* new_grid_horizontal = calloc(size*size,sizeof(float));
	for (int i = 0;i<12;i++) {
		do_step_iterative(slab,new_grid_horizontal);
	}


	
	print_Slab(slab);

}
