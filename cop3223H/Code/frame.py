#Federico Baron
#8/24/18
#Calculates area of frame

#Get the dimensions of the frame (inner and outer)
blen = int(input("What is the outside length of the frame?"))
bwidth = int(input("What is the outside width of the frame?"))
slen = int(input("What is the inner length of the frame?"))
swidth = int(input("What is the inside width of the frame?"))

#Calculate and output the result
print("The area of the frame is", blen*bwidth - slen*swidth)

# / is real number or floating point division
# // is int divisions
