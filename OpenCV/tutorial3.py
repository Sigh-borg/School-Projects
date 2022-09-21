# Cameras and Video Capture
import numpy as np
import cv2

cap  = cv2.VideoCapture(0)      # Loads a video capture device. The number represents the number of the video device you want to use,
                                # if you have multiple. You can also put in the file name of a mov file you wish to load.
                                # Will not work if another program is using the desired video device.

# Keep displaying the video capture device
while True:
    ret, frame = cap.read()     # cap.read() returns the frame (the image itself) and ret (Boolean that tells you whether the
                                # capture worked)

    # There are about 17 total properties of the capture object. You access them using cap.get(int)
    width = int(cap.get(3))          # Returns the width of your video capture. 3 is the identifier for the property, width.
    height = int(cap.get(4))         # Returns the height of your video capture. 4 is the identifier for the property, height.
        # cap.get will return these values as floating point values. They must be converted to integers to use them in a numpy slice.
        
    
    # Mirroring video multiple times
    image = np.zeros(frame.shape, np.uint8)     # np.zeros() creates a numpy array filled with zeroes (black screen).
                                                # You must pass in the shape of the array you want to create (frame.shape).
                                                # np.unit8 defines the type of values of the array.

    smaller_frame = cv2.resize(frame, (0,0), fx = 0.5, fy = 0.5)    # smaller_frame is a quarter of the size of frame.
                                                                    # You can now fit 4 smaller_frame video captures onto the 
                                                                    # black screen created by the numpy array from np.zeros()
    
        # Pasting the smaller_frame slices into the black screen numpy array.
    image[:height//2, :width//2] = smaller_frame                                    # Top left. 
    image[height//2:, :width//2] = smaller_frame                                    # Bottom left. 
    image[:height//2, width//2:] = cv2.rotate(smaller_frame, cv2.cv2.ROTATE_180)    # Top right. Rotated 180 degrees.
    image[height//2:, width//2:] = smaller_frame                                    # Bottom right
        # Can't be rotated 90 degrees because the height and width values get swapped, making the shape incorrect.

    cv2.imshow('frame', image)  # Displays image with the window name 'frame'

    if cv2.waitKey(1) == ord('q'):      # cv2.waitKey(1) waits 1 millisecond for a button to be pressed, otherwise it proceeds to next line.
        break                           # If a button is pressed, it returns the ASCII integer value of the key pressed.

cap.release()       # Releases the camera resource so another program is now able to use the camera. cv2.VideoCapture(0) is what originally
                    # takes hold of the camera. cap.release() releases it.

cv2.destroyAllWindows()
