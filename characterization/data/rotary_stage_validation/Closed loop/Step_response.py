import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
plt.style.use('seaborn-white')

# Import from excel
setpoint = pd.read_excel('1001200.xlsx',usecols="E")
angle = pd.read_excel('1001200.xlsx',usecols="F")
t = pd.read_excel('1001200.xlsx',usecols="G")

# Plot the results
plt.plot(t[1700:2000],setpoint[1700:2000])
plt.plot(t[1700:2000],angle[1700:2000])
plt.ylabel('Angle (deg)')
plt.xlabel('Time (s)')
plt.title('Step response at 100 deg/s')
#plt.ylim(0, 250)
#plt.xlim(37, 90)
plt.show()

# Import from excel
setpoint_20 = pd.read_excel('20200.xlsx',usecols="E")
angle_20 = pd.read_excel('20200.xlsx',usecols="F")
t_20 = pd.read_excel('20200.xlsx',usecols="G")

# Plot the results
plt.plot(t_20[4000:5300],setpoint_20[4000:5300])
plt.plot(t_20[4000:5300],angle_20[4000:5300])
plt.ylabel('Angle (deg)')
plt.xlabel('Time (s)')
plt.title('Step response at 20 deg/s')
#plt.ylim(0, 250)
#plt.xlim(37, 90)
plt.show()


# Normalized step response 20 deg/s

setpoint_20_norm = setpoint_20/90
angle_20_norm = angle_20/90

plt.plot(t_20[4000:5300],setpoint_20_norm[4000:5300])
plt.plot(t_20[4000:5300],angle_20_norm[4000:5300])
plt.ylabel('Normalized step response')
plt.xlabel('Time (s)')
plt.title('Step response at 20 deg/s')
#plt.ylim(0, 250)
#plt.xlim(37, 90)
plt.show()

# Normalized step response 100 deg/s

setpoint_norm = setpoint/90
angle_norm = angle/90

# Plot the results
plt.plot(t[1700:2000],setpoint_norm[1700:2000])
plt.plot(t[1700:2000],angle_norm[1700:2000])
plt.ylabel('Angle (deg)')
plt.xlabel('Time (s)')
plt.title('Step response at 100 deg/s')
#plt.ylim(0, 250)
#plt.xlim(37, 90)
plt.show()
