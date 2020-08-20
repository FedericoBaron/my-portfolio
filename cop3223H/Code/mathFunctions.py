#Federico Baron
#8/27/18
import math

#x = math.ceil(3.7)
#print(x)
#math.fabs is absolute value
#math.factorial
#math.pow
#math.sqrt

#Solves a quadratic with real roots.

# Read in the coefficients to the quadratic
a=float(input("Please enter a from your quadratic equation.\n"))
b=float(input("Please enter b from your quadratic equation.\n"))
c=float(input("Please enter c from your quadratic equation.\n"))

#Calculate the discriminant
discriminant = math.pow(b,2) -4*a*c

#Calculate both roots
root1 = (-b + math.sqrt(discriminant))/(2*a)
root2 = (-b - math.sqrt(discriminant))/(2*a)

#print out the roots
print("The roots of your quadratic are",root1,"and",root2)
