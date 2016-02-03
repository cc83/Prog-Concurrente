#include "Matrix.h"
#include <malloc.h>

int * create_grid(int x,int y) {
	int* grid = malloc(x*y*sizeof(int));
	return grid;
}


void print_Matrix(Matrix* m) {
	for (int i =0;i<m->height;i++){
		for (int j = 0;j<m->width;j++) {
			printf("%d ",m->grid[i*m->height+j] );
		}
		printf("\n");
	}

}

void set_values_center(Matrix* m,int value){
	int a = 1 << (m->n-1);
	int b = 1 << (m->n-4);

	int from = a-b;
	int to = a+b;
	
	
	for (int i =from ;i<to;i++)
		for (int j =from ;j<to;j++)
			 m->grid[i*m->height+j] = value;

			

}

int get_size_from_n(int s){
	return 1 << s;
}

void destroy_Matrix(Matrix* m){
	free(m->grid);
}

int main(){
	Matrix *m = malloc(sizeof(Matrix));
	int n = 0;
	n=n+4;
	int size = get_size_from_n(n); //correspondra a une grille de taille 16
	
	int* grid = create_grid(size,size);
	m->grid = grid;
	m->height = size;
	m->width = size;
	m->n = n;

	set_values_center(m,256);

	print_Matrix(m);
	
	destroy_Matrix(m);
	free(m);

}