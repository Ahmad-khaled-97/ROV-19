import cv2
import numpy as np
points=[]
laser_realsize=3.35
object_realsize=-1
def mouse_callback(event,x,y,flags,data):
    global points
    if event==cv2.EVENT_LBUTTONDOWN and len(points)<4:
        points.append(x)
    elif len(points)==4:
        laser_Size=abs(points[1]-points[0])
        object_size=abs(points[3]-points[2])
        object_realsize=(object_size/laser_Size) * laser_realsize
        print(str(object_realsize)+' CM')
        points=[]
stream='rtsp://admin:rov@192.168.1.108:554/cam/realmonitor?channel=4&subtype=0/'
mobile='http://192.168.1.5:8080/video'
cap = cv2.VideoCapture(stream)
while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()
    # Display the resulting frame
    #resized=cv2.resize(frame,(1024,768))
    resized=frame
    cv2.imshow('frame',resized)
    key=cv2.waitKey(1)
    if key & 0xFF == ord('q'):
        break
    elif key & 0xFF == ord('s'):
        cv2.imshow('size',resized)
        cv2.setMouseCallback('size', mouse_callback)

    elif key & 0xFF == ord('d'):
        points=[]



# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()