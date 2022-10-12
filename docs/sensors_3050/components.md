# Optical motion sensors - option 2, ADNS-3050


## Sensors

Another option to measure the sphere's position is to use two PCB boards based on the Avago Technologies ADNS-3050 optical flow sensor. The sensor was extracted from the Cougar Minos X2 gaming computer mouse. This sensor has high motion detection under speeds of 152.4 cm/s and can deal with accelerations up to 20G. It has selectable resolutions up to 2000 cpi (we have used the default configuration of 1000 cpi). Furthermore, the register outputs the SQUAL value, which is used for the calibration and adjustment process.


| ![Figure1](img/Fig1-ADNS3050%20.PNG) |
|:--:|
| *Figure 1. Pinout of the ADNS-3050* |

## Bill of materials (per sensor)
| Component          | Quantity | Supplier      | Reference                                                                                                                                               |
|--------------------|----------|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| Optical mouse      | 1        | -             | [link](https://cougargaming.com/products/mice/minos_x2/)|
| PCB Holder 1     | 1        | 3D printed part             | [STEP file](files/STEP/PCB%20holder.STEP), [STL file](files/STL/PCB%20holder.STL) |
| PCB Holder 2    | 1        | 3D printed part             | [STEP file](files/STEP/PCB%20holder%202.STEP), [STL file](files/STL/PCB%20holder%202.STL) |
| M3 screws       | 4        | RS Components               |                                                                             |

The rest of the components are the same as described in the ADNS 2610 assembly.

# Datasheets
[1] [ADNS-3050 datasheet](datasheets/adns-3050.pdf)


