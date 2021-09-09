import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches


'''
    Esta parte abre los archivos que contienen la data para cada time step,
    los unicos archivos que siempre estaran seran x y f0, para los demas hay que generar 
    un loop para abrirlos o hacerlo manual, planear eso una vez se termine con los calculos
'''
x = open("x.dat", "r") 
f0 = open("f0.dat", "r")
f1 = open("f1.dat", "r")
#f2 = open("f2.dat", "r")

'''
    Esta parte convierte la data encontrada en los archivos temporales en numpy arrays los cuales
    pueden ser tomados como argumentos de funciones de matplotlib
'''
x = np.loadtxt(x)
f0 = np.loadtxt(f0)
f1 = np.loadtxt(f1)
#f2 = np.loadtxt(f2)
f = [f1] #este array toma la data que sera graficada para poder hacer loops sobre ella
'''
    Esta parte solo usa las funciones plot y show de matplotlib para graficar la data obtenida,
    notese que debe agregarse un plot por cada solucion fi con una leyenda que corresponda al 
    time-step adecuado
'''
plt.figure()
red_patch = mpatches.Patch(color='red', label='T = 0')
plt.legend(handles=[red_patch])
plt.xlabel('x')
plt.ylabel('f(x, 0)')
plt.plot(x, f0)
plt.savefig("f0.png")
'''
    Este loop creara un plot en cada uno de los archivos de data y los imprimira como el multiplo de t correspondiente
    siendo el multiplo de t el time-step graficado
'''
i = 1
while i < 2: #Este 2 se cambia por el numer de time-steps despues del 0 que se quieran graficar
    plt.figure()
    red_patch = mpatches.Patch(color='red', label='T = {}t'.format(i))
    plt.legend(handles=[red_patch])
    plt.xlabel('x')
    plt.ylabel('f(x, {}t)'.format(i))
    plt.plot(x, f[i - 1])
    plt.savefig("f{}.png".format(i))
    i = i + 1

