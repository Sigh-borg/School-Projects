# Intro to Open CV and Images

import cv2 

img = cv2.imread('assets/orangu.png', 1) # must be png or jpg?
'''
(-1), cv2.IMREAD_COLOR: loads a color image, any transparency components of image will be neglected
(0), cv2.IMREAD_GRAYSCALE: loads image in grayscale mode (black and white pixels)
(1), cv2.IMREAD_UNCHANGED: loads image as such including alpha channel (includes transparency) 
'''

# Resize and rotate the iamge
img = cv2.resize(img, (900,800))
#img = cv2.resize(img, (0,0), fx = 0.5, fy = 0.5)  Resizes by the multiple of fx and fy. In this case, the image will will be half the size.
img = cv2.rotate(img, cv2.cv2.ROTATE_90_CLOCKWISE) 

cv2.imshow('ORANGUTANG CHILLIN', img) # creating a window with name "ORANGUTANG CHILLIN", with img inside the window

# needs an option to close window
cv2.waitKey(0) # wait an infinite amount of time until a key is pressed 
               # (if an int is used instead of 0, will wait that time in seconds, then move onto next line)
cv2.destroyAllWindows() 

# Saves all the changes done to the image above to a new file
cv2.imwrite('orangu_rot.png',img) 