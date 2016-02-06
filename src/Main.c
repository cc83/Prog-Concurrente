#include <malloc.h>

#include "Grid.h"
#include "Slab.h"


int get_size_from_n(int s){
	return 1 << s;
}


int main(){
	
	int n = 0;
	n=n+4;
	int size = get_size_from_n(n); //correspondra a une grille de taille 16

	Slab *slab = create_Slab(size,n,256.0);

	set_values_center(slab);

	float* new_grid_horizontal = calloc(size*size,sizeof(float));
	for (int i = 0;i<12;i++) {
		do_step_iterative(slab,new_grid_horizontal);
	}


	
	print_Slab(slab);

}
