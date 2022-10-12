import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('seaborn-white')

# Import from excel

mim = pd.read_excel('MIM.xlsx',usecols="A")
mim_steps = pd.read_excel('MIM.xlsx',usecols="B")
t = pd.read_excel('MIM.xlsx',usecols="D")/1000

#Plot Minimum Incremental Motion

plt.xlabel('Time (s)')
plt.ylabel('Angle (deg)')
plt.plot(t, mim, label="Encoder signal")
plt.plot(t, mim_steps, label="Stepper signal")
plt.title('Minimum Incremental Motion (MIM)')
plt.legend(loc='upper right', frameon=False)
plt.show()




