#!/usr/bin/env python3

from graphics import *
from PIL import Image

global ext
ext = ".jpg"
#win = GraphWin("My Animation", 400, 400, autoflush=False)

def funcion():
	win = GraphWin("My Circle", 100, 100)
	#c = Circle(Point(50,50), 10)
	#c.draw(win)
	#win.getMouse() # pause for click in window
	img = Image.open("descarga.jpp")
	#img = Image(100,"descarga.jpg")
	#img.draw(win)
	win.close()

funcion()


