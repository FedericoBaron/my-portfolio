#Kristen Ng and Federico Baron
#Intro to C final project
#Word connect game (finders)

#imports libraries
import pygame
import random
import sys
import enchant
import math
import random
from random import shuffle

#initializes game
pygame.init()

#Define size of window
WIDTH = 500
HEIGHT = 700
 
#Define some colors
BACKGROUND = (178,206,255)
BLACK = (0, 0, 0)
BLOSSOM = (183, 255, 241)
YELLOW = (237,227,37)

#list of words
wordList = []

#play game bool
screenNum = 0

#to start or not
toStart = False

#sets difficulty
difficulty = ""

#Used words list
wordsUsed = []

#loads all letters to list
letter = []
for i in range(ord('A'),ord('Z')):
    letter.append(pygame.image.load(chr(i)+'.png'))

#list of letters
letterList = []

#temp letterlist
temp = []

#what the user inputs
userWord = ""

#list of coordinates
coordinatesX = []
coordinatesY = []

#makes a list with all "lastMove" as it keeps adding them to it
allMoves = []

#makes list with all the information needed to undo the previous move
lastMove = []

#sets score to 0
score = 0

#sets total score to 0
totalScore = 0

#sets seconds to 60
seconds = 60

#time setter
start_ticks = 0

#Pre-Condition: takes in the text and the font to be used
#Post-Condition: returns the textSurface and rectangular text surface
def text_objects(text, font):
    textSurface = font.render(text, True, BLACK)
    return textSurface, textSurface.get_rect()

#Pre-Condition: takes in the text, position of X, position of Y, and size
#Post-Condition: displays the text at the font in freesansbold font at the given size
def display_text(text, posX, posY, size):
    font = pygame.font.Font('freesansbold.ttf', size)
    textSurf, textRect = text_objects(text, font)
    textRect.center = (posX,posY)
    screen.blit(textSurf, textRect)

#Pre-Condition: none
#Post-Condition: makes the easy, medium, and hard buttons
def makeButton(button):
    #adds text to button
    display_text(button.get_name(), button.get_posX(), button.get_posY(), 20)

#Pre-Condition: receives all the properties of a button
#Post-Condition: checks if the given button is clicked, if so return True
def buttonClick(posX, posY, centerX, centerY, width, height, screenN):
    global screenNum
    if(screenNum == screenN and centerX + width / 2 >= posX and centerX - width / 2 <= posX and centerY + height / 2 >= posY and centerY - height / 2 <= posY):
        print("Button clicked")
        return True
    return False
    
#Pre-Condition: takes in file with ranked dictionary word.
#Post-condtion: separates rank and word and passes it to make an object of the word class.
def processFile():

    #f is the file and it opens
    f = open("notsomanywordspart2.txt", "r")

    #defines rank and word
    word = []
    rank = []

    while True:
        
        #reads next line
        line = f.readline()

        #checks for EOF
        if(line == ""):
            break

        #Makes new word object with given rank and word
        wordX = line.split(" ")[8]
        
        #appends word object to wordList
        wordList.append(wordX.lower())
        
    f.close()

#processess the file
processFile()

#Pre-Condition: takes in file with all words in dictionary
#Post-Condition: saves all words into list to be compared with user input
def checkIfWord(word):

    #checks if word from user is in dictionary
    d = enchant.Dict("en_US")

    #returns True or False
    return(d.check(word))

#Pre-Condition: It receives an unscrambled word string.
#Post-Condition: It returns a string of the scrambled word.
def scramble(word):
    print(word)
    word = list(word)
    shuffle(word)
    print(''.join(word))

    #adds each letter into letterList
    for i in range(0,len(word)):
        letterList.append(word[i])
        
    return ''.join(word)

#Pre-Condition: it is passed x and y coordinates, a letter object, and that they want the letter to be
#Post-Condition: it plots a letter at a given location
def plotLetter(x, y, word, size):
    print(ord(word)-97)
    drawLetter = Letter(x,y,letter[ord(word)-97],size)
    return drawLetter
    
    
#sets up board with given word
def setUp(word):

    #scrambles the word
    word = scramble(word)
    
    #initializes radius
    radius = 1
    
    #defines radius and lettersize based on the length of the word
    if(len(word) <8):
        radius = 140
    else:
        radius = 180

    angle = 360 / len(word)
    
    startAngle = 0

    i = 0
    while(startAngle < round(360,1)):
        
        #calculates position at angle
        y = round(math.sin(math.radians(startAngle)),6) * radius + HEIGHT / 2 
        x = round(math.cos(math.radians(startAngle)),6) * radius + WIDTH / 2 -30

        #plots a letter at the given location with the given dimensions
        plotLetter(x, y, word[i], 50)

        #appends to coordinate list
        coordinatesX.append(x)
        coordinatesY.append(y)
        
        #increases counter to do next letter
        i = i + 1

        #increases angle to do next location
        startAngle = startAngle + angle

#j allows the program to plot a letter in the right box
j = 0

#Pre-Condition: it starts when user clicks on word and while it remains clicked it keeps on adding the letters to form a word
#Post-Condition: it forms a word at the end and returns it
def connectWords():
    global userWord
    global j
    global lastMove
    global temp

    #if the user clicks
    if event.type == pygame.MOUSEBUTTONDOWN:

        #gets the position of where the user clicked
        clickPosX = pygame.mouse.get_pos()[0]
        clickPosY = pygame.mouse.get_pos()[1]

        #temporary letterlist to set letters that are clicked to -1 to indicate they have already been clicked and cannot be clicked again
        temp = letterList[:]
        
        #goes through every letter in the word that is diplayed and checks if it was clicked or not
        for i in range(0, len(coordinatesX)):

            #checks if the letter was already clicked and if the button is clicked
            if(temp[i]!= -1 and buttonClick(clickPosX-25, clickPosY-25, coordinatesX[i], coordinatesY[i], 50, 50, 1)):

                #user word gets next letter
                userWord = userWord + temp[i]

                #appends everything that's needed for lastMove to be able to perform the undo function
                lastMove = []
                lastMove.append(temp[i])
                lastMove.append(coordinatesX[i])
                lastMove.append(coordinatesY[i])
                
                #letter is plotted in box grid
                letter = plotLetter(j*40,20,temp[i],40)
                all_sprites.add(letter)
                lastMove.append(letter)
                
                #last move is appended to all moves
                allMoves.append(lastMove)

                #j increases by one to do next box 
                j = j + 1

                #temp[i] is set to -1 to know that it was already used
                temp[i] = -1

                #shows that the button was clicked
                pygame.draw.rect(screen, YELLOW, [coordinatesX[i],coordinatesY[i],50,50], 10)

                #breaks out of loop
                break

        #once the word is as long as the max length it checks
        if(len(userWord) == len(coordinatesX)):
            checkWord()

        #debugging purposes        
        print(userWord)
        print(lastMove)
        print(allMoves)
            
    return

#checks if user word is the original word or a different word
def checkWord():
    global userWord
    if (userWord not in wordsUsed and len(userWord) > 3 and checkIfWord(userWord)):
        print("yay")
        if (len(userWord) == len(letterList)):
            print("double yay")

        #adds the length of the word found to score
        addScore(len(userWord))

        #appends the word found to a word list
        wordsUsed.append(userWord)

    #clears everything
    clear()

#Pre-Condition: takes in length of the word
#Post-Condition: increases score
def addScore(wordLen):
    global score
    global totalScore
    score = score + wordLen
    totalScore = totalScore + wordLen
    updateScore()

#Pre-Condition: None
#Post-Condition: updates the score to display the new score
def updateScore():
    #draws over score
    pygame.draw.rect(screen, BACKGROUND, [0, 70, 200, 40])
    
    #does text for score
    display_text("Score: "+ str(totalScore), 50, 95, 25)
            
#Pre-Condition: None
#Post-Condition: undos last move
def undo():

    #global variables needed to undo
    global lastMove
    global allMoves
    global userWord
    global j

    #checks if last move is empty
    if(len(lastMove) == 0):
        return
    
    #shows that the button was clicked
    pygame.draw.rect(screen, BACKGROUND, [lastMove[1],lastMove[2],50,50], 10)

    #deletes last move
    if(len(allMoves)>0):
        del allMoves[len(allMoves)-1]
        if(len(allMoves)>0):
            lastMove = allMoves[len(allMoves)-1]
        else:
            lastMove = []

    #removes last letter from user word
    userWord = userWord[:-1]

    #sets last temp to what it used to be so it can be clicked again
    temp[len(temp)-1] = letterList[len(temp)-1]

    #sets j to be one less
    j = j - 1

    #clears the boxes
    pygame.draw.rect(screen, BACKGROUND, [0, 0, 500, 70])
    drawBoxes()

    #re-plots all letters
    for i in range(0,len(userWord)):
        letter = plotLetter(i*40,20,allMoves[i][0],40)

#Pre-Condition: None
#Post-Condition: 
def clear():
    #global variables needed to undo
    global allMoves

    #defines the amount of letters
    length = len(allMoves)

    #undos every single letter
    for i in range(0,length):
        undo()

#Draws boxes for plotting letters to form word
def drawBoxes():
    for i in range(0,len(letterList)):
        pygame.draw.rect(screen, BLACK, [i*40,20,40,40], 5)
    
    
#random word from text file
def getWord():
    return wordList[random.randint(0,len(wordList)-1)]

#Pre-Condition: word is a word from the list wordList[] and difficulty is whatever the user inputs.
#Post-Condition: returns a word of that difficulty level.
def difficultyWord(word, difficulty):
    
    #checks if word is too short or has non alpha characters. If one of those conditions is true, calls recursively to draw a new word
    if(len(word) <= 5 or len(word) >= 12  or not word.isalpha()):
        return difficultyWord(getWord(), difficulty)

    #checks if word is easy
    elif(len(word) < 7):
        if(difficulty == "easy"):
            return word
        else:
            return difficultyWord(getWord(), difficulty)

    #checks if word is medium
    elif(len(word) < 10):
        if(difficulty == "medium"):
            return word
        else:
            return difficultyWord(getWord(), difficulty)
        
    #else word is hard
    else:
        if(difficulty == "hard"):
            return word
        else:
            return difficultyWord(getWord(), difficulty)
       
#Pre-Condition: none
#Post-Condition: draws the entire home screen
def drawHomeScreen():
    global all_sprites
    global screenNum

    #adds sprites to sprite group
    all_sprites.add(easy_button)
    all_sprites.add(medium_button)
    all_sprites.add(hard_button)

    #removes buttons that aren't used
    all_sprites.remove(undo_button)
    all_sprites.remove(clear_button)
    all_sprites.remove(check_button)

    #sets screenNum to 0
    screenNum = 0

    #import image of raccoon
    image = pygame.image.load('raccoonyay.png')
    
    #turns the image into the given scale
    image = pygame.transform.scale(image, (WIDTH, HEIGHT))

    #displays image at given location
    screen.blit(image, (0, 0))

    #makes button shapes
    all_sprites.draw(screen)
    
    #make buttons
    makeButton(easy_button)
    makeButton(medium_button)
    makeButton(hard_button)

#Pre-Condition: called from playGame()
#Post-Condition: changes screen to game screen
def gameScreen():
    #needed to change variable
    global screenNum

    #sets screen number to home screen
    screenNum = 1

    #Sets background to color
    screen.fill(BACKGROUND)

#Pre-Condition: called from playGame() if loser loses (runs out of time)
#Post-Condition: changes screen to loser screen
def loserScreen():
    global screenNum

    #sets screen number to loser screen
    screenNum = 2

    #import image of loserScreen
    image = pygame.image.load('loserScreen.png')
    
    #turns the image into the given scale
    image = pygame.transform.scale(image, (WIDTH, HEIGHT))

    #displays image at given location
    screen.blit(image, (0, 0))

    #clears all sprites
    all_sprites.empty()
    
    #adds and places retry buttons
    all_sprites.add(retry_button)

    #makes button shapes
    all_sprites.draw(screen)

    #makes retry button, which brings user back to main screen
    makeButton(retry_button)
    

#Pre-Condition: called from playGame() if player wins!
#Post-Condition: changes screen to winner screen
def winnerScreen():
    global screenNum
    global score
    global totalScore

    #sets screen number to winner screen
    screenNum = 3

    #import image of winnerScreen
    image = pygame.image.load('winnerScreen.png')
    
    #turns the image into the given scale
    image = pygame.transform.scale(image, (WIDTH, HEIGHT))

    #displays image at given location
    screen.blit(image, (0, 0))

    #displays score user had?

    #clears sprites
    all_sprites.empty()

    #adds next button
    all_sprites.add(next_button)

    #draws next button
    all_sprites.draw(screen)
    
    #makes next button, which allows the user to play again in same level
    makeButton(next_button)
    
    
#Pre-Condition: called from main
#Post-Condition: does all the buttons and set up for the game screen
def playGame():
    
    #need global to update score and start timer
    global score
    global toStart
    global start_ticks
    
    #sets screen to game screen
    gameScreen()

    #gets a word of the given difficulty
    word = difficultyWord(getWord(),difficulty)

    #sets up the screen for that word
    setUp(word)

    #draws boxes
    drawBoxes()

    #removes buttons that aren't used
    all_sprites.remove(easy_button)
    all_sprites.remove(medium_button)
    all_sprites.remove(hard_button)

    #adds buttons that are used
    all_sprites.add(undo_button)
    all_sprites.add(clear_button)
    all_sprites.add(check_button)

    #draws all buttons needed
    all_sprites.draw(screen)

    #adds text to all buttons
    makeButton(undo_button)
    makeButton(clear_button)
    makeButton(check_button)

    #does text for score
    display_text("Score: "+ str(totalScore), 60, 95, 25)

    #sets toStart to true
    toStart = True

    #sets ticks to time
    start_ticks = pygame.time.get_ticks()

#used to see how much time passed
currentTime = 60

#checks the time that passed
def checkTime():
    global score
    
    seconds = (pygame.time.get_ticks()-start_ticks)/1000
    if(seconds < 60 and currentTime > seconds):
        #draws over time
        pygame.draw.rect(screen, BACKGROUND, [200, 70, 500, 40])

        #displays the time left
        display_text("Time remaining: " + str(60-int(seconds)), 350, 95, 25)

    if 60-seconds <= 0:
        if score >= len(letterList):
            winnerScreen()
        else:
            loserScreen()
        
#Creates image sprite
class Letter(pygame.sprite.Sprite):
    
    #construction for sprite, you can pass it posX, posY, and the image for that letter
    def  __init__(self, posX, posY, letter, size):
        
        pygame.sprite.Sprite.__init__(self)
        
        self.__letter = letter
        self.__posX = posX
        self.__posY = posY
        self.__size = size

        letter = pygame.transform.scale(letter, (size,size))
        screen.blit(letter,(posX,posY))

    #getter methods for name, posX, and posY
    def get_letter(self):
        return self.__letter
    
    def get_posX(self):
        return self.__posX
    
    def get_posY(self):
        return self.__posY


#Creates button sprite
class Button(pygame.sprite.Sprite):
    
    #construction for sprite, you can pass it more things like width and height
    def __init__(self, width, height, posX, posY, name, color, screenN):

        pygame.sprite.Sprite.__init__(self)

        #defines difficulty, posX, and posY in constructor
        self.__name = name
        self.__posX = posX
        self.__posY = posY
        self.__screenN = screenN
        
        #sets the size of the sprite
        self.image = pygame.Surface([width, height])

        #sets the color of the sprite
        self.image.fill(color)

        #the rectangle represents the dimensions of the sprite
        self.rect = self.image.get_rect()

        #sets the position of the sprite
        self.rect.center = (posX, posY)

    #getter methods for name, posX, and posY
    def get_name(self):
        return self.__name
    
    def get_posX(self):
        return self.__posX
    
    def get_posY(self):
        return self.__posY

#Open a new window
size = (WIDTH, HEIGHT)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Finders")

# The loop will carry on until the user exit the game (e.g. clicks the close button).
carryOn = True
 
# The clock will be used to control how fast the screen updates
clock = pygame.time.Clock()

#creates group of sprites
all_sprites = pygame.sprite.Group()

#creates easy, medium and hard buttons
easy_button = Button(100, 50, 100, HEIGHT -150, "easy", BLOSSOM, 0)
medium_button = Button(100, 50, WIDTH / 2, HEIGHT -150, "medium", BLOSSOM, 0)
hard_button = Button(100, 50, 400, HEIGHT -150, "hard", BLOSSOM, 0)

#makes undo button
undo_button = Button(100, 50, 400, HEIGHT -50, "undo", YELLOW, 1)

#makes clear button
clear_button = Button(100, 50, 250, HEIGHT -50, "clear", YELLOW, 1)

#makes check button
check_button = Button(100, 50, 100, HEIGHT -50, "check", YELLOW, 1)

#makes retry button
retry_button =  Button(100, 50, 250, HEIGHT -200, "retry", YELLOW, 2)

#makes next button
next_button = Button(100, 50, 250, HEIGHT -200, "next", YELLOW, 3)

#draws the home screen
drawHomeScreen()

#processes the text file for rank and word
processFile()

# Main Program Loop
while carryOn:
    
    #keep loop running at the right speed
    clock.tick(100)
    
    # Main event loop
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
              carryOn = False # Flag that we are done so we exit this loop

        #checks if user clicks button
        if event.type == pygame.MOUSEBUTTONDOWN:
            clickPosX = pygame.mouse.get_pos()[0]
            clickPosY = pygame.mouse.get_pos()[1]

            #checks if easy button is clicked
            if(screenNum == 0 and buttonClick(clickPosX, clickPosY, easy_button.get_posX(), easy_button.get_posY(), 100, 50, 0)):
                difficulty = "easy"
                playGame()

            #checks if medium button is clicked
            elif(screenNum == 0 and buttonClick(clickPosX, clickPosY, medium_button.get_posX(), medium_button.get_posY(), 100, 50, 0)):
                difficulty = "medium"
                playGame()

            #checks if hard button is clicked
            elif(screenNum == 0 and buttonClick(clickPosX, clickPosY, hard_button.get_posX(), hard_button.get_posY(), 100, 50, 0)):
                difficulty = "hard"
                playGame()

            #checks if undo button is clicked
            elif(screenNum == 1 and buttonClick(clickPosX, clickPosY, undo_button.get_posX(), undo_button.get_posY(),100, 50, 1)):
                undo()

            #checks if check button is clicked
            elif(screenNum == 1 and buttonClick(clickPosX, clickPosY, check_button.get_posX(), check_button.get_posY(),100, 50, 1)):
                checkWord()

            #checks if clear button is clicked
            elif(screenNum == 1 and buttonClick(clickPosX, clickPosY, clear_button.get_posX(), check_button.get_posY(),100, 50, 1)):
                clear()

            #if screen is the game screen and none of the other buttons are clicked then call connect words
            elif(screenNum == 1):
                connectWords()

            #if player loses and retry button is pressed, sets score back to 0 and drawsHomeScreen
            elif(screenNum == 2 and buttonClick(clickPosX, clickPosY, retry_button.get_posX(), retry_button.get_posY(),100, 50, 2)):
                all_sprites.remove(retry_button)
                letterList = []
                temp = []
                coordinatesX = []
                coordinatesY = []
                allMoves = []
                lastMove = []
                userWord = ""
                wordsUsed = []
                j = 0
                score = 0
                totalScore = 0
                drawHomeScreen()
                

            #if player wins and next button is pressed, generates a new gameScreen and allows user to play again 
            elif(screenNum == 3 and buttonClick(clickPosX, clickPosY, next_button.get_posX(), next_button.get_posY(),100, 50, 3)):
                all_sprites.remove(next_button)
                letterList = []
                temp = []
                coordinatesX = []
                coordinatesY = []
                allMoves = []
                lastMove = []
                userWord = ""
                wordsUsed = []
                j = 0
                score = 0
                drawHomeScreen()
                


    if(screenNum == 1):
        checkTime()

    #Update
    all_sprites.update()
    
    #Go ahead and update the screen with what we've drawn.
    pygame.display.flip()
         
 
#Once we have exited the main program loop we can stop the game engine:
pygame.quit()






