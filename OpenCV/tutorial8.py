# Face and Eye Detection
import numpy as np
import cv2

cap = cv2.VideoCapture(0)

# A HAAR Cascade is a pre-trained classifier. It will look at an image and try to pick out distinct features.
# The Cascades have been trained on millions of images to determine what features make up its specified classifier

# Loading HAAR Cascade Classifiers
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')
    # Pass the path to the classifier + the pre-trained HAAR cascade classifier that we want.


while True:
    ret, frame = cap.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)      # Convert image to grayscale to pass it to face cascade. Then
                                                        # the face cascade will return all of the locations of faces.
                                                        # The cascade requires the image to be in grayscale to function.
    faces = face_cascade.detectMultiScale(gray, 1.05, 5)     # detectMultiScale returns the locations of all of the faces in terms of positions.
        # Pass the base image, the scaleFactor (Parameter specifying how much the image size is reduced at each image scale), 
        # minNeighbors (Parameter specifying how many neighbors each candidate rectangle should have to retain it),
        # minSize, maxSize
            # scaleFactor:
                # The HAAR cascade doesn't know the size of the image we are giving it. That means we may have to change the size of the image
                # such that the HAAR cascade has something that it can compare it against to. For example, the HAAR cascade was likely not
                # trained on images of 10000 x 10000 pixels, so we need to shrink the base image. The scaleFactor tells us how much the
                # image shrinks by in each iteration. In this example, the image is shrunken by 5% in each iteration. The smaller the value,
                # the higher the accuracy but also the slower the algorithm. The recommended value is 1.05 (5%).
            #  minNeighbors:
                # The HAAR cascade returns a bunch of positions of potential faces. This parameter tells us how many overlapping candidate
                # rectangles do we use in an area before we determine what is actually a face.
                # This parameter will affect the quality of the detected faces. Higher value results in less detection but with higher
                # quality. The recommended value is 3-6
            # minSize:
                # Minimum possible object size. Objects smaller than that are ignored 
            # maxSize:
                # Maximum possible object size. Objects smaller than that are ignored
    
    for (x, w, y, h) in faces:      # Loop through all of the rectangles containing faces
        cv2.rectangle(frame, (x,y), (x + y, y + h), (255, 0, 0), 5)     # Draw rectangle around detected face on frame
        roi_gray = gray[y:y+h, x:x+w]       # Store the pixels of the detected rectangle from the grayscale image in roi_gray.
        roi_color = frame[y:y+h, x:x+w]     # Store the pixels of the detected rectangle from the color image in roi_color.
        eyes = eye_cascade.detectMultiScale(roi_gray, 1.05, 5)   # Stores locations of eyes on the detected faces on the grayscale image.
                                                                # Remember that the grayscale image is not the same size as frame
                                                                # (original image).
        for (ex, ey, ew, eh) in eyes:   # Loop through all of the rectangles containing eyes
            cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (0, 255, 0), 5)  # Draw rectangle around detected eyes on roi_color

    cv2.imshow('frame', frame)

    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()