//Federico Baron
//9/12/18
//Cubbies

#include<stdio.h>
#include<stdlib.h>

int main(void){

	//int declaration
	int r, c, h, w;
	
	//defines number of rows and columns for cubbies
	printf("Please enter the number of rows and colums for the cubbies\n");
	scanf("%d %d", &r, &c);

	//defines height and width for the cubbies
	printf("Please enter the height and width for the cubbies\n");
	scanf("%d %d", &h, &w);

	//defines the length of the long line
	int rowlen = w * c + 1;

	int numspaces = ((rowlen - 1) / c) - 1;

	//draws cubbies
	for (int j = 0; j < r; j++){

		//makes long line
		for(int i = 0; i < rowlen; i++){
			printf("*");
		}

		//goes to new line
		printf("\n");

		//makes part of cube with spaces
		for(int l = 0; l < h - 1; l++){
			for(int i = 0; i < c; i++){
				printf("*");
				for(int k = 0; k < numspaces; k++){
					printf(" ");
				}
			}
			printf("*\n");
		}
	}

	//makes long line to finish cubes
	for(int i = 0; i < rowlen; i++){
		printf("*");
	}

	return 0;

}