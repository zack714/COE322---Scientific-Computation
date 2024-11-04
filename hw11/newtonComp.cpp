/*
NAME: Christian Aruba
EID: cma3939
TACC: slopan_karn93
*/
#include<iostream>
#include<complex>
using std::cout;
using std::complex;
using namespace std::complex_literals;

//>>>>>>Function Overloading<<<<<<
//make prototypes for your template functions.
template <typename T>
complex<T> f(complex<T> x);

template <typename T>
complex<T> fprime(complex<T> x);

//prototypes for non-complex numbers, so they can also work
double f(double x);

double fprime(double x);

int main(){
  //start at 0.5+0.5i.
  complex<double> z{.5,.5};
  //double n = 3.0;
  while ( true ) {
    //calculate the output of your complex number
    auto fz = f(z);
    //print out the complex number and its output
    cout << "f( " << z << " ) = " << fz << '\n';
    //if the absolute value of the output is small close enough to 0, break.
    if (std::abs(fz)<1.e-10 ) break;
    //otherwise, subtract the quotient between the output and the derivative from z.
    z-= fz/fprime(z);
  }
  
  return 0;
}

//template function definitions
template <typename T>
//takes a complex version x-value entered and returns a complex double y-value
complex<T> f(complex<T> x){
    return x*x-static_cast<complex<double>>(2);
}

//takes a complex version of an x-value and the derivate (as a complex double) 
template <typename T>
complex<T> fprime(complex<T> x){
    return static_cast<complex<double>>(2)*x;
}
//for non-complex numbers
double f(double x){
  return x*x-2;
}

double fprime(double x){
  return 2*x;
}
