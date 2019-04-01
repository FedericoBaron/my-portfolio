//Federico Baron
//8/26/18
//Solves a quadratic formula with real roots

#include <stdio.h>
#include <math.h>

int main(void){
	double a,b,c;
	printf("Please enter a, b and c from your quadratic.\n");
	scanf("%lf%lf%lf", &a,&b,&c);

	//calculate the discriminant
	double discriminant = pow(b,2)-4*a*c;
	return 0;

	//use that to calculate the two roots
	double root1 = (-b + sqrt(discriminant))/(2*a);
	double root2 = (-b - sqrt(discriminant))/(2*a);

	//print the roots
	printf("Roots are %.12lf and %.12lf.\n", root1, root2);
	return 0;
}
