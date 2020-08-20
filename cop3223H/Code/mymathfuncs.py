# Federico Baron
# 9/26/2018
# Square root and log
# This is a small math library.

MY_PI = 3.14159265358979

# "Constants" for menu choices
POWER = 1
FACT = 2
EXP = 3
SIN = 4
COS = 5
TAN = 6
NLOG = 7
ROOT = 8
QUIT = 9

# Prints out all of the menu choices.
def printchoices():
    print("1. Calculate an exponent.")
    print("2. Calculate a factorial.")
    print("3. Calculate e raised to an exponent.")
    print("4. Calculate sin of an angle.")
    print("5. Calculate cos of an angle.")
    print("6. Calculate tan of an angle.")
    print("7. Calculate natural log.")
    print("8. Calculate square root.")
    print("9. Quit.")

# Prompts the user with the menu and returns their first valid entered choice.
def menu():

    # Get first choice.
    printchoices()
    choice = int(input("Which menu selection would you like to make?\n"))

    # Keep on going until a choice is valid.
    while choice < 1 or choice > QUIT:
        print("Sorry, that is not a valid choice.")
        printchoices()
        choice = int(input("Which menu selection would you like to make?\n"))

    # Just return it.
    return choice

# Pre-condition: exp must be an integer. If base is 0, exp can't be negative.
# Post-condition: returns base raised to the power exp.
def mypow(base, exp):

    # Maps negative exponent case to positive exponent case.
    if exp < 0:
        exp = -exp
        base = 1/base

    # Multiply base into res exactly exp times.
    res = 1
    for i in range(exp):
        res *= base

    return res

# Pre-condition: n must be a non-negative integer.
# Post-condition: Returns n!
def myfact(n):

    # Multiply each integer from 1 to n into res.
    res = 1
    for i in range(1,n+1):
        res *= i
    return res

# Pre-condition: x is a real number
# Post-condition: returns the absolute value of x.
def myabs(x):
    if x < 0:
        return -x
    return x

# Returns e raised to the power x.
def myexp(x):

    res = 0

    # Max times this will run is 100.
    for i in range(100):

        # Get this term and add it in.
        term = mypow(x,i)/myfact(i)
        res += term

        # It's so small, we can break out.
        if myabs(term) < 1e-9:
            break

    return res

# Returns e raised to the power x.
def mysin(x):

    res = 0
    sign = 1

    # Max times this will run is 100.
    for i in range(1,100,2):

        # Get this term and add it in.
        term = mypow(x,i)/myfact(i)
        res += (sign*term)

        # Flip so next term is opposite.
        sign = -sign

        # It's so small, we can break out.
        if myabs(term) < 1e-9:
            break

    return res

# Uses a trig formula to calculate cosine!
def myothercos(x):
    return mysin(MY_PI/2 - x)

# Returns e raised to the power x.
def mycos(x):

    res = 0
    sign = 1

    # Max times this will run is 100.
    for i in range(0,100,2):

        # Get this term and add it in.
        term = mypow(x,i)/myfact(i)
        res += (sign*term)

        # Flip so next term is opposite.
        sign = -sign

        # It's so small, we can break out.
        if myabs(term) < 1e-9:
            break

    return res

# Pre-condition: x can't be pi/2, 3pi/2 or any other equivalent angle.
# Post-condition: returns the tangent of x.
def mytan(x):
    return mysin(x)/mycos(x)

#Pre-condition: x must be positive
#Post-condition: returns the natural log of x
def nlog(x):

    #chekcs if x is 1
    if x == 1:
        return 0
    #checks if x is less than 1
    elif x < 1:
        x = 1/x
        flag = False

    #defines low, high and mid
    low = 0.0
    high = 25.0
    mid = (low + high) / 2
        

    #begins while loop for binary search to keep re-setting mid
    while(True):

        #checks if high needs to be mid
        if(myexp(mid) > x):
            high = mid

        #checks if low needs to be mid
        elif(myexp(mid) < x):
            low = mid

        #sets temp to mid to check if number is found
        temp = mid
        mid = (low + high) / 2

        #checks if number is found, if so returns mid
        if(mid == temp):
            if(flag):
                return mid
            else:
                return -mid
        
    return mid

#Pre-Condition: x can't be a negative number
#Post-Condition: returns the square root of x
def root(x):

    #defines low and high for square root
    low = 0.0
    high = 0.0
    mid = 0.0

    #sets low and high values for square root function
    if(x < 1):
        low = x
        high = 1.0
    elif(x > 1):
        low = 1.0
        high = x
    else:
        return 1

    #sets original mid value
    mid = (low + high) / 2

    #while loop to find root performs binary search until finding a mid number that makes x when squared
    while(True):

        #checks if x is less than mid squared
        if(x < mid * mid):
            high = mid

        #checks if x is greater than mid squared
        elif(x > mid * mid):
            low = mid

        #sets temp equal to mid to see if while loop should end because the value was found
        temp = mid
        mid = (low + high) / 2

        #if mid is equal to temp mid is returned and program ends
        if(mid == temp):
            return mid;
    return mid
        
    
    

# Runs the main program.
def main():

    # Get user's choice.
    choice = menu()

    # Process until the user wants to quit.
    while choice != QUIT:

        # Execute the user's choice.
        if choice == POWER:
            base = float(input("What base for your calculation?\n"))
            exp = int(input("What exponent for your calculation, must be an int.?\n"))
            print(base,"raised to the power",exp,"=", mypow(base, exp))
                  
        elif choice == FACT:
            n = int(input("What value do you want the factorial of?\n"))
            if n < 0:
                print("Sorry, not a valid input for factorial.")
            else:
                print(n,"! = ", myfact(n), sep="")
                  
        elif choice == EXP:
            x = float(input("To what power do you want to raise e?\n"))
            print("e to the",x,"=",myexp(x))
            
        elif choice == SIN:
            angle = float(input("What angle do you want the sin of?\n"))
            rad = angle*MY_PI/180
            print("sin(",angle,") = ",mysin(rad))
            
        elif choice == COS:
            angle = float(input("What angle do you want the cos of?\n"))
            rad = angle*MY_PI/180
            print("cos(",angle,") = ",mycos(rad))            
            
        elif choice == TAN:
            angle = float(input("What angle do you want the tan of?\n"))
            rad = angle*MY_PI/180
            print("tan(",angle,") = ",mytan(rad))
            
        elif choice == NLOG:
            x = float(input("Enter the number you want the natural log of"))
            print("The natural log of", x, "is", nlog(x))

        elif choice == ROOT:
            x = float(input("Enter the number you want the square root of"))
            print("The square root of", x, "is", root(x))

        # Get the next menu selection from the user.
        choice = menu()

    print("Thanks for printing star designs!")

# Start it off
main()
