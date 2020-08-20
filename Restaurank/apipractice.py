import requests

#this is the old version!!!! DO NOT DELETE YET
#response = requests.get("https://maps.googleapis.com/maps/api/geocode/json?address=1600+Amphitheatre+Parkway,+Mountain+View,+CA&key=AIzaSyBwo5hzLzWk_cafxCMh_ksvlxt3Sy_SiRk")
#addy = "1600 Amphitheatre Parkway, Mountain View, CA"

#gets input from user 
addy = input("Enter your address in quotes pls")

#response gets fetches the data for the particular address
response = requests.get("https://maps.googleapis.com/maps/api/geocode/json?address="+addy+"&key=AIzaSyBwo5hzLzWk_cafxCMh_ksvlxt3Sy_SiRk")

#prints the contents of response
print(response.content)

#sets data into object to be processed 
data = response.json()

#gets the specific latitude from the json object 
latitude = data['results'][0]['geometry']['location']['lat']

#gets the specific longtitude from the json object 
longitude = data['results'][0]['geometry']['location']['lng']

#prints the stuffs
print(latitude)
print(longitude)

#to do list
#fix double quote
#get UFO latitudes
#calculate first x latitudes
#