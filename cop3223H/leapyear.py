#Federico Baron
#9/3/18
#leap year calculator
#These extra days occur in years which are multiples of four (with the exception of years divisible by 100 but not by 400).

#gets input from user for year 
year = int(input("What year do you want to check?"))

#checks if year is present past or future and prints string that contains the year and the correct tense.
if(year==2018):
    print("2018 is",end = ' ')
elif(year>2018):
    print(year,"will",end = ' ')
else:
    print(year,"was",end = ' ')

#Checks if the year input is a leap year or not and prints the answer
if(year%4 == 0 and (year%100 != 0 or year%400 == 0) and year<=2018):
    print("a leap year.")
elif(year%4 == 0 and (year%100 != 0 or year%400 == 0) and year>2018):
    print("be a leap year.")
elif(year>2018):
    print("not be a leap year.")
else:
    print("not a leap year")
   
