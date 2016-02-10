#include <malloc.h>
#include <time.h>
#include <sys/resource.h>

#include "Grid.h"
#include "Slab.h"


int get_size_from_n(int s){
	return 1 << s;
}


int main(){
	
	int n = 0;

	clock_t start_t_cpu, end_t_cpu, total_t_cpu;
	time_t start_t_user,end_t_user,total_t_user;

	n=n+4;
	int size = get_size_from_n(n); //correspondra a une grille de taille 16 si n=0

	Slab *slab = create_Slab(size,n,256.0);
	set_values_center(slab);

	

	start_t_cpu = clock();
	start_t_user = time(NULL);

	do_N_steps_iterative(slab,100);

	end_t_cpu = clock();
	end_t_user = time(NULL);

	total_t_cpu = (double)(end_t_cpu - start_t_cpu) / CLOCKS_PER_SEC;
	total_t_user = end_t_user - start_t_user;

	

	// print_Slab(slab);
	printf("Total CPU time : %ld s\nTotal user time : %ld s\n",total_t_cpu,total_t_user);

	struct rusage* use = malloc(sizeof(struct rusage));
	getrusage(RUSAGE_SELF,use);
	printf("Maximum RAM used : %ld kB\n",use->ru_maxrss);

	destroy_Slab(slab);
	
	


}
