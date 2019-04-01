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
	int a1, an, total, a1l, anl, ltotal, a1ll, anll, lltotal;
	double n, nl, nll;

	//asks for input for starting year
	printf("What is the starting year?");
	scanf("%d", &a1);

	//asks for input for ending year
	printf("What is the ending year?");
	scanf("%d", &an);

	//calculates sum
	a1 = getFirst(4,a1);
	an = getLast(4,an);
	n = getAmountMults(a1,an,4);
	total = getTotal(n,a1,an,4);

	//calculates sum for mult 100
	a1l = getFirst(100,a1);
	anl = getLast(100,an);
	nl = getAmountMults(a1l,anl,100);
	ltotal = getTotal(nl,a1l,anl,100);

	//calculates sum for mult 400
	a1ll = getFirst(400,a1);
	anll = getLast(400,an);
	nll = getAmountMults(a1ll,anll,400);
	lltotal = getTotal(nll,a1ll,anll,400);


	//prints result  by adding sum mult 4 and sum mult 400 and subtracting sum of mult 100
	printf("%d\n",total-ltotal+lltotal);

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


