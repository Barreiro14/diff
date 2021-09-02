#include <iostream>
#include <vector>
#include <cmath>

std::vector<long double> f0; 
std::vector<long double> F0;

void init(long double (*f)(long double), long double xi, long double xf){
    /*
        Esta funcion toma como argumento la funcion de las condiciones iniciales
        f(x, 0) y asigna los valores desde xi hasta xf con incrementos y asigna a 
        los elementos f0[i] el valor de la red; f0[0] = xi && f0[len(f0)] = xf
    */    
   int i = 0;
   while (xi <= xf){
       f0[i] = (*f)(xi);
       i = i + 1;
       xi = xi + ((xf-xi)/1000)*i;
   }    

}

void der(int i){
    /*
        Esta funcion asigna el valor aproximado de la derivada en 
    */
    if (i == 0){
        //definir para los bordes
    }else if (i == f0.size()){
        //definir para los bordes
    }else{
        F0[i] = (f0[i + 1] - f0[i - 1])/2;
    }
}


int main(){
    //std::cout << f0[1] << std::endl;
    return 0;
}

