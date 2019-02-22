import pygame
import serial
import time
import cv2
arduino = serial.Serial("COM11", 9600)
stream='rtsp://admin:rov@192.168.1.108:554/cam/realmonitor?channel=4&subtype=0/'
points=[]
time.sleep(0.1) #give the connection a second to settlen
Speed=0
#region streaming


#endregion


#region displayProperties
# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
size = [690, 580]  # Set the width and height of the screen [width,height]
class TextPrint:
    def __init__(self):
        self.reset()
        self.font = pygame.font.Font(None, 20)

    def print(self, screen, textString):
        textBitmap = self.font.render(textString, True, WHITE)
        screen.blit(textBitmap, [self.x, self.y])
        self.y += self.line_height

    def printSensors(self, screen ):
        axis = joystick.get_axis(2)
        axis = round(axis, 2)

        global Speed
        if axis ==1:
            Speed = 0
        if axis<1 and axis>=0.5:
            Speed=1
            pygame.draw.rect(screen, (0, 128, 0), [580, 500,20, 25])
        if axis<0.5 and axis>=0.0:
            Speed = 2
            pygame.draw.rect(screen, (0, 128, 0), [580, 500,50, 25])
        if axis<0.0 and axis>=-0.5:
            Speed = 3
            pygame.draw.rect(screen, (0, 128, 0), [580, 500,70, 25])
        if axis<-0.5 and axis>=-1:
            Speed = 4
            pygame.draw.rect(screen, (0, 128, 0), [580, 500,100, 25])
        font = pygame.font.SysFont("comicsans", 30, True)


        text = font.render("speed " , 1, WHITE)
        screen.blit(text, (500,500))
        text = font.render("Temp Sensor : " + str(50), 100, WHITE)
        screen.blit(text, (550, 5))
        text = font.render("Ph Sensor : " + str(50), 100, WHITE)
        screen.blit(text, (550, 25))
        text = font.render ("Pressure sensor: " + str(50), 100 ,WHITE)
        screen.blit(text, (550, 45))
        text = font.render("Leak sensor: " + str(50), 100, WHITE)
        screen.blit(text, (500, 65))
        text = font.render("Current Sensor: " + str(50), 100, WHITE)
        screen.blit(text,(500, 85))


    def reset(self):
        self.x = 10
        self.y = 10
        self.line_height = 15

    def indent(self):
        self.x += 10

    def unindent(self):
        self.x -= 10

pygame.init()
background=pygame.image.load("mm.jpg")
icon=pygame.image.load("q.ico")


screen = pygame.display.set_mode(size)
pygame.display.set_caption("ROV System")
pygame.display.set_icon(icon)

done = False  # Loop until the user clicks the close button.


clock = pygame.time.Clock()  # Used to manage how fast the screen updates


pygame.joystick.init() # Initialize the joysticks


textPrint = TextPrint() # Get ready to print

#endregion


#region directionControl

def up_down(hat):
    if hat[1] == 1:
        textPrint.print(screen, "up")
        up(hat)

    if hat[1] == -1:
        textPrint.print(screen, "down")
        down(hat)
    if hat[0] == 1:
        textPrint.print(screen, "down_V3")
        up_3(hat)

    if hat[0] == -1:
        textPrint.print(screen, "UP_V3")
        down_3(hat)


def axisDirection(axis,i):
    if axis<-0.01 and i==1:
        textPrint.print(screen, "forward")
        forward(axis)

    if axis>-0.01 and i==1:
        textPrint.print(screen, "Back")
        back(axis)

    if axis<-0.01 and i==0:
        textPrint.print(screen, "left")
        left(axis)

    if axis>-0.01 and i==0:
        textPrint.print(screen, "right")
        right(axis)

    if axis>-0.01 and i==3:
        textPrint.print(screen, "forwardRight")
        forwardRight(axis)

    if axis<-0.01 and i==3:
        textPrint.print(screen, "forwardLeft")
        forwardLeft(axis)

    if axis<1 and i==2:
        speed(axis)


def forward(axis):
    global Speed
    arduino.write(bytes('F', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def back(axis):
    global Speed
    arduino.write(bytes('B', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def left(axis):
    arduino.write(bytes('L', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def right(axis):
    arduino.write(bytes('R', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def up(hat):
    arduino.write(bytes('U', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def down(hat):
    arduino.write(bytes('D', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def up_3(hat):
    arduino.write(bytes('u', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def down_3(hat):
    arduino.write(bytes('d', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def forwardRight(axis):
    arduino.write(bytes('T', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def forwardLeft(axis):
    arduino.write(bytes('O', 'utf8'))
    time.sleep(0.1)
    arduino.write(bytes(str(Speed), 'utf8'))
    time.sleep(0.1)
    return

def speed(axis):
    return
#endregion


#region Buttons

def controlButtons(button,i):
    if button == 1 and i == 7:
        restart()
        textPrint.print(screen, "restart")
    if button==1 and i==0:
        openGripper()
        textPrint.print(screen, "openGripper")
    if button == 1 and i == 1:
        closeGripper()
        textPrint.print(screen, "closeGripper")
    if button == 1 and i == 10:
        stopROV()
        textPrint.print(screen, "stopROV")

    if button == 1 and i == 11:
        runROV()
        textPrint.print(screen, "runROV")

    if button == 1 and i == 9:
        runMicro()
        textPrint.print(screen, "runMicro")

    if button == 1 and i == 8:
        tail_move()
        textPrint.print(screen, "stopMicro")

    if button == 1 and i == 4:
        autoMode()
        textPrint.print(screen, "autoMode ON")

    if button == 1 and i == 2:
        screenshot()
        textPrint.print(screen, "Screenshot is taken!")

    if button == 1 and i == 3:
        detectmetal()
        textPrint.print(screen, "Metal is detected!")

    if button == 1 and i == 5:
        calculateshapes()
        textPrint.print(screen, "Calculate Shapes")

def openGripper():
    arduino.write(bytes('G', 'utf8'))
    time.sleep(0.1)
    return

def restart():
    arduino.write(bytes('r', 'utf8'))
    time.sleep(0.1)
    return

def closeGripper():
    arduino.write(bytes('g', 'utf8'))
    time.sleep(0.1)
    return

def stopROV():
    arduino.write(bytes('S', 'utf8'))
    time.sleep(0.1)
    return

def runROV():
    arduino.write(bytes('N', 'utf8'))
    time.sleep(0.1)
    return

def runMicro():
    arduino.write(bytes('M', 'utf8'))
    time.sleep(0.1)
    return

def tail_move():
    arduino.write(bytes('b', 'utf8'))
    time.sleep(0.1)
    return

def autoMode():
    arduino.write(bytes('A', 'utf8'))
    time.sleep(0.1)
    return

def  screenshot():
    arduino.write(bytes('H', 'utf8'))
    time.sleep(0.1)
    return

def detectmetal():
    arduino.write(bytes('m', 'utf8'))
    time.sleep(0.1)
    return

def calculateshapes():
    arduino.write(bytes('P', 'utf8'))
    time.sleep(0.1)
    return
#endregion

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

#region Joystick
#-------- Main Program Loop -----------
cap = cv2.VideoCapture(stream)
ret, frame = cap.read()
cv2.imshow('size',frame)
while done == False:

    key = cv2.waitKey(0)
    if key & 0xFF == ord('q'):
        break
    elif key & 0xFF == ord('s'):
        ret, frame = cap.read()
        cv2.imshow('size', frame)
        cv2.setMouseCallback('size', mouse_callback)

    elif key & 0xFF == ord('d'):
        points = []

    # EVENT PROCESSING STEP
    for event in pygame.event.get():  # User did something
        if event.type == pygame.QUIT:  # If user clicked close
            done = True  # Flag that we are done so we exit this loop

        # Possible joystick actions: JOYAXISMOTION JOYBALLMOTION JOYBUTTONDOWN JOYBUTTONUP JOYHATMOTION
        if event.type == pygame.JOYBUTTONDOWN:
            print("Joystick button pressed.")
        if event.type == pygame.JOYBUTTONUP:
            print("Joystick button released.")

    # DRAWING STEP
    # First, clear the screen to white. Don't put other drawing commands
    # above this, or they will be erased with this command.
    screen.blit(background,[0,0])

    textPrint.reset()

    # Get count of joysticks
    joystick_count = pygame.joystick.get_count()

    textPrint.print(screen, "Number of joysticks: {}".format(joystick_count))
    textPrint.indent()

    # For each joystick:
    for i in range(joystick_count):
        joystick = pygame.joystick.Joystick(i)
        joystick.init()

        textPrint.print(screen, "Joystick {}".format(i))
        textPrint.indent()

        # Get the name from the OS for the controller/joystick
        name = joystick.get_name()
        textPrint.print(screen, "Joystick name: {}".format(name))

        # Usually axis run in pairs, up/down for one, and left/right for
        # the other.
        axes = joystick.get_numaxes()
        textPrint.print(screen, "Number of axes: {}".format(axes))
        textPrint.indent()
        for i in range(axes):
            textPrint.printSensors(screen)
            axis = joystick.get_axis(i)
            axis = round(axis, 2)
            textPrint.print(screen, "Axis {} value: {}".format(i, axis))
            axisDirection(axis,i)



        textPrint.unindent()

        buttons = joystick.get_numbuttons()
        textPrint.print(screen, "Number of buttons: {}".format(buttons))
        textPrint.indent()

        for i in range(buttons):
            button = joystick.get_button(i)
            textPrint.print(screen, "Button {:>2} value: {}".format(i, button))
            controlButtons(button,i)

        textPrint.unindent()

        # Hat switch. All or nothing for direction, not like joysticks.
        # Value comes back in an array.
        hats = joystick.get_numhats()
        textPrint.print(screen, "Number of hats: {}".format(hats))
        textPrint.indent()

        for i in range(hats):
            hat = joystick.get_hat(i)
            up_down(hat)
            textPrint.print(screen, "Hat {} value: {}".format(i, hat))
        textPrint.unindent()

        textPrint.unindent()

    # ALL CODE TO DRAW SHOULD GO ABOVE THIS COMMENT

    # Go ahead and update the screen with what we've drawn.
    pygame.display.flip()

    # Limit to 20 frames per second
    clock.tick(20)
pygame.quit()

#endregion
