#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>
#include <SoftwareSerial.h>
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy, vx_prec, vy_prec;
int count = 0;
SoftwareSerial bluetoothSerial(0,1); // RX (HC-05 TX), TX (HC-05 RX)
for Bluetooth module
#define DEBUG_SERIAL Serial
void setup() {
DEBUG_SERIAL.begin(9600);
Wire.begin();
mpu.initialize();mbn
if (!mpu.testConnection()) {
DEBUG_SERIAL.println("MPU6050 connection failed. Please check your connections.");
while (1);
}
DEBUG_SERIAL.println("MPU6050 connection successful!");
Mouse.begin();
// Initialize SoftwareSerial for Bluetooth communication
bluetoothSerial.begin(9600); // You may need to adjust the baud rate
to match your HC-05 module
DEBUG_SERIAL.println("Bluetooth module connected!");
}
void loop() {
// Read sensor data
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
vx = (gx + 300) / 200;
vy = -(gz - 100) / 200;
Mouse.move(vx, vy);
// Check for mouse click
if ((vx_prec - 5) <= vx && vx <= vx_prec + 5 && (vy_prec - 5) <= vy
&& vy <= vy_prec + 5) {
count++;
if (count == 50) {
if (!Mouse.isPressed(MOUSE_LEFT)) {
Mouse.press(MOUSE_LEFT);
count = 0;
}
} else {
if (Mouse.isPressed(MOUSE_LEFT)) {
Mouse.release(MOUSE_LEFT);
} } }
else {
vx_prec = vx;
vy_prec = vy;
count = 0;
}
delay(10);
// Bluetooth communication
while (bluetoothSerial.available()) {
char data = bluetoothSerial.read();
DEBUG_SERIAL.write(data);
}
// Serial communication for debugging
while (DEBUG_SERIAL.available()) {
char data = DEBUG_SERIAL.read();
bluetoothSerial.write(data); }}