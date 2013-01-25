// igmv.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TIMES 100000000
int main(int argc, char* argv[])
{
	FILE *fmatrix;
	FILE *fvector;
	FILE *fresult;
	long long int start, end;
	int *matrix, *vector, *result;
	unsigned int w, h;
	char *fnm, *fnv, *fnr;
	int i,j, k;
	h = atoi(argv[1]);
	w = atoi(argv[2]);
	fnm = argv[3];
	fnv = argv[4];
	fnr = argv[5];
	matrix = (int*)malloc(sizeof(int)*w*h);
	vector = (int*)malloc(sizeof(int)*h);
	result = (int*)malloc(sizeof(int)*h);
	memset(result, 0, sizeof(int)*h);

	fmatrix = fopen(fnm, "rb");
	fread(matrix, sizeof(int), w*h, fmatrix);
	fclose(fmatrix);
	fvector = fopen(fnv, "rb");
	fread(vector, sizeof(int), h, fvector);
	fclose(fvector);
	start = time(NULL);
	for(k = 0; k < TIMES; k++){
		for(i=0; i<h; i++){
			result[i] = 0;
			for(j = 0; j<w; j++){
				result[i] += matrix[j*h+i]*vector[j];
			}
		}
	}
	end = time(NULL);
	printf("Time for execution in seconds: %i\n", end-start);

	return 0;
}
//10 10 d:\Work\dissertation_microprocessor\altera_projects\fpga_igmv\matrices\test_matrix.bin d:\Work\dissertation_microprocessor\altera_projects\fpga_igmv\matrices\test_vector.bin d:\Work\dissertation_microprocessor\altera_projects\fpga_igmv\matrices\test_result.bin
