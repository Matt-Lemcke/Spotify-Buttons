#Run module to use the arduino to interact with spotify

import serial
import time
import pyautogui

ArduinoSerial = serial.Serial('com3',9600)
time.sleep(2)

while 1:
    incoming = str (ArduinoSerial.readline())
    print incoming

    if 'pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)

    if 'previous' in incoming:
        pyautogui.hotkey('ctrl', 'left')

    if 'skip' in incoming:
        pyautogui.hotkey('ctrl', 'right')
