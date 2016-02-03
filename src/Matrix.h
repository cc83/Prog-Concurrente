#include <stdio.h>



typedef struct Matrix Matrix;

struct Matrix{
	int n; //la puissance de 2 utilisee pour les dimensions
	int height;
	int width;
	int *grid;


};

int * create_grid(int x,int y);

void print_Matrix(Matrix* m);

int pos_grid(int,int,Matrix*);