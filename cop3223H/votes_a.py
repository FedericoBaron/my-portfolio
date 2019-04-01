#Federico Baron
#8/26/18
#Calculates how many more votes candidate A needs to win the election

#takes input for how many votes A and B candidates have
candA=int(input("How many more votes does candidate A currently have?"))
candB=int(input("How many more votes does candidate B currently have?"))

#computes who needs more votes and exactly how many more
if(candA>candB):
    print("Candidate B needs",candA-candB+1,"more votes to win the election")
else:
    print("Candidate A needs",candB-candA+1,"more votes to win the election")
