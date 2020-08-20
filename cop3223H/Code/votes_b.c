//Federico Baron
//8/26/18
//Calculates how many new voters candidate A needs to win the election.

#include <stdio.h>
int main(){

//declares integer variables
int candA, candB;

//gets the current amount of votes candidate A has
printf("How many votes does candidate A currently have?\n");
scanf("%d",&candA);

//gets the current amount of votes candidate B has
printf("How many votes does candidate B currently have?\n");
scanf("%d",&candB);

//prints result of how many people will need to switch their vote
printf("Candidate A needs %d people to switch their vote.", (candB-candA)/2+1);

return 0;

}