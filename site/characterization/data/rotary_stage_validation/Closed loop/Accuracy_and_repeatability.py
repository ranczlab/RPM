import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('seaborn-white')

# Import from excel
#velocity = pd.read_excel('Accuracy.xlsx',usecols="A")
#acceleration = pd.read_excel('Accuracy.xlsx',usecols="B")
#accuracy = pd.read_excel('Accuracy.xlsx',usecols="C")
#repeatability = pd.read_excel('Accuracy.xlsx',usecols="D")

#velocitynp = np.array(velocity)
#accelerationnp = np.array(acceleration)
#accuracynp = np.array(accuracy)
#repeatabilitynp = np.array(repeatability)

w = np.array([20, 40, 60, 80, 100])
a = np.array([200, 400, 600, 800, 1000, 1200])
W, A = np.meshgrid(w, a)

mean = np.array([[0.149, 1.262, 5.972, 11.572, 21.099], [0.399, 0.231, 2.369, 4.742, 8.965], [0.336, 0.219, 1.158, 0.131, 0.094], [0.343, 0.225, 0.154, 1.827, 4.434], [0.322, 0.536, 0.484, 1.412, 3.291], [0.125, 0.109, 0.403, 0.165, 0.123]])
std = np.array([[0.011, 0.804, 2.707, 3.559, 4.883], [0.019, 0.073, 0.741, 2.844, 4.326], [0.021, 0.005, 0.543, 0.065, 0.047], [0.018, 0.012, 0.070, 0.949, 0.993], [0.015, 0.106, 0.089, 0.371, 0.720], [0.078, 0.036, 0.064, 0.037, 0.065]])

#Plot accuracy

plt.xlabel('Angular velocity (deg/s)')
plt.ylabel('Angular acceleration (deg/s^2)')
plt.contourf(W, A, mean, 100, cmap='RdGy')
#plt.clim(0, 1)
plt.colorbar();
plt.title('Average of absolute position deviation')

plt.show()

#Plot repeatability

plt.xlabel('Angular velocity (deg/s)')
plt.ylabel('Angular acceleration (deg/s^2)')
stdcntr = plt.contourf(W, A, std, 100, cmap='RdGy')

#plt.clim(0, 1)
plt.colorbar()
plt.title('Standard deviation of absolute position deviation')

plt.show()


