import numpy as np
import matplotlib.pyplot as plt

x = open("x.dat", "r") #data file from C++
f0 = open("f0.dat", "r")

x = np.loadtxt(x)
f0 = np.loadtxt(f0)

plt.plot(x, f0)
plt.show()