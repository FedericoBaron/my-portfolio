#Federico Baron

#returns the largest of a, b, c
def max3(a,b,c):

    #a is biggest
    if a > b and a > c:
        return a

    #here b
    if (b > c):
        return b

    #c
    return c

def main():

    #get user value
    a = int(input("Enter the first value.\n")
    b = int(input("Enter the second value.\n")
    c = int(input("Enter the third value.\n")
    d = int(input("Enter the fourth value.\n")

    #get the largest of the three pairs with a
    maxA = max3(a+b, a+c, a+d)

    #and the three pairs without a.
    maxRest = max3(b+c, b+d, c+d)


    #maxA wins!!!
    if maxA > maxRest:
            print("The max sum of any pair is", maxA)

    #maxRest wins!!!
    else:
            print("The max sum of any pair is", maxRest)

main()
