import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('seaborn')
#plt.style.use('grayscale')

# Import from excel
encoder_angle = pd.read_excel('Rotary stage calibration.xlsx',usecols="D")
stepper_angle = pd.read_excel('Rotary stage calibration.xlsx',usecols="E")
t = pd.read_excel('Rotary stage calibration.xlsx',usecols="F")
d_angle = np.gradient(encoder_angle,axis=0)


# Plot the encoder and stepper angles

fig, ax1 = plt.subplots()

color = 'tab:red'
ax1.set_xlabel('Time (s)')
ax1.set_ylabel('Encoder angle (deg)', color=color)
ax1.plot(t, encoder_angle, color=color, linewidth=1)
ax1.tick_params(axis='y', labelcolor=color)
plt.ylim(0, 370)

ax2 = ax1.twinx()  # instantiate a second axes that shares the same x-axis

color = 'tab:blue'
ax2.set_ylabel('Stepper angle (deg)', color=color)  # we already handled the x-label with ax1
ax2.plot(t, stepper_angle, color=color, linewidth=5, alpha=0.3)
ax2.tick_params(axis='y', labelcolor=color)

plt.title('Rotary stage performance without load')
fig.tight_layout()  # otherwise the right y-label is slightly clipped
plt.ylim(0, 370)
plt.xlim(40, 490)

plt.show()

def avg_deg_at_360(position):
    s = np.array(position)
    positives = s > 359.5
    if positives.any():
        return s[positives].mean()
    else:
        return 0.

def avg_deg_at_0(position):
    s = np.array(position)
    positives = s < 0.5
    if positives.any():
        return s[positives].mean()
    else:
        return 0.

def std_deg_at_360(position):
    s = np.array(position)
    positives = s > 359.5
    if positives.any():
        return s[positives].std()
    else:
        return 0.

def std_deg_at_0(position):
    s = np.array(position)
    positives = s < 0.5
    if positives.any():
        return s[positives].std()
    else:
        return 0.

av_at_360 = avg_deg_at_360(encoder_angle[10000:len(encoder_angle)])
print(av_at_360)

std_at_360 = std_deg_at_360(encoder_angle[10000:len(encoder_angle)])
print(std_at_360)

av_at_0 = avg_deg_at_0(encoder_angle[10000:len(encoder_angle)])
print(av_at_0)

std_at_0 = std_deg_at_0(encoder_angle[10000:len(encoder_angle)])
print(std_at_0)

# Plot the substraction between the stepper and encoder signals

encoder_angle_np = np.array(encoder_angle)
stepper_angle_np = np.array(stepper_angle)
substraction = stepper_angle_np-encoder_angle_np

plt.plot(t,substraction)
plt.ylabel('angle(deg)')
plt.xlabel('t(s)')
plt.ylim(-0.4, 0.4)
plt.xlim(40, 490)
plt.show()

