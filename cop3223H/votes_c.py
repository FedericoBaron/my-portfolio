#Federico Baron
#8/26/18
#Calculates how many more voters candidate A will need to win the election by a margin of 1000

#declares variables of candidate votes and percent of new voters that will vote for candidate A
candA=int(input("How many votes does candidate A currently have?"))
candB=int(input("How many votes does candidate B currently have?"))
percentA=int(input("What percentage of new voters will vote for candidate A?"))

#calculates how many new voters are needed for candidate A to win by a margin of 1000 votes
total=(int)((candB-candA+1000)/((percentA/100)-((100-percentA)/100)))

#outputs how many new voters are needed for candidate A to win
print("Candidate A will need",total,"more voters")

          
          
