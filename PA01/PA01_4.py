# PA01: Image Enhancement
# Written by: Marwin B. Alejo 2020-20221
# February 23, 2022
#
# Item 4 Requirement: 
# Write a code that continously reads frames from webcam,
# turns the result to gryscale, and performs Canny edge detection on the image.
# Display all three stages as three different frame (images) in one window.
#
# ATTENTION: Although this is an easy task, 
# the catch here is to have all frames to have the same number of channels else this code will fail.
# SWISH!!!

import cv2 as cv
import numpy as np

cam1 = cv.VideoCapture(0) #init camer feed

while(True):
    ret1, frame1 = cam1.read() #read frames from cam1
    frame2 = cv.cvtColor(frame1, cv.COLOR_BGR2GRAY) # convert frame 1 to grayscale and store to frame 2 with 2-ch
    frame4 = cv.cvtColor(frame2, cv.COLOR_GRAY2BGR) # convert frame 2 to BGR but remain gray to have 3-ch instead of 2
    frame3 = cv.Canny(frame4, 60, 100, 0.5) # canny edge but with 2-ch due to grayscale
    frame5 = cv.cvtColor(frame3, cv.COLOR_GRAY2BGR) # convert 2ch canny image to 3ch
    combi = cv.hconcat((frame1, frame4, frame5)) #voltes-3 ykwim here...
    cv.imshow("Camera REAL-TIME feed: (1)left: no filter, (2)middle: grayscale, (3)right: canny-edge", combi)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cam1.release()
cv.destroyAllWindows()