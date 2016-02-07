#include <malloc.h>

#include "Grid.h"
#include "Slab.h"


int get_size_from_n(int s){
	return 1 << s;
}


int main(){
	
	int n = 0;



	n=n+4;
	int size = get_size_from_n(n); //correspondra a une grille de taille 16 si n=0

	Slab *slab = create_Slab(size,n,256.0);
	set_values_center(slab);

	float* new_grid = create_grid(size,size);
	printf("%p %p\n",slab->grid,new_grid);
	for (int i = 0;i<8;i++) {
		do_step_iterative(slab,new_grid);
	}


	print_Slab(slab);

	
	destroy_Slab(slab);
	free(new_grid);


}
