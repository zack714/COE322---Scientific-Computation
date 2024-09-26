#include <iostream>
#include <functional>
using namespace std;

/*
EID: cma3939
Name: Christian Aruba
Tacc: slopan_karn93
 */
//goal: write a version of the root finding function that only takes the
//objective function (f) and approximates the derivative by a finite difference.
//call h = 1e-6.
//create a lambda for the gradient and pass it to the function newton_root coded earlier.

/*approximation for the derivative of a function, f:

(f(x+h) - f(x))/h

 */

//Ex 4
double newton_root( function<double(double)> f, function <double(double)> deriv) {

  //Guess a x value
  double current_x = 10000000.0;

  //find the function with this guess:
  double function_val = f(current_x);

  //iterate
  for (int iteration_count = 0; ++iteration_count;) {

    //update current x
    current_x -= f(current_x) / deriv(current_x);

    //new function value
    function_val = f(current_x);

      //check if f(x) is close enough to 0

      if(std::abs(function_val) < 1e-5){
	//exit the iteration
	break; 
      }
    //return the x where you found 0
    return current_x;
  }
}

//Ex 5
double newton_root(function<double(double)> f){
  //constant for h, the value for the space near x
  const double h = 1e-6;

  //use lambda to calculate derivative and call previous newton function

  return newton_root(f, [f,h] (double x) {return f(x+h) - f(x) / h;});
}


int main(){

  //call Ex.5 newton root in this for loop:
  for(int n = 2; n<=8; ++n){
      cout<<"sqrt(" << n << ") = " << newton_root([n](double x){return x*x-n;}) << '\n';
    }
  
  return 0;
}
