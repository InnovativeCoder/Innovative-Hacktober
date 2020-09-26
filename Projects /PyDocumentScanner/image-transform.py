import numpy as np
import cv2

# pts is the list of four points(x,y) specifying the coordinates of the rectangle
def order_points(pts):
	# sample pts: [[x1,y1],[x2,y2],[x3,y3],[x4,y4]] this can be arbitary
	# initialize  a list of coodinates 
	# first-entry: top-left corner, with the smallest x+y sum
	# second-entry: top-right corner, with the smallest x-y difference
	# third-entry: botton-right, with the largest x+y sum
	# fourth-entry: bottom-left , with the largest x-y difference
	rect =np.zeros((4,2), dtype='float32')
	
	s = pts.sum(axis = 1)
	rect[0] = pts[np.argmin(s)] # the top-left corner will have the minimum value
	rect[2] = pts[np.argmax(s)]	# the bottom-right corner will have the maximumn value

	diff = np.diff(pts, axis=1)
	rect[1] = pts[np.argmin(diff)] # the top-right corner will have least difference
	rect[3] = pts[np.argmax(diff)] # the bottom-left corner will have largest difference
	
	return rect

def four_transform(image, pts):
	# Obtaining a constant ordered points from the given points
	rect = order_points(pts)
	(tl, tr, br, bl) = rect

	# computing the maximum width of the new image, 
	widthA = np.sqrt(((br[0] - bl[0]) ** 2) + ((br[1] - bl[1]) ** 2))
	widthB = np.sqrt(((tr[0] - tl[0]) ** 2) + ((tr[1] - tl[1]) ** 2))
	maxWidth = max(int(widthA), int(widthB))

	# computing the maximum height of the new image
	heightA = np.sqrt(((tr[0] - br[0]) ** 2) + ((tr[1] - br[1]) ** 2))
	heightB = np.sqrt(((tl[0] - bl[0]) ** 2) + ((tl[1] - bl[1]) ** 2))
	maxHeight = max(int(heightA), int(heightB))

	# now getting the dimensions of the new image, for a consistent ordering representation
	dst = np.array([
		[0, 0],
		[maxWidth - 1, 0],
		[maxWidth - 1, maxHeight - 1],
		[0, maxHeight - 1]], dtype = "float32")
 
	#
	#rect: coordinates of quadrangle vertices
	#dst: coordinates of the corresponding quarangle vertices in destination image
	#M: actual transformation matrix
	#warped: top-down view of the image 
	#compute the perpective transform matrix and the apply it
	M = cv2.getPerspectiveTransform(rect, dst)
	warped = cv2.warpPerspective(image, M, (maxWidth, maxHeight))

	return warped