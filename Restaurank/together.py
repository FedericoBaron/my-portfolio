# Import tkinter.
from tkinter import *

# Import requests for API.
import requests

# Define it as "root".
root = Tk()

# Title of the window.
root.title("Yummyz")

# Size of window.
root.geometry("250x300")

# Weight configuration for each row and column.
root.columnconfigure(0, weight = 1)
root.rowconfigure(0, weight = 1)
root.columnconfigure(1, weight = 1)
root.rowconfigure(1, weight = 1)
root.columnconfigure(2, weight = 1)
root.rowconfigure(2, weight = 1)
root.columnconfigure(3, weight = 1)
root.rowconfigure(3, weight = 1)
root.columnconfigure(4, weight = 1)
root.rowconfigure(4, weight = 1)

addy = StringVar
select = StringVar
x = StringVar

# Hard code cuisine ID's in dictionary.
thisdict = {
        "Chinese": "25",
        "Italian": "55",
        "Indian": "148",
        "Mexican": "73"
}

# Function used to capture value of user input address.
def capAddy():
    global addy
    addy = (entry.get())
    return

# Function used to capture option menu selection.
def capSelection():
    global select
    select = (variable.get())
    return

# Function that clears text entry box for user once clicked on.
firstclick = True

def entryclick(Event):
    global firstclick

    if firstclick:
        firstclick = False
        entry.delete(0, "end")

# Define our variable as a string, and set the first one to "choose.."
variable = StringVar(root)
variable.set("Choose..")

# Different choices user can choose from.
choices = ["Italian", "Mexican", "Indian", "Chinese"]

# Create our option menu and set our other options.
option = OptionMenu(root, variable, *choices)
option.grid(row = 1)

# Create the question labels.
question1 = Label(root, text = "Please enter your address:", bg = "black", fg = "gold", anchor = "center")
question2 = Label(root, text = "Please select your desired cuisine..", bg = "black", fg = "gold")

# Create a submit button.
button1 = Button(root, text = "Submit", command = lambda: [capSelection(), capAddy()])
button1.grid(row = 4)

# Define our entry variables for user input.
entry = Entry(root)
entry.insert(0, "Ex. 12345 West Street, Orlando, FL")
entry.bind("<FocusIn>", entryclick)

# Pack the question labels in the desired space.
question1.grid(row = 2)
question2.grid(row = 0)

# Pack the entry variables next to the 
entry.grid(row = 3)

if select is "Chinese":
        x = thisdict["Chinese"]
elif select is "Italian":
        x = thisdict["Italian"]
elif select is "Indian":
        x = thisdict["Indian"]
elif select is "Mexican":
        x = thisdict["Mexican"]

print(str(addy))
response = requests.get("https://maps.googleapis.com/maps/api/geocode/json?address="+str(addy)+"&key=AIzaSyBwo5hzLzWk_cafxCMh_ksvlxt3Sy_SiRk")

data = response.json()
#gets the specific latitude from the json object 
latitude = data['results'][0]['geometry']['location']['lat']
#gets the specific longtitude from the json object 
longitude = data['results'][0]['geometry']['location']['lng']

print(latitude)
print(longitude)

# Make a get request with the parameters.
header = {"User-agent": "curl/7.43.0", "Accept": "application/json", "user_key": "cfd43e3e996afa772f2f03a05a94a59a"}
response3 = requests.get("https://developers.zomato.com/api/v2.1/search?count=100&lat=" + str(latitude) + "&lon=" + str(longitude) + "&radius=200000&cuisines=" + str(x), headers = header)

data3 = response3.json()
#print(data3)

addresses = []
ratings = []
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

# Call infinite loop.
root.mainloop()