# Using Mediapipe to control Gripper

Hand Detector and servo control/Python Code

```python
import cv2
import serial
import mediapipeas mp
import math
import numpyas np
import time
import pyfirmata

#--------------

board = pyfirmata.Arduino('COM3')
servo = board.get_pin('d:9:s')

mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
mp_hands = mp.solutions.hands

# Webcam Setup
wCam, hCam = 640, 480
cam = cv2.VideoCapture(0)
cam.set(3,wCam)
cam.set(4,hCam)

with mp_hands.Hands(
    model_complexity=0,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5)as hands:

while cam.isOpened():
    success, image = cam.read()

    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    results = hands.process(image)
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
if results.multi_hand_landmarks:
for hand_landmarksin results.multi_hand_landmarks:
        mp_drawing.draw_landmarks(
            image,
            hand_landmarks,
            mp_hands.HAND_CONNECTIONS,
            mp_drawing_styles.get_default_hand_landmarks_style(),
            mp_drawing_styles.get_default_hand_connections_style()
            )

# multi_hand_landmarks method for Finding postion of Hand landmarks
    lmList = []
if results.multi_hand_landmarks:
      myHand = results.multi_hand_landmarks[0]
for id, lmin enumerate(myHand.landmark):
        h, w, c = image.shape
        cx, cy = int(lm.x * w), int(lm.y * h)
        lmList.append([id, cx, cy])

# Assigning variables for Thumb and Index finger positionif len(lmList) != 0:
      x1, y1 = lmList[4][1], lmList[4][2]
      x2, y2 = lmList[8][1], lmList[8][2]

# Marking Thumb and Index finger
      cv2.circle(image, (x1,y1),15,(255,255,255))
      cv2.circle(image, (x2,y2),15,(255,255,255))
      cv2.line(image,(x1,y1),(x2,y2),(255,0,0),3)
      length = math.hypot(x2-x1,y2-y1)
if length < 50:
        cv2.line(image,(x1,y1),(x2,y2),(0,0,0),3)

      Pos = np.interp(length, [50, 220], [0, 100])
      Posgripper= (round(Pos))
#print(Posgripper)
      converted_Posgripper = str(Posgripper)
      cv2.putText(image, str(Posgripper), (50, 60), cv2.FONT_HERSHEY_COMPLEX, 2, (255, 0, 0))
#cv2.line(image, 320, 320, (0,0,0), 2)
      Servopos=(100-Posgripper)
      print (Servopos)
      servo.write(Servopos)

    cv2.imshow('handDetector', image)
if cv2.waitKey(1) & 0xFF == ord('q'):
break
cam.release()

```

Arduino Code

```arduino
#include <Servo.h>#include <Firmata.h>Servo servos[MAX_SERVOS];
byte servoPinMap[TOTAL_PINS];
byte servoCount = 0;

voidanalogWriteCallback(byte pin, int value)
{
if (IS_PIN_DIGITAL(pin)) {
    servos[servoPinMap[pin]].write(value);
  }
}

voidsystemResetCallback()
{
  servoCount = 0;
}

voidsetup()
{
  byte pin;

  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.attach(SYSTEM_RESET, systemResetCallback);

  Firmata.begin(57600);
  systemResetCallback();

// attach servos from first digital pin up to max number of// servos supported for the boardfor (pin = 0; pin < TOTAL_PINS; pin++) {
if (IS_PIN_DIGITAL(pin)) {
if (servoCount < MAX_SERVOS) {
        servoPinMap[pin] = servoCount;
        servos[servoPinMap[pin]].attach(PIN_TO_DIGITAL(pin));
        servoCount++;
      }
    }
  }
}

voidloop()
{
while (Firmata.available())
    Firmata.processInput();
}
```