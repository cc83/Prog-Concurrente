#ifndef SLAB_H
#define SLAB_H


typedef struct Slab Slab;

struct Slab{
	int n; //la puissance de 2 utilisee pour les dimensions
	int base_value;
	int size;
	float *grid;
};


Slab* create_Slab(int size,int n,int base_value);

void print_Slab(Slab* s);

void set_values_center(Slab* m);

void h_transfert(Slab* s,int l,int c,float* new_grid);

void v_transfert(Slab* s,int l,int c,float* new_grid);

void do_step_iterative(Slab* s,float* grid);

#endif