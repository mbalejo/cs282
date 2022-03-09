# PA01: Image Enhancement
# Written by: Marwin B. Alejo 2020-20221
# February 23, 2022
#
# Item 5 Requirement: 
# Image Enhancement

from statistics import median
import cv2 as cv
from cv2 import hconcat
import numpy as np
from scipy.ndimage.filters import median_filter

dental = cv.VideoCapture('C:/Users/mbale/Desktop/CS282/dental.gif')
butterfly = cv.VideoCapture('C:/Users/mbale/Desktop/CS282/butterfly.gif')
cells = cv.imread('C:/Users/mbale/Desktop/CS282/cells27.jpg')
momandkids = cv.imread('C:/Users/mbale/Desktop/CS282/momandkids.jpg')

def gammaCorrectionDental(frame):
    img2 = np.array(255*(frame/255)**1.4, dtype='uint8')
    return img2

def gammaCorrectionCell(img):
    img3 = np.array(255*(img/255)**0.8, dtype='uint8')
    return img3

def equalizeHistColorButterfly(frame):
    img = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    img[:,:,2] = cv.equalizeHist(img[:,:,2])
    img[:,1,:] = cv.equalizeHist(img[:,1,:])
    img[0,:,:] = cv.equalizeHist(img[0,:,:])
    return cv.cvtColor(img, cv.COLOR_HSV2BGR)

def medFiltMom(img):
    img = median_filter(img, 3)
    return img

while(True):
    ret, butterframe = butterfly.read()
    ret2, dental2 = dental.read()
    butterf = equalizeHistColorButterfly(butterframe)
    dentalf = gammaCorrectionDental(dental2)
    combi2 = cv.hconcat((dental2, dentalf))
    combi = cv.hconcat((butterframe, butterf))
    cellsf = gammaCorrectionCell(cells)
    combi3 = hconcat((cells, cellsf))
    momf = medFiltMom(momandkids)
    combi4 = hconcat((momandkids, momf))
    cv.imshow("Cells27 :: Left: without enhancement, Right: with gamma correction of 0.8", combi3)
    cv.imshow("Butterfly :: Left: without enhancement, Right: with histogram equalization", combi)
    cv.imshow("Dental :: Left: without enhancement, Right: with gamma correction of 1.4", combi2)
    cv.imshow("Mom and Kids :: Left: without enhancement, Right: with median filter", combi4)
    if cv.waitKey(0) & 0xFF == ord('q'):  # press q to quit
        break

butterfly.release()
dental.release()
cv.destroyWindow