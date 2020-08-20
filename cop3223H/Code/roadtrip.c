//Federico Baron
//8/22/18
//calculates amount of money required for the roadtrip
#include <stdio.h>
int main(void) {
  //gasPrice is the price of gas per gallon
  //gasInCar is the amount of fuel left in the car in gallons
  //mpg is the miles per gallon the car does
  //tripLen is how long the trip is in miles
  //total is the calculation of how much money will need to be spent
  double gasPrice, gasInCar, mpg, tripLen;
  printf("What is the price of gasoline?\n");
  scanf("%lf",&gasPrice);
  printf("How many gallons of gas are in the car?");
  scanf("%lf",&gasInCar);
  printf("How many miles per gallon does your car get?");
  scanf("%lf",&mpg);
  printf("How long is your road trip in miles?");
  scanf("%lf",&tripLen);
  //calculates total to be spent
  double total = (tripLen/mpg-gasInCar)*gasPrice;
  printf("You need to spend $ %.2lf on extra gas to complete the trip.", total);
  return 0;
}