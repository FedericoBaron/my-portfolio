//Federico Baron
//9/3/18
//Calculates taxes

#include <stdio.h>
int main(){
//declares variables
double income, tax;

//gets input for income and assigns it to variable "income"
printf("What is your annual income?\n");
scanf("%lf",&income);

//defines baseline income and tax
tax = 0.0;
income = income - 20000;

//tax bracket 20,000/40,000
if(income > 0 && income <= 20000){
	tax = tax + income * 0.1;
	income = 0;
}
else if(income > 20000){
	tax = tax + 20000 * 0.1;
	income = income-20000;
}

//tax bracket 40,000/80,000
if(income > 0 && income <= 40000){
	tax = tax + income * 0.2;
	income = 0;
}
else if(income > 40000){
	tax = tax + 40000 * 0.2;
	income = income - 40000;
}

//tax bracket >80,000
if(income > 0){
	tax = tax + income * 0.3;
}

//prints resulting income tax
printf("You owe $%.2lf in income tax.",tax);

return 0;
}
