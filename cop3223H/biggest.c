#include <math.h>

int biggestChange(int seq[], int length){
	biggest = 0;
	for(int i = 0; i < length-1; i++){
		if(abs(seq[i]-seq[i+1])>biggest)
			biggest = abs(seq[i]-seq[i+1]);
	}
	return biggest;
}

double count = 0.0;
int people = 0;

for(int i = 0; i < 10; i++){
	people+= freq[i];
	count = freq[i]*i;
}
return count/people;