# Import tkinter.
from tkinter import *

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

# Function used to capture value of user input address.
def capAddy():
    addy = (entry.get())
    print(addy)

# Function used to capture option menu selection.
def capSelection():
    select = (variable.get())
    print(select)

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

# Create a submit button. ****Should capture return value of address******
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


# Call infinite loop.
root.mainloop()
