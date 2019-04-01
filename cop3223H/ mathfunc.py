#Federico Baron
#9/26/18
#Example illustrating the use of functions in python
#This is a small math library

MY_PI = 3.14

#Pre-condition: exp must be an integer. If base is 0, exp can't be negative.
#Post-condition: returns base raise to the power exp.
def myPow(base, exp):

    #maps negative exponent case to positive exponent case.
    if exp < 0:
        exp = - exp
        base = 1 / base

    res = 1
    for i in range(exp):
        res *= base

    return res

#Pre-condition: n must be a non-negative integer.
#Post-condition: returns n! (factorial).
def myFact(n):

    #Multiply each integer from 1 to n into res.
    res = 1   
    for i in range(1, n + 1):
        res *= i
        
    return res

#returns abs value of x
def myAbs(x):
    if(x < 0):
        return -x
    return x

#returns e raised to the power x.
def myExp(x):

    res = 0

    #max times this will run is 100
    for i in range(100):

        #get this term and add it in
        term = myPow(x,i) / myFact(i)
        res += term

        #it's so small, we can break out
        if myAbs(term) < 1e-9:
            break
        
    return res
        
#returns sin
def mySin(x):

    res = 0
    sign = 1

    #max times this will run is 50
    for i in range(1, 100, 2):

        #get this term and add it in
        term = myPow(x,i) / myFact(i)
        res += sign * term

        #flip so next term is opposite
        sign = - sign

        #it's so small, we can break out
        if myAbs(term) < 1e-9:
            break
        
    return res

#uses trig formula to calculate cosine.
def myOtherCos(x):
    return mySin(MY_PI / 2 - x)

#returns cos.
def myCos(x):

    res = 0
    sign = 1

    #max times this will run is 50
    for i in range(0, 100, 2):

        #get this term and add it in
        term = myPow(x,i) / myFact(i)
        res += sign * term

        #flip so next term is opposite
        sign = - sign

        #it's so small, we can break out
        if myAbs(term) < 1e-9:
            break
        
    return res

#Pre-condition: x can't be pi/2, 3pi/2 or any other equivalent angle,
#Post-condition: returns the tangent of x
def myTan(x):
    return mySin(x)/myCos(x)

def main():

    print(mySin(3.14))
    print(mySin(1.57))
    print(mySin(.523))

main()

    
    
