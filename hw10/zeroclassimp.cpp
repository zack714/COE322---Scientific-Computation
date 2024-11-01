/*
Name: Christian Aruba
EID: cma3939
TACC: slopan_karn93
*/
#include "zeroclasslib.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using std::cout;
using std::cin;
using std::vector;
using std::pow;

//constructor for polynomial object
polynomial::polynomial(vector<double> c): coefficients(c){
  //if the highest power has a coefficient of 0, it's improperly defined. Throw 1.
  if(c.at(0)==0){
    throw 1;
  }
};

//check if your polynomial is odd
bool polynomial::is_odd() const {
  //odd polynomials have an even number of elements.
  if(coefficients.size()%2==0){   
    return true;
  }
  else{
    return false;
    }
};

//get the y-value of your polynomial at a certain point. 
double polynomial::evaluate_at(double x) const{
  //holds the value at point x
  float finalv = 0.f;

  //the degree of a polynomial is always 1 smaller than its size
  int degree = coefficients.size()-1;
  
  //loop through the coefficients and add your value to the power of the degree minus that element
  for(int i = 0; i<coefficients.size(); i++){
    finalv+=(coefficients.at(i)*pow(x,degree-i)); 
  }
      return finalv;

};

void find_initial_bounds(const polynomial& f,double& left,double& right){

  //x values of the boundaries
  double yleft = f.evaluate_at(left);
  double yright = f.evaluate_at(right);

  //is the polynomial not odd?
  if(!f.is_odd()){
    throw 1;
  }

  //make sure we aren't making useless computations if our function is fine
  if(left<right && yleft*yright<0){
    return;
  }
  //if both functions are positive, move the left bound to the left
  while(yleft>0 && yright>0){
    left-=0.1;
    //reevaluate the left y-value
    yleft = f.evaluate_at(left);
  }

  //if both funtions are negative, moev the right bound to the right
  while(yleft<0 && yright<0){
    right+=0.1;
    //reevaluate right y-value
    yright = f.evaluate_at(right);
  }

  //if the left bound is greater than the right bound, swap them.
  if(left>right){
    std::swap(left, right);
  }
  
}


void move_bounds_closer(const polynomial& f, double& left, double& right, bool trace){
  //before you try computing stuff, always preform a sanity check:
  if(left>=right){
    throw 1;
  }
  
  //a midpoint will form between the bounds
  double midX = (left+right)/2.f;

  //midpoint's y value
  double midY = f.evaluate_at(midX);

  //if the midpoint is positive, the shift the right bound to the midpoint. Vice-versa for a negative midpoint
  if(midY>0){
    right = midX;
  }else{
    left = midX;
  }
  
}

double find_zero(const polynomial& f, double prec, bool trace){
  //make sure the function is odd
  if(!(f.is_odd())){
    throw 1;
  }

  //guess bounds
  double left = -100.f;
  double right = 100.f;

  //set bounds
  find_initial_bounds(f,left,right);

  //start your inital guess at the midpoint:
  double midX = (left+right)/2.f;

  //while the y-value of your midpoint is above prec, move it closer
  while(std::abs(f.evaluate_at(midX))>prec){
    //move bounds closer
    move_bounds_closer(f,left,right);
    //update midpoint
    midX = (left+right)/2.f;
  }
  //return your zero.
  return midX;
}

