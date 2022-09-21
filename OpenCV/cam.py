import cv2, numpy as np 

# how to load a video capture device 

cam = cv2.VideoCapture(0)

orang = cv2.imread('assets/orangu.png',1)

while True: 
    ret, frame = cam.read() # returns the frame(image itself) and ret(tells you if capture worked properly) 
    width = int(cam.get(3)) # gives us width property of capture object 
    height = int(cam.get(4))

    
    image = np.zeros(frame.shape, np.uint8)  
    smaller_frame = cv2.resize(frame, (0,0), fx=0.5, fy=0.5) 

    x, y, z = smaller_frame.shape
    orang = cv2.resize(orang, (y, x)) 

    image[:height//2, :width//2] = orang   # top left
    image[height//2:, :width//2] = smaller_frame   # bottom left
    image[:height//2, width//2:] = smaller_frame   # top right
    image[height//2:, width//2:] = smaller_frame   # bottom right 

    cv2.imshow('ORANGUTANG CHILLIN', orang)

    #cv2.imshow('frame', frame)                  # Original frame
    #cv2.imshow('smallframe', smaller_frame)     # Smaller frame
    cv2.imshow('4frames', image)                # 4 smaller frames in original frame
    # ord gives ASCII value of key
    if cv2.waitKey(1) == ord('q'):              # The value in waitKey is in milliseconds. Change it to change the Frames per second.
        break 

cam.release() 
cv2.destroyAllWindows() 