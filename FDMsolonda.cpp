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
        xi = xi + ((xf-xi)/999)*i;
   }    
}

void der(int i){
    /*
        Esta funcion asigna el valor aproximado de la derivada en 
    */
   if (i == 0){
    F0[0] = 2.0*f0[1] - 1.5*f0[0] - 0.5*f0[2];
   } else if (i == 999){ 
    F0[999] = 0.5*f0[997] - 2.0*f0[998] + 1.5*f0[999];
   } else{
        int i = 1;
        while(i < 999){
            F0[i] = (f0[i + 1] - f0[i - 1])/2;
            i = i + 1;
        }
    }
}


int main(){
    init(std::cos, 0.0, 2*M_PI_4);
    int i = 0;
    while (i < 1000){
        der(i);
        i = i + 1;
    }
    std::cout << f0[0] << std::endl;
    std::cout << f0[999] << std::endl;
    std::cout << F0[0] << std::endl;
    std::cout << F0[999] << std::endl;
    return 0;
}

