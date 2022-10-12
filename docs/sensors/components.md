# Optical motion sensors

## Sensors

To measure the position of the sphere, we used two PCB boards based on the Avago Technologies ADNS-2610 [[1]](#references) optical flow sensor and extracted from the Logitech M-SBF96 PS2 computer mouse. This sensor presents high reliability for speeds under 30.5 cm/s, and has a register that outputs the SQUAL value, a reference for the quality of the surface. This SQUAL value can be used for calibration and optimization. 


| ![Figure1](img/Fig1-Optical-Motion_Sensors.png) |
|:--:|
| *Figure 1. Pinout of the ADNS-2610* |

The PCB and lens are attached to a 3D printable structure and assembled with 3 Thorlabs components.

| ![Figure2](img/Fig4-Optical-Motion_Sensors.png) |
|:--:|
| *Figure 2. Optical sensor* |

## Bill of materials (per sensor)

The 3D-printed parts have been designed to be printed optimally with an Objet 30 (Polyjet resin printer), but have also been printed with a Form 2 (SLS resin printer). We used the Vero gray resin and the Clear V4 resin with the Objet 30 and the Form 2 respectively. Printer settings were kept at default.

| Component          | Quantity | Supplier      | Reference                                                                                               |
|--------------------|----------|---------------|-----------------------------------------------------------------------------------------------------------|
| Optical mouse      | 1        | -             | [example link](https://www.ebay.com/itm/232746871340) |
| Sensor holder      | 1        | 3D printed    | [STEP file](files/Sensor%20holder.stp), [STL file](files/Sensor%20holder.stl)                            |
| PH75/M             | 1        | Thorlabs      | [link](https://www.thorlabs.com/thorproduct.cfm?partnumber=PH75/M)                                           |
| RA180/M            | 1        | Thorlabs      | [link](https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=1985&pn=RA180#6066)                        |
| TR75V/M            | 1        | Thorlabs      | [link](https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=1266&pn=TR75V/M#7832)               |
| M3 x 6 mm          | 2        | RS Components | [link](https://uk.rs-online.com/web/p/grub-screws/0137720)                                             |
| M3 threaded insert | 2        | RS Components | [link](https://uk.rs-online.com/web/p/threaded-inserts/0278534)                                       |

# References

[1] [ADNS-2610 datasheet](datasheets/ADNS-2610.pdf)
