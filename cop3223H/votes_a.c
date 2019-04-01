//Federico Baron
//8/26/18
//how many more votes?

#include <stdio.h>
int main(){
int candA, candB;
printf("How many votes does candidate A currently have?\n");
scanf("%d",&candA);
printf("How many votes does candidate B currently have?\n");
scanf("%d",&candB);
if(candA > candB){
	printf("Candidate B needs %d more votes to win the election.", candA-candB+1);
}
else{
	printf("Candidate A needs %d more votes to win the election.", candB-candA
		+1);
}
return 0;
}