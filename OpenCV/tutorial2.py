# Image Fundamentals and Manipulation

import cv2
import random


# Image Representation

# When you load an image, the compiler extracts the pixels from the image and loads them into a numpy array.
img = cv2.imread('assets/orangu.png', 1)

'''
# print(img)            # Prints the numpy array of t img
# print(type(img))      # Prints that img is a numpy array
# print(img.shape)      # Prints (height, width, channels) of the image aka number of rows, columns, channels
                            # channels are the number of values that represent each pixel; (In order) Blue, Green, Red
# Whenever we are modifying the image with the cv2 methods, we are just manipulating the values inside the numpy array.    
'''

#Accessing Pixel Values
# print(img[257][45:200])       # Prints out pixels in row 257 from columns 45 to 200.        
 


# Changing Pixel Colors
#    -changes all pixels in 100 rows to a random color in the image.
'''
for i in range(100):
   for j in range(img.shape[1]):
       img[i][j] = [random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)]

cv2.imshow('ColoredOrangutan', img)
cv2.waitKey(0)
cv2.destroyAllWindows()                          
'''

# Copying and Pasting parts of an Image

# Numpy array slicing
tag = img[500:700, 600:900]     # In rows 500 to 700, copy columns 600 to 900 into tag.
img[100:300, 650:950] = tag     # Replaces rows 100 to 300, columns 650 to 950 with tag, which is a numpy array slice. 
                                # They must have same dimensions