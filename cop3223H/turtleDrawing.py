#Federico Kristen turtle drawing
#9/14/18
#turtle drawing of computer stabbed by knight sword debugger

import turtle
import random

#speeds up the drawing
turtle.speed(0)

#sets turtle to begin drawing keyboard
turtle.penup()
turtle.setpos(-320,-200)
turtle.pendown()
turtle.pensize(8)

def drawKeyboard():
    #draws rectangle for keyboard
    for i in range(2):
        turtle.fd(240)
        turtle.lt(90)
        turtle.fd(70)
        turtle.lt(90)

    #draws keys for keyboard
    turtle.pensize(4)

    #columns 
    for i in range (6):
        turtle.fd(20)
        turtle.lt(90)
        turtle.fd(70)
        turtle.rt(90)
        turtle.fd(20)
        turtle.rt(90)
        turtle.fd(70)
        turtle.lt(90)

    #range
    turtle.lt(90)
    turtle.fd(23)
    turtle.lt(90)
    turtle.fd(240)
    turtle.rt(90)
    turtle.fd(23)
    turtle.rt(90)
    turtle.fd(240)

def drawRectangle(height, width):
    for i in range(2):
        turtle.fd(width)
        turtle.rt(90)
        turtle.fd(height)
        turtle.rt(90)

def drawOval(height, width):
    turtle.pensize(6)
    for i in range(2):
        turtle.circle(10,90)
        turtle.fd(height)
        turtle.circle(10,90)
        turtle.fd(width)

#draws monitor
def drawMonitor():
    
    #bezel
    turtle.penup()
    turtle.setpos(-350,140)
    turtle.pendown()
    turtle.pensize(10)
    turtle.fd(300)
    turtle.rt(90)
    turtle.fd(27)
    turtle.penup()
    turtle.fd(50)
    turtle.pendown()
    turtle.fd(123)
    turtle.rt(90)
    turtle.fd(300)
    turtle.rt(90)
    turtle.fd(200)
    turtle.rt(90)

    #stand
    turtle.penup()
    turtle.setpos(-200,-60)
    turtle.pendown()
    turtle.rt(90)
    turtle.fd(45)
    turtle.lt(90)
    turtle.fd(40)
    turtle.rt(180)
    turtle.fd(80)

#draws mouse
def drawMouse():

    #draws cable
    turtle.penup()
    turtle.setpos(-100,-60)
    turtle.lt(90)
    turtle.pendown()
    turtle.pensize(3)
    turtle.fd(15)
    turtle.circle(30,90)
    turtle.circle(-50,80)
    turtle.circle(-15,90)

    #draws actual mouse
    drawOval(35,20)
    turtle.lt(90)
    turtle.setpos(-24,-163)
    turtle.fd(25)
    turtle.penup()
    turtle.setpos(-38,-192)
    turtle.pendown()
    turtle.setpos(1,-185)

#draws sword
def drawSword():
    #draw blade
    turtle.pencolor("dark gray")
    turtle.pensize(5)
    turtle.penup()
    turtle.setpos(-181,66)
    turtle.lt(130)
    turtle.pendown()
    turtle.fd(30)
    turtle.rt(40)
    turtle.fd(320)
    turtle.rt(90)
    turtle.fd(40)
    turtle.rt(90)
    turtle.fd(320)
    turtle.rt(40)
    
    turtle.fd(30)
    turtle.setpos(-181,66)

    #draws details
    turtle.setpos(-38,91)
    turtle.penup()
    turtle.setheading(90)
    
    #draws U
    turtle.pencolor("dark goldenrod")
    turtle.setpos(-22,103)
    turtle.rt(165)
    turtle.pendown()
    turtle.fd(20)
    turtle.lt(90)
    turtle.fd(13)
    turtle.lt(90)
    turtle.fd(20)
    turtle.penup()

    #draws C
    turtle.rt(95)
    turtle.fd(30)
    turtle.pendown()
    turtle.rt(180)
    turtle.fd(16)
    turtle.lt(90)
    turtle.fd(20)
    turtle.lt(90)
    turtle.fd(16)
    turtle.penup()

    #draws F
    turtle.fd(10)
    turtle.pendown()
    turtle.lt(90)
    turtle.fd(20)
    turtle.rt(90)
    turtle.fd(10)
    turtle.rt(180)
    turtle.fd(10)
    turtle.lt(90)
    turtle.fd(10)
    turtle.lt(90)
    turtle.fd(10)

    #draws remaining line
    turtle.pencolor("dark gray")
    turtle.penup()
    turtle.fd(20)
    turtle.lt(1)
    turtle.pendown()
    turtle.fd(95)

    #draws handle bar
    turtle.pencolor("dark goldenrod")
    turtle.penup()
    turtle.setpos(177,186)
    turtle.lt(89)
    turtle.pendown()
    drawOval(10,115)

    #draws handle
    turtle.rt(180)
    turtle.fd(45)
    turtle.lt(90)
    drawRectangle(25,60)

    #adds dots
    turtle.penup()
    turtle.setpos(163,175)
    turtle.dot(20, "dark gray")
    turtle.dot(10, "dark goldenrod")
    turtle.setpos(180,79)
    turtle.dot(20, "dark gray")
    turtle.dot(10, "dark goldenrod")

#draws bug
def drawBug(x,y,angle):
    turtle.setpos(x,y)
    turtle.lt(angle)
    turtle.dot(25)
    turtle.pensize(4)
    turtle.pendown()

    #draws legs
    turtle.lt(90)
    turtle.fd(3)
    turtle.rt(90)
    turtle.fd(20)
    turtle.rt(180)
    turtle.fd(40)
    turtle.rt(180)
    turtle.fd(20)
    turtle.rt(90)
    turtle.fd(10)
    turtle.rt(90)
    turtle.fd(20)
    turtle.rt(180)
    turtle.fd(40)

    #draws antennae
    turtle.rt(180)
    turtle.fd(15)
    turtle.rt(90)
    turtle.fd(22)
    turtle.rt(45)
    turtle.fd(10)
    turtle.rt(180)
    turtle.fd(10)
    turtle.lt(45)
    turtle.fd(22)
    turtle.rt(90)
    turtle.fd(10)
    turtle.rt(90)
    turtle.fd(22)
    turtle.lt(45)
    turtle.fd(10)

    turtle.penup()

#draw cracks in screen
def drawShatter(angle):
    turtle.pencolor("black")
    turtle.setposition(-183,63)
    turtle.pendown()
    turtle.lt(angle)
    turtle.fd(random.randint(10,30))
    turtle.lt(40)
    turtle.fd(random.randint(10,30))
    turtle.setposition(-183,63)

def drawLL():
    #draws 2 L's
    turtle.penup()
    turtle.lt(90)
    turtle.fd(30)
    turtle.pendown()
    turtle.fd(35)
    turtle.lt(180)
    turtle.fd(35)
    turtle.rt(90)
    turtle.fd(50)
    turtle.lt(180)
    turtle.fd(50)
    turtle.lt(90)
    turtle.penup()
    turtle.fd(60)
    turtle.pendown()
    turtle.fd(35)
    turtle.lt(180)
    turtle.fd(35)
    turtle.rt(90)
    turtle.fd(50)

def drawLetters():
    turtle.pensize(10)
    turtle.pencolor("dark goldenrod")
    #draws K
    turtle.penup()
    turtle.setposition(16,-16)
    turtle.seth(90)
    turtle.pendown()
    turtle.fd(50)
    turtle.rt(180)
    turtle.fd(20)
    turtle.lt(45)
    turtle.fd(45)
    turtle.rt(180)
    turtle.fd(45)
    turtle.rt(100)
    turtle.fd(30)
    turtle.penup()

    #draws I
    turtle.setheading(0)
    turtle.fd(30)
    turtle.pendown()
    turtle.rt(90)
    turtle.fd(50)

    #draws LL for kill
    drawLL()

    #draws A
    turtle.penup()
    turtle.rt(90)
    turtle.fd(95)
    turtle.pendown()
    turtle.rt(65)
    turtle.fd(55)
    turtle.lt(180)
    turtle.fd(55)
    turtle.lt(130)
    turtle.fd(55)
    turtle.rt(180)
    turtle.fd(25)
    turtle.rt(65)
    turtle.fd(25)

    #draws LL for all
    turtle.penup()
    turtle.setpos(270,-20)
    turtle.rt(90)
    drawLL()

    turtle.pencolor("black")
    #draws T for "the"
    turtle.penup()
    turtle.setpos(142,-115)
    turtle.pendown()
    turtle.fd(50)
    turtle.lt(90)
    turtle.fd(30)
    turtle.lt(180)
    turtle.fd(60)

    #draws H for "the"
    turtle.penup()
    turtle.fd(20)
    turtle.pendown()
    turtle.rt(90)
    turtle.fd(50)
    turtle.rt(180)
    turtle.fd(25)
    turtle.rt(90)
    turtle.fd(35)
    turtle.lt(90)
    turtle.fd(25)
    turtle.rt(180)
    turtle.fd(50)

    #draws E for "the"
    turtle.lt(90)
    turtle.penup()
    turtle.fd(65)
    turtle.pendown()
    turtle.lt(180)
    for i in range(2):
        turtle.fd(30)
        turtle.rt(90)
        turtle.fd(25)
        turtle.rt(90)
        turtle.fd(30)
        turtle.rt(180)

    turtle.pencolor("dark goldenrod")
    #draws B for "bugs"
    turtle.penup()
    turtle.setpos(71,-250)
    turtle.rt(90)
    turtle.fd(50)
    turtle.pendown()
    turtle.fd(50)
    turtle.rt(90)
    turtle.fd(25)
    turtle.rt(90)
    turtle.fd(25)
    turtle.rt(90)
    turtle.fd(25)
    turtle.lt(90)
    turtle.fd(25)
    turtle.lt(90)
    turtle.fd(40)
    turtle.lt(90)
    turtle.fd(25)
    turtle.lt(90)
    turtle.fd(25)
    
    #draws U for "bugs"
    turtle.penup()
    turtle.setpos(140,-150)
    turtle.lt(90)
    turtle.pendown()
    turtle.fd(50)
    turtle.lt(90)
    turtle.fd(30)
    turtle.lt(90)
    turtle.fd(50)

    #draws G for "bugs"
    turtle.penup()
    turtle.rt(90)
    turtle.fd(25)
    turtle.pendown()
    turtle.fd(30)
    turtle.rt(180)
    turtle.fd(30)
    turtle.lt(90)
    turtle.fd(50)
    turtle.lt(90)
    turtle.fd(30)
    turtle.lt(90)
    turtle.fd(20)
    turtle.lt(90)
    turtle.fd(15)

    #draws S for "bugs"
    turtle.penup()
    turtle.setpos(282,-150)
    turtle.pendown()
    turtle.fd(30)
    turtle.lt(90)
    turtle.fd(20)
    turtle.lt(90)
    turtle.fd(30)
    turtle.rt(90)
    turtle.fd(30)
    turtle.rt(90)
    turtle.fd(30)

    #draws !
    turtle.penup()
    turtle.setpos(320,-150)
    turtle.pendown()
    turtle.fd(10)
    turtle.lt(100)
    turtle.fd(35)
    turtle.lt(160)
    turtle.fd(35)
    turtle.penup()
    turtle.setpos(315,-200)
    turtle.dot(13)

#draws drawing
drawKeyboard()
drawMonitor()
drawMouse()
drawSword()
drawBug(-295,-16, -35)
drawBug(-96,13,-10)
drawBug(-241,100,-10)
drawShatter(100) 
drawShatter(150)
drawShatter(200)
drawLetters()

#hides turtle after finished drawing
turtle.hideturtle()

