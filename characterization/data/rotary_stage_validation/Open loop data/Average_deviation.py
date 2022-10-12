import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('seaborn-white')

# Import from excel

mean = pd.read_excel('Accuracy and repeatability.xlsx',sheet_name='Sheet4')
mean_abs = pd.read_excel('Accuracy and repeatability.xlsx',sheet_name='Sheet6')
#std = pd.read_excel('Accuracy and repeatability.xlsx',sheet_name='Sheet5')
encoder= pd.read_excel('20400.xlsx',usecols="A")
stepper= pd.read_excel('20400.xlsx',usecols="B")
t = pd.read_excel('20400.xlsx',usecols="D")/1000

w = np.array([20, 40, 60, 80, 100])
a = np.array([200, 400, 600, 800, 1000, 1200])
W, A = np.meshgrid(w, a)

#Plot Average position deviation

plt.xlabel('Angular velocity (deg/s)')
plt.ylabel('Angular acceleration (deg/s^2)')
plt.contourf(W, A, mean, 100, cmap='RdGy')
plt.colorbar();
plt.title('Average position deviation')
plt.show()

#Plot Average absolute position deviation

plt.xlabel('Angular velocity (deg/s)')
plt.ylabel('Angular acceleration (deg/s^2)')
plt.contourf(W, A, mean_abs, 100, cmap='winter')
plt.colorbar();
plt.title('Average absolute position deviation')
plt.show()

# Plot signals

plt.xlabel('Time (s)')
plt.ylabel('Angle (deg)')
plt.plot(t, encoder)
plt.title('Accuracy and repeatability sequence')
plt.show()
