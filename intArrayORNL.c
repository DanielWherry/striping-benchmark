#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){

	const int SIZE = 100;
	int* integers;
	integers = (int *)malloc(SIZE*sizeof(int));
	
	if(strcmp(argv[1],"--create") == 0){	
	
		FILE *outfile;

		outfile = fopen(argv[2],"w");

		for(int i = 0; i < SIZE; i++){
			integers[i] = i;
		}
		fwrite(integers, sizeof(int), SIZE ,outfile);
		printf("Created\n");
	
		free(integers);
		fclose(outfile);
		return 0;
		
	}else if(strcmp(argv[1],"--verify") == 0){

		FILE *infile;
	
		infile = fopen(argv[2],"r");
		fread(integers, sizeof(int), SIZE, infile);
	
		for(int i = 0; i < SIZE; i++){
			if(integers[i] != i){			
				printf("The files are not the same!!\n");
				free(integers);
				fclose(infile);
				return 0;
				
			}
		}
	
		
		printf("The files are equivalent!\n");
		free(integers);
		fclose(infile);
		return 0;

	}	
	
	return 0;
}
	
