#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

long double f0[1000];
long double x[1000];

void init(long double (*f)(long double), long double xi, long double xf){
    /*
        Esta funcion toma como argumento la funcion de las condiciones iniciales
        f(x, 0) y asigna los valores desde xi hasta xf con incrementos y asigna a 
        los elementos f0[i] el valor de la red; f0[0] = xi && f0[len(f0)] = xf
    */    
   int i = 0;
   while (i < 1000){
        f0[i] = (*f)(xi);
        i = i + 1;
        xi = xi + ((xf-xi)/999)*i;
   }    
}

void base(long double xi, long double xf){
    /*
    Esta funcion genera todos los puntos de x desde xi hasta xf en intervalos iguales
    se usa para graficar
    */
    int i = 0;
    while (i < 1000){
        x[i] = xi;
        i = i + 1;
        xi = xi + ((xf-xi)/999)*i;
    }
}

long double *der(long double arr[1000], long double darr[1000], double dx){
    /*
        Esta funcion asigna el valor aproximado de la derivada en xi en termino de los puntos de su alrededor.
        note: dx funciona mejor (por alguna razon) un numero "grande"
    */
    darr[0] = (2.0*arr[1] - 1.5*arr[0] - 0.5*arr[2])/dx;
    darr[999] = (0.5*arr[997] - 2.0*arr[998] + 1.5*arr[999])/dx;
    int i = 1;
    while(i < 999){
        darr[i] = (arr[i + 1] - arr[i - 1])/2*dx;
        i = i + 1;
    }
    return darr;
}
int main(){
    long double dt = 0.000001;
    long double F0[1000];
    long double G0[1000];
    init(std::cos, 0.0, 6*M_PI_4);
    base(0.0, 6*M_PI_4);
    der(der(f0, F0, 2), G0, 2);
    std::ofstream file;
    int i = 0;
    int j = 0;
    int k = 0;
    file.open ("x.dat");
    while (j < 1000){
        file << x[j] << std::endl;
        j = j + 1;

    }
    file.close();
    file.open ("f0.dat");
    while (i < 1000){
        file << f0[i] << std::endl;
        i = i + 1;

    }
    file.close();
    file.open("f1.dat");
    while(k < 1000){
        file << G0[k]*dt*dt/4 << std::endl;
        k = k + 1;
    }
    
    double dx = (f0[999]-f0[0])/1000;
    return 0;
}


