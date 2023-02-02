import sys
from PyQt5 import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import serial
import time

#   necessary settings for serial communication

ser = serial.Serial(port='COM3', baudrate=1200, bytesize=8, parity='N', stopbits=1, timeout=2)
time.sleep(2)  # delay for error-free serial communication settings

class window(QMainWindow):
    def __init__(self):
        super().__init__()
# Connecting with the self parameter to access the interface designs and adjustments when needed        
        self.arayuz()
        self.button1() 
        self.button2()  
        self.menu_file()      
        self.dial_window()   
        self.servo()
        self.setStyleSheet("background-color: PALETURQUOISE ")  # interface background coloring
      


#---------->> size, position and naming of the interface window <<------------

    def arayuz(self):
        self.setWindowTitle("slider")
        self.setGeometry(450,200,500,400)
        

#------->> Creating a button to turn on the leds and calling the connection signal <<--------

    def button1(self):
        ekran1 = QPushButton(self)
        ekran1.move(150,50)
        ekran1.setText("LED ACTIVE")
        ekran1.setStyleSheet("background-color: red;")
        ekran1.clicked.connect(self.Button_On)
       
#------>> button creation and connection signal to turn off buttons <<--------------

    def button2(self):
        ekran2 = QPushButton(self)
        ekran2.move(300,50)
        ekran2.setText("LED OFF")
        ekran2.setStyleSheet("background-color: green;")
        ekran2.clicked.connect(self.Button_Off)     
       


 #--->> Creating the menu window to control the party and ambulance leds and creating the connection and signal flow <<----

    def menu_file(self):
        menu = QMenuBar(self)
        file = menu.addMenu("SİRENLER")
        file.addAction("ampulans sireni")
        file2 = menu.addMenu("PARTİ")
        file2.addAction("PARTİ LED")
        file2.triggered.connect(self.parti)
        file.triggered.connect(self.ambulans_sireni)
   
 

#--->> Creating the dial window to control the servo motor and setting the initial value to 0 and printing the changed values ​​on the interface screen instantly <<----

    def dial_window(self):
        self.dial = QDial(self)
        self.dial.setGeometry(200,200,100,100)
        self.dial.setNotchesVisible(True)
        self.dial.setNotchTarget(15)
        self.dial.setStyleSheet("background-color: purple;")
        self.dial.setMaximum(180)
    
        value = 0
        self.dial.setValue(value)
        self.label = QLabel(self)
        self.label.setText("value = " +str(value))
        self.label.setGeometry(320,150,200,200)
   

        self.label.setWordWrap(True)
        self.dial.valueChanged.connect(self.servo)           # signal connection for data transfer to servo motor
        


#---->> The part that transfers the data received from the dial window to the microcontroller <<-----

    def servo(self):
        angel2 = int(self.dial.value())
        self.label.setText("value =" +str(self.dial.value()))  # allows us to see the instantaneously changing values ​​in the interface
        ser.write(('5'+chr(angel2)).encode('latin_1'))  

        self.show()     



# Two bytes of data are sent.
#  The first byte is the communication protocol and tells the microcontroller from which part to send data.
# The second byte is the sent data and according to this data, processing is done in the microcontroller.

# process data to turn on leds

    def Button_On(self):
      ser.write('1A'.encode('latin_1')) 
     
# sending data to operate ambulance leds  
    
    def ambulans_sireni(self):
       ser.write('2B'.encode('latin_1')) 
       
# sending data to operate party leds

    def parti(self):
        ser.write('3C'.encode('latin_1'))
     
# process data to turn off leds

    def Button_Off(self):
        ser.write('4D'.encode('latin_1'))
              


#-------->> code to keep the interface window open until you close it <<-----------

if __name__ == '__main__':
    app = QApplication(sys.argv)
    calis = window()
  
    sys.exit(app.exec_())