
# Import requests for API.
import json
import requests

addy = input("enter your address: ")
select = input("enter the cuisine type you want (chinese, italian, indian, mexican): ")
select = select.capitalize()
x = ""


# Hard code cuisine ID's in dictionary.
thisdict = {
    "Chinese": "25",
    "Italian": "55",
    "Indian": "148",
    "Mexican": "73"
}

if select in "Chinese":
    x = thisdict.get("Chinese")
elif "Italian" in str(select):
    x = thisdict.get("Italian")
elif "Indian" in str(select):
    x = thisdict.get("Indian")
elif "Mexican" in str(select):
    x = thisdict.get("Mexican")

response = requests.get("https://maps.googleapis.com/maps/api/geocode/json?address="+str(addy)+"&key=AIzaSyBwo5hzLzWk_cafxCMh_ksvlxt3Sy_SiRk")

data = response.json()
#gets the specific latitude from the json object 
latitude = data['results'][0]['geometry']['location']['lat']
#gets the specific longtitude from the json object 
longitude = data['results'][0]['geometry']['location']['lng']

#print(latitude)
#print(longitude)

# Make a get request with the parameters.
header = {"User-agent": "curl/7.43.0", "Accept": "application/json", "user_key": "cfd43e3e996afa772f2f03a05a94a59a"}
response3 = requests.get("https://developers.zomato.com/api/v2.1/search?count=100&lat=" + str(latitude) + "&lon=" + str(longitude) + "&radius=200000&cuisines=" + str(x), headers = header)

data3 = response3.json()
#print(data3)

addresses = []
ratings = []
names = []
tup = []
masterlist = []
count = 0
for i in range(0,int(data3['results_shown'])):
    restadd = data3['restaurants'][i]['restaurant']['location']['address']
    restrat = data3['restaurants'][i]['restaurant']['user_rating']['aggregate_rating']
    restname = data3['restaurants'][i]['restaurant']['name']

    #response gets fetches the data for the particular address
    response2 = requests.get("https://maps.googleapis.com/maps/api/distancematrix/json?units=imperial&origins="+addy+"&destinations="+str(restadd)+"&key=AIzaSyADAncTwQZOsU_4jNU1BaFpjm55rjMfON4")

    #sets data into object to be processed 
    data2 = response2.json()

    distance = data2['rows'][0]['elements'][0]['duration']['value']
    
    if(distance < 1200):
        addresses.append(restadd)
        ratings.append(restrat)
        names.append(restname)
        tup = []
        tup.append(addresses[count])
        tup.append(ratings[count])
        tup.append(names[count])
        masterlist.append(tup)
        count = count + 1

length = len(ratings)
masterlist.sort(reverse = True, key = lambda masterlist: masterlist[1])
updatedmaster = []
if(length>10):
    length = 10

score = 0.0
for i in range(0,length):
    updatedmaster.append(masterlist[i])
    print(updatedmaster[i])
    score = score + float(updatedmaster[i][1])
score = (score / length) * 20
print("Your area's " + select + " foodie index is " + str(score))




    