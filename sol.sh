#    En este script de Bash compilamos el programa de C++
#    el cual es el que hace todos los calculos, luego ejecutamos
#    el archivo binario el cual crea unos archivos temporales que
#    usamos para enviar data calculada desde C++ hasta Python,
#    ejecutamos el script de Python que graficara los valores calculados
#    y por ultimo borra los archivos temporales y el ejecutable.

clang++ FDMsolonda.cpp -o solnum
./solnum #name of the c++ program
python3 solgraph.py #name of the python program
rm x.dat f0.dat f1.dat solnum #f1.dat #name of the mean time files from C++ -> Python
