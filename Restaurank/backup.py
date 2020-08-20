#backup
import requests

#gets input from user 
addy = input("Enter your address in quotes pls")
cuisine = input("Enter the cuisine in quotes pls")

#gets coordinates of the users address 
response = requests.get("https://maps.googleapis.com/maps/api/geocode/json?address="+addy+"&key=AIzaSyBwo5hzLzWk_cafxCMh_ksvlxt3Sy_SiRk")
data = response.json()

#gets the specific latitude from the json object 
latitude = data['results'][0]['geometry']['location']['lat']
#gets the specific longtitude from the json object 
longitude = data['results'][0]['geometry']['location']['lng']

#prints latitude and longitude
#print(latitude)
#print(longitude)

# Make a get request with the parameters.
header = {"User-agent": "curl/7.43.0", "Accept": "application/json", "user_key": "cfd43e3e996afa772f2f03a05a94a59a"}
response3 = requests.get("https://developers.zomato.com/api/v2.1/search?count=100&lat=" + str(latitude) + "&lon=" + str(longitude) + "&radius=2000000&cuisines=" + cuisine, headers = header)
data3 = response3.json()
#print(data3)

#list of addresses that are used for computing score
addresses = []

#list of ratings that are used for computing score
ratings = []

#goes through results shown 
for i in range(0,int(data3['results_shown'])):
    restadd = data3['restaurants'][i]['restaurant']['location']['address']
    restrat = data3['restaurants'][i]['restaurant']['user_rating']['aggregate_rating']
    print(restadd)
    print(restrat)
    #response gets fetches the data for the particular address
    response2 = requests.get("https://maps.googleapis.com/maps/api/distancematrix/json?units=imperial&origins="+addy+"&destinations="+restadd+"&key=AIzaSyADAncTwQZOsU_4jNU1BaFpjm55rjMfON4")
    #sets data into object to be processed 
    data2 = response2.json()
    distance = data2['rows'][0]['elements'][0]['duration']['value']
    print(distance)
    if(distance < 1200):
        addresses.append(restadd)
        ratings.append(restrat)