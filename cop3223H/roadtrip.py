#Federico Baron
#8/21/18
#Roadtrip calculates the amount of money to be spent on the trip
#gasPrice float is the price of gasoline in dollars
#gallonsInCar is a float and is the amount of gallons left in the car
#mpg float is the miles per gallon of the car
#tripLength is the length of the trip in miles
#total float is the money that is needed to complete the trip
gasPrice=float(input("What is the price of gasoline in dollars?"))
gallonsInCar=float(input("How many gallons of gas are in the car?"))
mpg=float(input("how many miles per gallon does your car get?"))
tripLength=float(input("how long is your road trip in miles?"))
total=((tripLength/mpg)-gallonsInCar)*gasPrice
print("you will need to spend $"+"{0:.2f}".format(total)+" on extra gas to complete the trip")
