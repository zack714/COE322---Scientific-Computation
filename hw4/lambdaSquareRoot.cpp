#include <iostream>
#include <functional>
using namespace std; 

double newton_root(function< double(double) > f,
		   function< double(double) > deriv) {
	//find the square root of two
	//start somewhere
	double current_x = 10000000.;
	//while the function in the current value is too large keep looping
	double function_value = f(current_x);
	for (int iteration_count = 0; abs(function_value)>1.e-5; ++iteration_count){
	//update current x
	current_x -= f(current_x)/deriv(current_x);
	//calculate new function value
	function_value = f(current_x);
	if(abs(function_value)<1.e-5) {
	//cout << "Function is " << f(current_x) << " at " << current_x <<
	// " in iteration " << iteration_count << '\n';
	break;
	}
}
return current_x;
}

int main(){

	//define functions
auto f = [](double x) {return x*x-2;};
auto deriv = [](double x) { return 2*x; };

	//print results
	cout<< "Sqrt 2 " << newton_root(f,deriv) <<  " at " << '\n';
	return 0;
}


