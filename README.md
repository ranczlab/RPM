# RPM v2

### HARP implementation of sensors and motor control, Bonsai integration for recording (add HARP synchroniser)
HARP boards
[H1](https://github.com/harp-tech/device.vestibularH1) - on platform
- inputs: optical flow sensor, 2x lick port
- outputs: 2x camera trigger; direct motor command (implemented in hardware?); 2x reward valve; GND, 3-5V and 12-24V power, USB to Bonsai
- bidirectional(?): I/O pin, HARP synchroniser (CLOCK SYNC)
[Full list of H1 registers](https://github.com/harp-tech/device.vestibularH1/blob/main/Firmware/VestibularH1/registers.xls)

[H2](https://github.com/harp-tech/device.vestibularH2) - off platform
- inputs: Hall sensor; rotary encoder (external or from motor driver); emergency stop
- outputs: motor; GND, 3-5V, 5-24V power, USB to Bonsai 
- bidirectional(?): I/O pin, HARP synchroniser (CLOCK SYNC)
[Full list of H2 registers](https://github.com/harp-tech/device.vestibularH2/blob/main/Firmware/VestibularH2/registers.xls)


to add:
### New INMED cameras, camera holders, lenses

### New INMED optical sensors 

### New INMED probe holder (NPX) + NewScale manipulator for insertion 

### New INMED motor - unclear of the specs though

### Attempted head-movement sensing

General folder structure:

<img width="406" alt="image" src="https://github.com/user-attachments/assets/807a13ad-9601-4401-b066-5b36dd310ab4" />

