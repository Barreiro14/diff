#include <iostream>
#include <vector>
#include <cmath>

//std::vector<long double> f0; 
//std::vector<long double> F0;
long double f0[1000];
long double F0[1000];

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
        xi = xi + ((xf-xi)/1000)*i;
   }    
}

void der(){
    /*
        Esta funcion asigna el valor aproximado de la derivada en 
    */
    F0[0] = 2.0*f0[1] - 1.5*f0[0] - 0.5*f0[2];
    
    F0[sizeof(f0) - 1] = 0.5*f0[sizeof(f0) - 3] - 2.0*f0[sizeof(f0) - 2] + 1.5*f0[sizeof(f0) - 1];
    int i = 0;
    while(i < sizeof(f0) - 1){
        F0[i] = (f0[i + 1] - f0[i - 1])/2;
        i = i + 1;
    }
}


int main(){
    return 0;
}

