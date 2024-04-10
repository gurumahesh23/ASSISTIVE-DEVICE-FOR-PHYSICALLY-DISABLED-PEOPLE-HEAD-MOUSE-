## Conference Paper

I have written a conference paper for this project.You can access the paper (https://www.overleaf.com/read/vrfbndmvqhxd#9e6634).


# ASSISTIVE-DEVICE-FOR-PHYSICALLY-DISABLED-PEOPLE-HEAD-MOUSE-
This project utilizes an MPU6050 accelerometer and gyroscope sensor along with an Arduino Micro to create a head mouse system. The head mouse allows users to control the cursor on a computer screen by moving their head, providing an alternative input method for individuals with limited mobility.

## Hardware Components
- Arduino Pro Micro
- MPU6050 Accelerometer and Gyroscope Sensor
- Connecting wires
- Breadboard
- USB cable for Arduino Micro
- Bluetooth module HC-05

## Software Requirements
- Arduino IDE

## Circuit Diagram
<div align="center">
  <img alt="circuit Diagram" src="CIRCUIT DIAGRAM.jpg" width="400" height="300" />
</div>


## Installation and Setup
1. Connect the MPU6050 sensor to the Arduino Micro according to the circuit diagram.
2. Download and install the Arduino IDE from [here](https://www.arduino.cc/en/software).
4. Open the Arduino IDE and load the `CODE.ino` sketch from the downloaded repository.
5. Connect the Arduino Micro to your computer using a USB cable.
6. Select the correct board and port in the Arduino IDE.
7. Upload the sketch to the Arduino Micro.

## Usage
1. Once the sketch is uploaded, the system is ready to use.
2. Place the MPU6050 sensor on a suitable position on your head.
3. Tilt your head in the desired direction to control the cursor on the computer screen.
4. Click actions can be performed using additional buttons connected to the Arduino Micro.

## Block Diagram
<div align="center">
  <img alt="Block Diagram" src="BLOCK DIAGRAM.png" width="600" height="400" />
</div>


## CONNECTIONS
Arduino Pro Micro to MPU6050:
- VCC TO VCC
- GND TO GND
- SCL TO PIN3
- SDA TO PIN2

Arduino Pro Micro to Bluettoth Module:
- VCC TO VCC
- GND TO GND
- TXD TO RXD
- RXD TO TXD

# Code Explanation

## Initialization
- The code initializes serial communication for debugging purposes and starts communication with the MPU6050 sensor via I2C.

## Main Loop
1. **Reading Sensor Data**:
   - Sensor data (accelerometer and gyroscope readings) are obtained using the `getMotion6()` function of the MPU6050 library.

2. **Calculating Cursor Movement**:
   - The values from the gyroscope readings (gx and gy) are adjusted to control the cursor movement (vx and vy).
   - These values are then passed to the `Mouse.move()` function to move the cursor accordingly.

3. **Assisted Click Feature**:
   - The code checks if the cursor movement is within a small range of the previous position (10-pixel square).
   - If the cursor remains stationary within this range for a predefined period (2 seconds), it triggers a mouse click.
   - The assisted click feature helps users perform clicks by pausing the cursor movement.

4. **Updating Cursor Position**:
   - The previous cursor position (vx_prec and vy_prec) is updated to track the movement and enable the assisted click feature.
   - A counter (count) is reset if the cursor moves, ensuring the assisted click feature is only triggered when the cursor remains stationary.

5. **Delay**:
   - A small delay (20 milliseconds) is added to control the loop execution rate.

## Test and Calibration
- The code includes comments guiding users on how to calibrate the cursor movement values (vx and vy) based on their specific setup.
- By using a test code, users can adjust the values to ensure accurate cursor movement according to their head movements.


## Result
<div align="left">
  <img alt="OPENING A WEB APPLICATION BY AUTO CLICKING" src="OPENING A WEB APPLICATION BY AUTO CLICKING.JPG" width="400" height="300" />
</div><br>
It appears that the website is being automatically accessed with an automated click occurring within a 5-second interval.<br><br>
<div align="left">
  <img alt="CURSOR MOVING TOWARDS LEFT" src="CURSOR MOVING TOWARDS LEFT.jpg" width="400" height="300" />
</div><br>
It appears that the Cursor moving towards the left side of the screen.<br><br>
<div align="left">
  <img alt="CURSOR MOVING TOWARDS RIGHT" src="CURSOR MOVING TOWARDS RIGHT.jpg" width="400" height="300" />
</div><br>
It appears that the Cursor moving towards the Right side of the screen.<br><br>






