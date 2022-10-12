# Assembly instructions

The PCB and the lens must be removed from the optical mouse. The VDD, GND, MISO, MOSI, NCS and SCLK must be soldered to wires leading to the microcontroller with the microcontroller 3.3V power supply output. The SCLK is the clock selected on the ADNS-3050.h C++ library (in our case 4 MHz, the internal clock divided by 21 of the Arduino DUE used for the SQUAL measurements). The NCS pin allows communication with more than one device by changing the state to HIGH or LOW. The MOSI and MISO pins are to send the data in both directions.

| ![Figure1](img/Fig2-ADNS3050%20.PNG) |
|:--:|
| *Figure 1. Soldered pins on the ADNS-3050* |

The lens and the PCB are assembled with the PCB holder part 1 and 2 by placing the lens as in Figure 1 and inserting the screws to attach both parts together. 

| ![Figure2](img/Fig3-ADNS3050%20.PNG) |
|:--:|
| *Figure 2. ADNS-3050 and lens assembled with the PCB holder.* |

The provided library was created by Tom Wiggins and is available on GitHub [[1]](#references) and Hackaday [[2]](#references). The library has been modified duplicating the functions needed to control and get data from two optical mice.

# References

[1] [https://github.com/Tom101222/Adns-3050-Optical-Sensor](https://github.com/Tom101222/Adns-3050-Optical-Sensor)

[2] [https://hackaday.io/project/18344-adns-3050-optical-sensor-mouse](https://hackaday.io/project/18344-adns-3050-optical-sensor-mouse)