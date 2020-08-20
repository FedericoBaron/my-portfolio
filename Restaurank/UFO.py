import requests

#this is the old version!!!! DO NOT DELETE YET
#response = requests.get("https://maps.googleapis.com/maps/api/geocode/json?address=1600+Amphitheatre+Parkway,+Mountain+View,+CA&key=AIzaSyBwo5hzLzWk_cafxCMh_ksvlxt3Sy_SiRk")
#addy = "1600 Amphitheatre Parkway, Mountain View, CA"

#gets input from user
#addy = input("Enter your address in quotes pls")

#addy= "\""+ input("Enter your address in quotes pls") + "\""

# api-endpoint 
URL = "http://maps.googleapis.com/maps/api/geocode/json"
  
# location given here 
location = "delhi technological university"
  
# defining a params dict for the parameters to be sent to the API 
PARAMS = {'address':location} 
  
# sending get request and saving the response as response object 
r = requests.get(url = URL, params = PARAMS) 
  
# extracting data in json format 
data = r.json() 
  
  
# extracting latitude, longitude and formatted address  
# of the first matching location 
latitude = data['results'][0]['geometry']['location']['lat'] 
longitude = data['results'][0]['geometry']['location']['lng'] 
formatted_address = data['results'][0]['formatted_address'] 
  
# printing the output 
print("Latitude:%s\nLongitude:%s\nFormatted Address:%s"
      %(latitude, longitude,formatted_address)) 

#to do list
#fix double quote
#get UFO latitudes
#calculate first x latitudes
#