from image-transform import four_transform
import cv2
import numpy as np
from skimage.filters import threshold_local
import argparse
import cv2
import imutils

def scanner(image):
	# Edge Detection
	# load the image and compute the ratio of old height to the new height, clone it and resize it
	image = cv2.imread(image)
	ratio = image.shape[0] / 500.0
	orig = image.copy()
	image = imutils.resize(image, height=500)

	# convert the image to grayscale, blur it, and find images edges in image
	gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
	grayscale = cv2.GaussianBlur(gray, (5, 5), 0)
	edged = cv2.Canny(gray, 75, 200)

	#cv2.imshow("Image", image)
	#cv2.imshow("Edged", edged)
	#cv2.waitKey(0)
	#cv2.destroyAllWindows()

	# Finding Contours
	# Assume that the longest contour in the image with exactly four points is the piece of the paper
	# to be scanned
	cnts = cv2.findContours(edged.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
	cnts = imutils.grab_contours(cnts)
	# This will filter out all the contours with the largest area
	cnts = sorted(cnts, key = cv2.contourArea, reverse = True)[:5]

	for c in cnts:
		#approximating the contour
		peri = cv2.arcLength(c, True)
		approx = cv2.approxPolyDP(c, 0.02 * peri, True)

		# finding the rectangle if the contour has 4 points
		if len(approx) == 4:
			screenCnt = approx
			break

	cv2.drawContours(image, [screenCnt], -1, (0,255,0), 2)
	#cv2.imshow("Outline", image)
	#cv2.waitKey(0)
	#cv2.destroyAllWindows()

	#orig: original image
	#screenCnt: contour representing the document multiplied by ratio for resizing the original image
	warped = four_point_transform(orig, screenCnt.reshape(4, 2) * ratio)

	#this is for black and white feels
	warped = cv2.cvtColor(warped, cv2.COLOR_BGR2GRAY)
	T = threshold_local(warped, 11, offset=10, method="gaussian")
	warped = (warped > T).astype("uint8") * 255

	#cv2.imshow("Original", imutils.resize(orig, height = 650))
	#cv2.imshow("Scanned", imutils.resize(warped, height = 650))
	#cv2.waitKey(0)

	return warped
