//Kristen and Federico 
//10/5/18
//Permutations

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArrayList.h"

void doperm();
int fact(int n);

int main(void){

	//initializes variables
	int cases;

	//takes number of test cases
	scanf("%d\n",&cases);

	for(int i = 0; i < cases; i++)
		doperm();

	return 0;
}

void doperm(){
	//initializes variables
	int n, k;

	//takes input for a test case
	scanf("%d %d", &n, &k);

	//sets k to k-1;
	k--;

	//Creates arraylist for n numbers in order
	ArrayList numlist;

	//adds all n numbers in order to numlist
	for(int i = 0; i <= n; i++)
		arraylist_add(numlist, &i);

	//creates list in which the answer is stored
	ArrayList answer;

	//sets n to n - 1
	n--;

	//gets first digit of answer
	arraylist_add(answer, &(k/fact(n)));

	//removes used digit from numlist
	arraylist_remove(numlist, &(k/fact(n)));

	//makes factorial number
	int factnum = n;

	//gets every other digit, except the last two
	for(int i = 1; i < n-1; i++){

		//adds digit to arraylist in order to find kth sequence
		arraylist_add(answer, &(k/fact(factnum-1))%arraylist_size(numlist));

		//makes factorial one less for next comparison
		factnum--;

		//removes digits from ordered list 
		arraylist_remove(numlist, &(k/fact(factnum-1))%arraylist_size(numlist));

	}

	//gets last two digits
	if(k % 2 == 1){
		arraylist_add(arraylist_get(numlist,0));
		arraylist_add(arraylist_get(numlist,1));
	}
	else{
		arraylist_add(arraylist_get(numlist,1));
		arraylist_add(arraylist_get(numlist,0));
	}

	for(int i = 0; i < arraylist_size(answer)-1; i++)
		printf("%d, ", arraylist_get(answer, i));

	printf("%d", arraylist_get(answer,arraylist_size(answer)-1));
	

}

//Pre-Condition: n is a non-negative integer
//Post-Condition: returns an integer which is the result of n factorial
int fact(int n){

	//declares factorial
	int factorial = 1;

	//does n factorial and saves it on variable "factorial"
	for(int i = n; i > 0; i--){
		factorial *= i;
	}

	//returns n!
	return factorial;
}

//initialize 2 arraylists one with digits used and one with the formed number
//to get first number do 


