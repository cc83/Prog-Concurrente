#include <malloc.h>
#include <time.h>
#include <sys/resource.h>

#include "Grid.h"
#include "Slab.h"
#include "Tests.h"


int get_size_from_n(int s){
	return 1 << s;
}

void remove_extreme_values(double* tab,int size) {
	int min_i=0;
 	int max_i=0;
 	for (int i=0; i<size; i++) {
	      if(tab[i]>tab[max_i]) max_i = i;
	      if(tab[i]<tab[min_i]) min_i = i;
    }
    
    int j = 0;
    for (int i=0; i<size; i++) 
	      if(i != max_i && i != min_i) tab[j++] = tab[i];
	      
    tab = realloc(tab,sizeof(double)*(size-2));

}

void compute_median_value(double* tab,int size,double* val){
	double a = 0;
	for (int i = 0;i< size;i++) 
		a+= (double) tab[i];
	*val = (double) a/size;
}



void print_time(int m,int M,double* cpu_times,double* user_times,int r_max) {
	if (m) {
		remove_extreme_values(cpu_times,r_max);
		double val;
		compute_median_value(cpu_times,r_max-2,&val);
		printf("Total CPU time per scenario (median): %lf s\n",val);
		free(cpu_times);
	
	}
	
	if (M) {
		remove_extreme_values(user_times,r_max);
		double val;
		compute_median_value(user_times,r_max-2,&val);
		printf("Total user time per scenario (median): %lf s\n",val);
		free(user_times);
	}
}

int main(){
	
	//options du programme
	int s = 0;
	short m = 0;
	short M = 0;
	short a = 0;
	int i = 50000;
	short e = 0;
	int t = 0;	

	void (*func)(Slab*,int,int); //la fonction correspondant au scenario voulu : iteratif, avec threads...



	int r_max=1; //le nombre de repetition du scenario pour faire une moyenne des temps de calcul

	if (m || M)
		r_max = 10;

	s+=4;
	int size = get_size_from_n(s); //correspondra a une grille de taille 16 si s=0

	Slab *slab = create_Slab(size,s,256.0);
	set_values_center(slab);

	
	if (!e)
		func = do_N_steps_iterative;


	if (!(m) && !(M))
		printf("/********** Program launched   ************/\n");


	clock_t start_t_cpu, end_t_cpu;
	time_t start_t_user,end_t_user;

	double* cpu_times;
	double* user_times;


	if (a && !(m) && !(M)) {
		printf("Initial temperatures");
		print_quarter_Slab(slab);
	}

	

	if (m)
		cpu_times = malloc(sizeof(double)*10);

	if (M)
		user_times = malloc(sizeof(double)*10);


	for (int r=0;r<r_max;r++) {
		if (m) 
			start_t_cpu = clock();
		if (M)
			start_t_user = time(NULL);

		func(slab,i,t); //appel du scenario voulu selon le parametre -e

		if (m) {
			end_t_cpu = clock();
			cpu_times[r] = (double)(end_t_cpu - start_t_cpu) / CLOCKS_PER_SEC;
		}

		if (M) {
			end_t_user = time(NULL);
			user_times[r] =  (double) end_t_user - start_t_user;

		}

	}



	if (a && !(m) && !(M) ) {
		printf("Final temperatures");
		print_quarter_Slab(slab);
	}


	print_time(m,M,cpu_times,user_times,r_max); //affichage des temps CPU et utilisateur si demandés avec -m et -M et libere la memoire
	
	

	

	destroy_Slab(slab);
	
	if (!(m) && !(M)) {
		struct rusage* use = malloc(sizeof(struct rusage));
		getrusage(RUSAGE_SELF,use);
		printf("Maximum RAM used : %ld kB\n",use->ru_maxrss);
		printf("/********** Program finished   ************/\n");
	}

}
