#include <stdio.h>

#define ICE_DENSITY .1
#define PI 3.14

double sphere_vol(double r);
double calc_mass(double vol, double density);

int main(void){

	double smallR, midR, bigR;
	printf("Please enter the three radii, smallest to largest of your snowman in cm\n");
	scanf("%lf%lf%lf", &smallR, &midR, &bigR);

	//sum up the volumes of the trhee spheres
	double volume = sphere_vol(smallR) + sphere_vol(midR) + sphere_vol(bigR);

	//calculate mass of snowman
	double mass = calc_mass(volume, ICE_DENSITY);

	printf("The mass of the snowman is %lf grams.\n",mass);

	return 0;
}

//pre condition r >= 0
//post condition: returns the volume of a sphere with radius r
double sphere_vol(double r){
	return 4.0 / 3 * PI * r * r * r;
}

//pre condition vol is non-negative and density is positive
//post condition returns the mass of an object with the volume
double calc_mass(double vol, double density){
	return vol * density;
}