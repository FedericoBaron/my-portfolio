//Federico Baron
//9/6/18
//sum of leap years

#include <stdio.h>

//function declarations
int getNextMultiple(int mult, int first);
int getPrevMultiple(int mult, int last);
int getAmountMults(int first, int last, int mult);
int sumArithSeries(int n, int a1, int an);

int main(){

	//declares starting and ending year integers
	int a1, an, total, a1l, anl, ltotal, a1ll, anll, lltotal, aa1;
	double n, nl, nll;

	//asks for input for starting year
	printf("What is the starting year?");
	scanf("%d", &a1);

	//asks for input for ending year
	printf("What is the ending year?");
	scanf("%d", &an);

	//calculates sum
	total = sumArithSeries(getAmountMults(getNextMultiple(4,a1),getPrevMultiple(4,an),4),getNextMultiple(4,a1),getPrevMultiple(4,an));

	//calculates sum for mult 100
	ltotal = sumArithSeries(getAmountMults(getNextMultiple(100,a1),getPrevMultiple(100,an),100),getNextMultiple(100,a1),getPrevMultiple(100,an));

	//calculates sum for mult 400
	lltotal = sumArithSeries(getAmountMults(getNextMultiple(400,a1),getPrevMultiple(400,an),400),getNextMultiple(400,a1),getPrevMultiple(400,an));


	//prints result  by adding sum mult 4 and sum mult 400 and subtracting sum of mult 100
	printf("The sum of leap years in between %d and %d is %d.\n",a1,an,total-ltotal+lltotal);

	return 0;

}

	//pre condition: mult and first are non-negative integers
	//post condition: returns first multiple of n
	int getNextMultiple(int mult, int first){
		if(first % mult != 0){
			first = first + (mult - first % mult);
		}
		return first;
	}

	//pre condition: mult and last are non-negative integers
	//post condition: gets last multiple of a number
	int getPrevMultiple(int mult, int last){
		if(last % mult != 0){
			last = last - (last % mult);
		}
		return last;
	}

	//pre condition: first, last, and mult are non-negative integers
	//post condition: calculates number of multiples of a number
	int getAmountMults(int first, int last, int mult){
		return(last / mult - first / mult + 1);
	}

	//pre condition: n, a1, an, mult are non-negative integers
	//post condition: gets total sum of arithmetic series
	int sumArithSeries(int n, int a1, int an){
		return(n / 2.0 * (a1 + an));
	}


