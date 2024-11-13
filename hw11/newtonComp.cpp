/*
NAME: Christian Aruba
EID: cma3939
TACC: slopan_karn93
*/
#include<iostream>
#include<complex>
#include<functional>

using std::cout;
using std::complex;
using namespace std::complex_literals;

//make prototypes for your template functions.
template <typename T>
void newton_root(std::function<T(T)> f,std::function<T(T)> deriv, T guess);

int main(){
  //complex test values
  complex<double> z = 0.5+0.5i;
  complex<float> g = 0.5f+0.5fi;

  //calling the templetized newton function for different types with lambdas as the parameters
  //watch your static casting for complex inputs!
  cout<<"Newton (complex double): ";
  newton_root<complex<double>>([] (complex<double> x) ->  complex<double>{return x*x-static_cast<complex<double>>(2);},[] (complex<double> x) -> complex<double>{return static_cast<complex<double>>(2)*x;},z);

  cout<<"Newton (double): ";
  newton_root<double>([] (double x) -> double{return x*x-2.0;}, [] (double x) -> double{return 2.0*x;},10000.0);

  cout<<"Newton (complex float): ";
  newton_root<complex<float>>([] (complex<float> x) -> complex<float>{return x*x-static_cast<complex<float>>(2);}, [] (complex<float> x) -> complex<float>{return static_cast<complex<float>>(2.0)*x;},g);

  cout<<"Newton (float): ";
  newton_root<float>([] (float x) -> float{return x*x-2.0;}, [] (float x) -> float{return 2.0*x;},10000.f);
  
  return 0;
}


//also pass in the inital guess as a parameter
template<typename T>
void newton_root(std::function<T(T)>f,std::function<T(T)> deriv, T guess){
  T currentx = guess;
  T fx = f(currentx);
  //make the limit greater than 1.e-7 so that floats can find the root
  while(std::abs(fx)>=1.e-6){
    //update current x and its y-value
    currentx -= fx/deriv(currentx);
    fx = f(currentx);
  }
  std::cout<<"Function is "<<fx<<" at x = "<<currentx<<".\n";
};
