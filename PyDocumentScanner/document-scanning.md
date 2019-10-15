# Document-Scanner

This is a simple a document scanner, made with very popular library for computer vision **OpenCV**, then I have used **scikit-image** for giving a black and white touch to the file.
The process is to first resizing the image to a desired height, converting the image to grayscale, then finding all contours present in the file.

 There is a assumption that the numbers of the sides in the piece of paper to be scanned  is equal to four.

Then, we get the top-view of the image and atlast, we give it a black and white touch.
