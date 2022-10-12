import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('seaborn-white')

# Import from excel

accuracy = pd.read_excel('Accuracy and repeatability.xlsx',sheet_name='Sheet2')
repeatability = pd.read_excel('Accuracy and repeatability.xlsx',sheet_name='Sheet3')

accuracy_np = accuracy.to_numpy()
repeatability_np = repeatability.to_numpy()

w = np.array([20, 40, 60, 80, 100])
a = np.array([200, 400, 600, 800, 1000, 1200])
W, A = np.meshgrid(w, a)

#Plot accuracy

plt.xlabel('Angular velocity (deg/s)')
plt.ylabel('Angular acceleration (deg/s^2)')
plt.contourf(W, A, accuracy, 100, cmap='RdGy')
plt.colorbar();
plt.title('Open loop accuracy')
plt.show()

#Plot repeteability

plt.xlabel('Angular velocity (deg/s)')
plt.ylabel('Angular acceleration (deg/s^2)')
plt.contourf(W, A, repeatability, 100, cmap='RdGy')
plt.colorbar();
plt.title('Open loop repeatability')
plt.show()



