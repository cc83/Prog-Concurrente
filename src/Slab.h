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

void destroy_Slab(Slab* s);

void print_Slab(Slab* s);

void print_quarter_Slab(Slab* s);

void set_values_center(Slab* m);

void h_transfert(int l,int c,int size,float* prev_grid,float* new_grid);

void v_transfert(int l,int c,int size,float* prev_grid,float* new_grid);



#endif