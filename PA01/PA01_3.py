# PA01: Image Enhancement
# Written by: Marwin B. Alejo 2020-20221
# February 23, 2022
#
# Item 3 Requirement: 
# Write a code that reads in and displays an image.
# When the user clocks on the image, display the mouse pointer coordinates
# and the corresponding pixel (blue, green, red) values and write those values
# as text to the screen at the mouse pointer.

import cv2 as cv
import numpy as np

def mouseBGRXY(event, x, y, flags, param):
    if event == cv.EVENT_LBUTTONDOWN:
        colorsB = img[y,x,0]
        colorsG = img[y,x,1]
        colorsR = img[y,x,2]
        colors = img[y,x]
        font = cv.FONT_HERSHEY_SIMPLEX
        text = "Blue: " + str(colorsB) + " Green: " + str(colorsG) + " Red: " + str(colorsR) + " X-coord: " + str(x) + " Y-coord: " + str(y)
        cv.putText(img, text, (x,y), font, 0.5, (0,255,200), 1)
        cv.imshow("mouseBGRXY", img)

img = cv.imread("C:/Users/mbale/Desktop/CS282/regalia.png")
cv.namedWindow("mouseBGRXY")
cv.setMouseCallback('mouseBGRXY', mouseBGRXY)

while(1):
    cv.imshow('mouseBGRXY', img)
    if cv.waitKey(20) & 0xFF == 27:
        break

cv.destroyAllWindows()