#include <malloc.h>
#include <stdio.h>

#include "Grid.h"



float* create_grid(int x,int y) {
	float* grid = calloc(x*y,sizeof(float));
	return grid;
}

void print_grid(float* grid,int len,int wid){
	for (int i =0;i<len;i++){
		for (int j = 0;j<wid;j++) {
			printf("%'.1f ",grid[i*len+j] );
		}
		printf("\n");
	}
}


void clear_grid(float* grid, int size) {
	for (int i=0; i<size*size; i++)
		grid[i] = 0.0;
}