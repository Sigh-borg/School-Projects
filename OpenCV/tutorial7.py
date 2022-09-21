# Template Matching (Object Detection )
import numpy as np
import cv2

img = cv2.resize(cv2.imread('assets/soccer_practice.jpg', 0), (0,0), fx=0.5, fy=0.5)       # Loaded as grayscale
template = cv2.resize(cv2.imread('assets/ball.PNG', 0), (0,0), fx=0.5, fy= 0.5)           # Template to detect ball. Loaded as grayscale
# template = cv2.resize(cv2.imread('assets/shoe.PNG', 0), (0,0), fx=0.5, fy= 0.5)            # Template to detect the shoe   
    # Note that whenever you resize the base image, you must resize the template image

img2 = img.copy()
h, w = template.shape       # Because it is in grayscale, img is a 2D array, not a 3D array with channels, so a tuple can be used.

# 6 Main Methods for Template Matching
methods = [cv2.TM_CCOEFF, cv2.TM_CCOEFF_NORMED, cv2.TM_CCORR, cv2.TM_CCORR_NORMED, cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]
    # Try all methods and the method that gives you the best result is the one you continue with

# Loop through each method and perform a template matchup to decide which one is best.
for method in methods:
    img2 = img.copy()

    result = cv2.matchTemplate(img2, template, method)  # Performs a convolution; takes the template image and slides it around the base image and
                                                        # sees how close of a match there is in every single region of the base image.
                                                        # Returns another 2D array that tells us roughly how accurate of a match there is in each
                                                        # region of the base image.
                                                        # The resulting 2D array is the size (W - w + 1, H - h + 1).
                                                            # W = width of base image,  w = width of template image.
                                                            # H = height of base image, h = height of template image.
        # Pass source image, template, method (because we are looping through the methods)
    
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)  # minMaxLoc returns the minimum value, the maximum value, 
                                                                # the location of the minimum, the location of the maximum in the array.

    
    if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:     # Determines the correct location.
        # We want to take the minimum location for these 2 methods.  If we dont use these methods, we want the maximum location                                                  
        location = min_loc
    else:
        location = max_loc
    
    bottom_right = (location[0] + w, location[1] + h)       # A tuple that represents the bottom right of the rectangle

    # Draw rectangle at min_loc or max_loc in our base image and display to see if it matched
    cv2.rectangle(img2, location, bottom_right, 255, 5)     # Draw white rectangle with line thickness 5 where the images match.
    
    # Will display all 6 methods of template matching from the methods array. Not all methods will detect the template image correctly.
    cv2.imshow('Match', img2)
    cv2.waitKey(0)
    cv2.destroyAllWindows() 