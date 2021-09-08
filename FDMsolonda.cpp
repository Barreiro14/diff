#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

//std::vector<long double> f0; 
//std::vector<long double> F0;
long double f0[1000];
long double x[1000];
//long double F0[1000];
//long double G0[1000];

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
    int i = 0;
    while (i < 1000){
        x[i] = xi;
        i = i + 1;
        xi = xi + ((xf-xi)/999)*i;
    }
}

long double *der(long double arr[1000], long double F0[1000], double dx){
    /*
        Esta funcion asigna el valor aproximado de la derivada en 
    */
    F0[0] = (2.0*arr[1] - 1.5*arr[0] - 0.5*arr[2])/dx;
    F0[999] = (0.5*f0[997] - 2.0*f0[998] + 1.5*f0[999])/dx;
    int i = 1;
    while(i < 999){
        F0[i] = (f0[i + 1] - f0[i - 1])/2*dx;
        i = i + 1;
    }
    return F0;
}
/*
void Sder(int i){
   if (i == 0){
    G0[0] = 2.0*F0[1] - 1.5*F0[0] - 0.5*F0[2];
   } else if (i == 999){ 
    G0[999] = 0.5*F0[997] - 2.0*F0[998] + 1.5*F0[999];
   } else{
        int i = 1;
        while(i < 999){
            G0[i] = (F0[i + 1] - F0[i - 1])/2;
            i = i + 1;
        }
    }
}
*/
int main(){
    long double F0[1000];
    init(std::cos, 0.0, 2*M_PI_4);
    base(0.0, 2*M_PI_4);
    std::ofstream file;
    int i = 0;
    int j = 0;
    file.open ("f0.dat");
    while (i < 1000){
        file << f0[i] << std::endl;
        i = i + 1;

    }
    file.close();
    file.open ("x.dat");
    while (j < 1000){
        file << x[j] << std::endl;
        j = j + 1;

    }
    file.close();
    double dx = (f0[999]-f0[0])/1000;
    /*
    int i = 0;
    int j = 0;
    while (i < 1000){
        der(i);
        i = i + 1;
    }
    while (j < 1000){
        der(j);
        j = j + 1;
    }
    */
   
    std::cout <<  f0[0] << std::endl;
    //std::cout << f0[999] << std::endl;
    //std::cout << der(der(f0, (f0[999]-f0[0])/1000), (f0[999]-f0[0])/1000)[0] << std::endl;
    //std::cout << der(f0, 0.0001)[999] << std::endl;
    return 0;
}

