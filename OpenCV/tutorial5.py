# Colors and Color Detection

'''
Acronyms:
    RGB: Red, Green, Blue
    BGR: Blue, Green, Red
    HSV: Hue, Saturation, Lightness/Brightness
'''

import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    width = int(cap.get(3))
    height = int(cap.get(4))

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)        # Create an hsv image. COLOR_BGR2HSV takes BGR pixel values and converts to HSV.
        # Pass the source image, conversion wanted
    
    '''
    Convert colors manually
    BGR_color = np.array([[[255,0,0]]])               numpy array with one pixel
    x = cv2.cvtColor(BGR_color, cv2.COLOR_BGR2HSV)    passes an image that has one pixel. This converts one blue pixel to HSV
    x[0][0]         Access the one pixel
    '''

    # Define lower bound and upper bound for the pixels we want to extract.
        # -colors determined using HSV color picker
    lower_blue = np.array([90, 50, 50])        # Lighter blue
    upper_blue = np.array([130, 255, 255])      # Darker blue

    mask = cv2.inRange(hsv, lower_blue, upper_blue)     # Returns a new "mask" of the hsv image with only the blue pixels within the range
                                                        # This mask tells us which pixels to use within the range.
                                                        # The mask is composed of 0s and 1s. Pixels within the range get a 1, and
                                                        # pixels outside the range get a 2.
        # Pass hasv, lower bound, upper bound

    result = cv2.bitwise_and(frame, frame, mask=mask)   # Takes 2 source images and will blend them together, using mask as a function 
                                                        # to determine whether it should keep a certain pixel.
                                                        # In this case, it will return only the blue pixels and keep the others as black.
        # Pass source image 1, source image 2, mask 

    cv2.imshow('Frame', result)                         # Display result
    cv2.imshow('Mask', mask)                            # Display mask. The mask is all 0s and 1s. All that is white in the mask is what's
                                                        # showing up in the result            

    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cap.destroyAllWindows()