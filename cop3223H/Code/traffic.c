//Traffic
//Federico Baron
//10/13/18

#include<stdio.h>

void checkIntersections();
void checkIfTrue();

int main(void){

	//initializes n which is number of test cases
	int n;

	//declares n to be user input 
	scanf("%d", &n);

	//runs for loop to do n test cases and calls function to do 1 test case at a time
	while(n > 0){

		//prints city number 
		printf("City #%d\n",i+1);

		//runs program
		checkIntersections();

		n--;
	}

	return 0;
}

//Pre-Condition: Does one test case
//Post-Condition: Prints whether there will be an accident or not for one test case
void checkIntersections(){

	//initializes k which is the amount of intersections
	int k;

	//declares k to be user input
	scanf("%d", &k);

	//initializes intersections to be an array k length
	int intersections[k]; 

	//goes through k roads and takes in input for how many intersections they have 
	for(int i = 0; i < k; i++){

		//saves the amount of intersections to its array space
		scanf("%d", &intersections[k]);

		//goes through the amount of intersections and just takes in input so the program runs as intended
		for(int j = 0; j < intersections[k]; j++)
			scanf("%d");
	}

	checkIfTrue(intersections);
}

void checkIfTrue(int intersections[]){
	//declares c which is the amount of blocks
	int c, test;

	//makes c user input
	scanf("%d", &c);

	for(int i = 0; i < c; i++){

		scanf("%d", &test);

		if(intersections[test-1] > 1)
			printf("yes\n");
		else
			printf("no\n");
	}


}