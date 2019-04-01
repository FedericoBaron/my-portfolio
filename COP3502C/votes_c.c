//Federico Baron
//8/26/18
//Calculates how many more voters candidate A will need to win the election by a margin of 1000

#include <stdio.h>
#include <stdlib.h>
int main(){

//declares integer and double variables
double candA, candB, percentA;
int count = 0;

//gets how many votes candidate A has
printf("How many votes does candidate A currently have?\n");
scanf("%lf",&candA);

//gets how many votes candidate B has
printf("How many votes does candidate B currently have?\n");
scanf("%lf",&candB);

//gets what percentage of new voters will vote for candidate A
printf("What percentage of new voters will vote for candidate A?\n");
scanf("%lf",&percentA);

//Calculates how many new voters A needs

/*

this was the non-mathematical/inefficient way of doing it

while(candA-candB<=1000){
	candA=candA+(percentA/100.0);
	candB=candB+(100-percentA)/100.0;
	count++;
}

*/

//This is the mathematical way (the right way)
int total = (candB-candA+1000)/((percentA/100)-((100-percentA)/100));

//prints resulting amount of voters needed for A to win by a margin of 1000
printf("Candidate A will need %d more voters", total);

return 0;

}