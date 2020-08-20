#Federico Baron
#9/12/18
#treasure box

days = int(input("How many days will you run the simulation?"))

#declares and initializes variables for sticker count and behavior count
sumbehavior = 0
sumstickers = 0
sumtreasure = 0
currentdaytreasures = 0

#goes through days and makes calculations
for i in range(days):

    #takes input for behavior and stickers and adds it to variables
    sumbehavior = sumbehavior + int(input("What was your overall behavior on day " + str(i + 1) + "?"))
    sumstickers = sumstickers + int(input("How many stickers did you earn on day " + str(i + 1) + "?"))

    #checks if student has enough stickers
    if(sumstickers >= 10):
        sumstickers = sumstickers - 10
        currentdaytreasures = currentdaytreasures + 1

    #checks if it is the 5th day   
    if( (i + 1) % 5 == 0):

        #checks if treasure was won
        if(sumbehavior == 0):
            currentdaytreasures = currentdaytreasures + 1
            
        #sets variables to 0
        sumbehavior = 0

    #checks if any treasures were earned     
    if(currentdaytreasures > 0):
        print("At the conclusion of day " + str(i + 1) + " you have received " + str(currentdaytreasures) + " treasure box item(s).")
        sumtreasure = sumtreasure + currentdaytreasures

    #sets treasures for the day to 0
    currentdaytreasures = 0

#prints total amount of treasure boxes received
print("in total, you received " + str(sumtreasure) + " treasure box item(s).") 
        
    
