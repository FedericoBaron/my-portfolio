#Federico Baron
#9/26/18
#star designs

def forwardtri(n):
    for i in range(n):
        print("*"*(i+1))

def backwardtri(n):
    for i in range(n-1,-1,-1):
        print(" "*i, sep = "")
        print("*"*(n-i))
def main():
    forwardtri(10)
    backwardtri(10)

main()
