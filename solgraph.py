import numpy as np
import matplotlib.pyplot as plt

'''
    Esta parte abre los archivos que contienen la data para cada time step,
    los unicos archivos que siempre estaran seran x y f0, para los demas hay que generar 
    un loop para abrirlos o hacerlo manual, planear eso una vez se termine con los calculos
'''
x = open("x.dat", "r") 
f0 = open("f0.dat", "r")
f1 = open("f1.dat", "r")

'''
    Esta parte convierte la data encontrada en los archivos temporales en numpy arrays los cuales
    pueden ser tomados como argumentos de funciones de matplotlib
'''
x = np.loadtxt(x)
f0 = np.loadtxt(f0)
f1 = np.loadtxt(f1)
'''
    Esta parte solo usa las funciones plot y show de matplotlib para graficar la data obtenida,
    notese que debe agregarse un plot por cada solucion fi con una leyenda que corresponda al 
    time-step adecuado
'''
plt.plot(x, f0, x, f1)
plt.show()