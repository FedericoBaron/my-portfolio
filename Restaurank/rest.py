# Import tkinter.
from tkinter import *

# Import requests for API.
import json
import requests

# Define it as "root".
root = Tk()

addy = ""
select = ""
x = 0


# Hard code cuisine ID's in dictionary.
thisdict = {
    "Chinese": "25",
    "Italian": "55",
    "Indian": "148",
    "Mexican": "73"
}

def forgetfunc(length, num):
    for i in range(length):
        num[i].grid_forget()

# Function that clears text entry box for user once clicked on.
firstclick = True

def chapter2():
    if select == "Chinese":
        x = thisdict.get("Chinese")
    elif str(select) == "Italian":
        x = thisdict.get("Italian")
    elif str(select) == "Indian":
        x = thisdict.get("Indian")
    elif str(select) == "Mexican":
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
    masterlist = []
    for i in range(0,int(data3['results_shown'])):
        restadd = data3['restaurants'][i]['restaurant']['location']['address']
        restrat = data3['restaurants'][i]['restaurant']['user_rating']['aggregate_rating']
        restname = data3['restaurants'][i]['name']
        #print(restadd)
        #print(restrat)
        #response gets fetches the data for the particular address
        response2 = requests.get("https://maps.googleapis.com/maps/api/distancematrix/json?units=imperial&origins="+addy+"&destinations="+restadd+"&key=AIzaSyADAncTwQZOsU_4jNU1BaFpjm55rjMfON4")
        #sets data into object to be processed 
        data2 = response2.json()
        distance = data2['rows'][0]['elements'][0]['duration']['value']
        #print(distance)
        if(distance < 1200):
            addresses.append(restadd)
            ratings.append(restrat)
            names.append(restname)
            masterlist.append(addresses[i],ratings[i],names[i])

    length = len(ratings)
    #ratings = [float(x) for x in ratings]
    masterlist.sort(reverse = True, key = lambda masterlist: masterlist[1])
    updatedmaster = []
    if(length>10):
        length = 10
    for i in range(0,length):
        updatedmaster.append(masterlist[i])
        print(masterlist[i])

    # Title of the window.
    root.title("Yummyz")

    # Size of window.
    root.geometry("250x300")

    num = []
    for i in range(1,length+1):
        num.append(Label(root, text = "#"+str(i), bg = "black", fg = "gold"))
        num[i-1].grid(row = i, column = 0)
        root.columnconfigure(0, weight = 1)
        root.rowconfigure(i-1, weight = 1)
    
    button1 = Button(root, text = "Return to homepage", command = lambda: [forgetfunc(length, num), chapter1()])
    button1.pack(side = BOTTOM)
        

def chapter1():
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

    # Function used to capture value of user input address.
    def capAddy():
        global addy
        addy = (entry.get())
        #print(addy)
        return

    # Function used to capture option menu selection.
    def capSelection():
        global select
        select = (variable.get())
        #print(select)
        return

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
    button1 = Button(root, text = "Submit", command = lambda: [capSelection(), capAddy(), question1.grid_forget(), question2.grid_forget(), entry.grid_forget(), button1.grid_forget(), option.grid_forget(), chapter2()])
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

    # Call infinite loop.
    root.mainloop()

chapter1()



    