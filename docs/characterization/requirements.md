# Required libraries and software packages

## Software packages
-	[Arduino IDE](https://www.arduino.cc/en/software) 
-	[Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) 

## Required Libraries
-	[Arduino](Arduino/libraries.zip)
-	[ADNS 2160 optical sensor with SQUAL readout](Arduino/libraries.zip) (based on the [OptiMouse library](https://github.com/zapmaker/OptiMouse))
-	[Stepper motor control](https://luni64.github.io/TeensyStep/) 
-	[Encoder](https://github.com/PaulStoffregen/Encoder) 

### Libraries for alternative optical sensors
These are Optical motion sensor options with higher capabilities than the ADNS 2160. All of them use the SPI bus.

-	[ADNS 3500](https://github.com/Tom101222/Adns-3050-Optical-Sensor)
-	[PWM3360](https://github.com/SunjunKim/PMW3360) 
-	[ADNS 9800](https://github.com/mrjohnk/ADNS-9800) 


## Arduino code examples
####[Closed_loop.ino](Arduino/Closed_loop.zip)
The closed loop example uses the optically measured angle increment as a setpoint for the proportional motor control. The animal controls the rotation of the platform.

####[Open_loop.ino](Arduino/Open_loop.zip)
The Open loop example uses two user-defined variables (eg. 0-360 degrees) as setpoints to oscillate between at a user-defined interval.

####[Open_loop_SD.ino](Arduino/Open_loop_SD.zip)
Like the open loop example, but saving the different variables on the SD card on the Teensy 3.5 microcontroller. This program was used to record the accuracy and repeatability measurements.

####[Open_loop_moveAsync.ino](Arduino/Open_loop_moveAsync.zip)
Like Open_loop_SD.ino, but instead of using the proportional control, rotation movement is controlled by the teensystep moveAsync() method, using a non-blocking trapezoidal profile.
