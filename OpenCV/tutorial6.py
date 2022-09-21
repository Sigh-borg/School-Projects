# Corner Detection
import numpy as np
import cv2

img = cv2.imread('assets/chessboard.png')        # Use the original image to draw the corners on
img = cv2.resize(img, (0,0), fx=0.5, fy=0.5)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)     # Convert from BGR to gray scale. Use this new image to detect the corners.

corners = cv2.goodFeaturesToTrack(gray, 100, 0.01, 10)   # Returns numpy array of coordinates of the corners. Float data type.
    # Pass source image, the N number of best corners you want to return, minimum quality of corner ((0) Not sure - (1) Certain corners),
    # minimum euclidean (absolute value) distance between two corners (won't return multiple corners within this distance)
corners = np.int0(corners)  # Convert float numpy array to int numpy array

# Draw circles on each corner
for corner in corners:
    # Tuple/list decomposition
    x, y = corner.ravel()       # .ravel() flattens an array (Removes all the interior arrays)
                                # Ex: [[1,2], [2,1]] -> [1, 2, 2, 1] or in this case, [[x,y]] -> [x,y] 
    cv2.circle(img, (x,y), 5, (255, 0,0), -1)   # Draws a filled blue circle at each corner detected in img.

# Drawing lines between corners
for i in range(len(corners)):
    for j in range(i+1, len(corners)):
        corner1 = tuple(corners[i][0])      # Convert list to tuple (a corner coordinate point)
        corner2 = tuple(corners[j][0])      # Convert list to tuple (a corner coordinate point)
            # Remember that corners has not been "flattend" by .ravel().
            # This is why the 0th index must be taken, because this gives access to the interior array (first element)
        color = tuple(map(lambda x: int(x), np.random.randint(0,255, size=3)))    # Generates 3 random color values. 
            # np.random.randint(0,255,size=3) will return a list of 32 or 64 bit integers (numpy integers)
            # but python wants only regular 8-bit integers.
            # map applies a function (lambda x: int(x) in this case) to every single element from the np.random.randint array
            # and then it will return a new array that has all of the results from the function.
                # A lambda function is an anonymous function. x is the parameter and int(x) is the return value
                    # In this case, x will be every single element from the randomly generated list of integers
                    # which will be converted into a regular python int.
            # Finally it must be converted to tuple because color must be a tuple, not a list     
        cv2.line(img, corner1, corner2, color, 1)      # Draw line between corners

cv2.imshow('Frame', img)
cv2.waitKey(0)
cv2.destroyAllWindows()