# Drawing (Lines, Images, Circles & Text)

import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    width = int(cap.get(3))
    height = int(cap.get(4))


    # Draw a line
    img = cv2.line(frame, (0,0), (width, height), (255, 0, 0), 10)      # Draws a blue line from the top left (0,0)
                                                                        # to the bottom right (width, height)
        # Pass in the source image, the start position, end position, BGR of line, and pixel thickness
    img = cv2.line(img, (0,height), (width, 0), (0, 255, 0), 5)         # Draws a green line from bottom left (0, height)
                                                                        # to top right (width, 0)
        # Must pass in img to get both lines to show up.

    # Draw a rectangle
    img = cv2.rectangle(img, (100,100), (200, 200), (128, 128, 128), 5) # Draws an unfilled grey rectangle with top left at (100,100)
                                                                        # and bottom right at (200,200). The border has thickness of 5 pixels.
        # Pass in source image, the top left, bottom right, BGR, and border thickness (-1 to fill).

    # Draw a circle
    img = cv2.circle(img, (300,300), 60, (0,0,255), -1)                 # Draws a filled red circle with center position (300,300)                                                           
                                                                        # and radius of 60 pixels. 
        # Pass in source image, center position, radius, border thickness (-1 to fill)

    # Drawing text
        # -drawing text requires a font to be created first.
    font = cv2.FONT_HERSHEY_SIMPLEX                     # Select font
    img = cv2.putText(img, 'Brian was here!', (10, height-10), font, 1, (0,0,0), 5, cv2.LINE_AA)    # Draws black text in bottom left
                                                                                                    # (10, height-10)with font size 1
        # Pass in source image, text, centered position, font, font scale (size), BGR, line thickness (no -1), line type (usually cv2.LINE_AA)            

    cv2.imshow('frame', frame)

    if cv2.waitKey(1) == ord('q'):
        break   

cap.release()
cv2.destroyAllWindows()