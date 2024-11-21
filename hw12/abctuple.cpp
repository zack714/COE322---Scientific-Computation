/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2024 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** actuple.cpp : abc formula
 ****
 ****************************************************************/
/*
Name: Christian Aruba
EID: cma3939
TACC: slopan_karn93
Date: 11/20/2024
*/
#include <iostream>
using std::cout;
#include <cmath>
#include <string>
using std::string;

#include <optional>
using std::optional;

#include <tuple>
using std::pair, std::make_pair, std::tuple, std::make_tuple;
#include <variant>
using std::variant, std::monostate;

using quadratic = tuple<double,double,double>;

double discriminant
    ( quadratic q ) {
  auto [a,b,c] = q;
  return b*b-4*a*c;
}

//takes a quadratic and returns a monostate for no roots, a double with 1 root, or a pair with the two roots
tuple<double,double> abc_roots(quadratic q){

  auto d = discriminant(q);
  //unpack the tuple to get a,b, and c
  auto [a,b,c] = q;
  //b plus the sqrt
  double xpos = (b+sqrt(d)/(2.0*a));
  //b minus the sqrt
  double xneg = (b-sqrt(d)/(2.0*a));
  //return as a tuple.
    return {xpos,xneg};
  
}

//returns strings stating how many roots there are
optional<string> how_many_roots(quadratic q){
  auto d = discriminant(q);
  if(d>0 || d==0){
    if(d>0){
      return "two\n";
    }else{
      return "one\n";
    }
  }
  return {};

}

//returns a monostate for no roots, a double for 1 root, or a tuple holding two roots
variant<std::monostate,double,tuple<double,double>> abc_cases(quadratic q){
  auto  d = discriminant(q);
  //if the discriminant is negative, there's no real roots.
  if(d<0){
    return std::variant<std::monostate,double,tuple<double,double>>{std::monostate{}};
  }else{

    //get the coefficients through structured binding
    auto [a,b,c] = q;

    //if the discriminant is zero, return 1 root, as a double.
    if(d==0){
      double x = (-1.0*b+sqrt(d))/2.0*a;
      return std::variant<std::monostate,double,tuple<double,double>>{x};
    }else{
      //otherwise, return the two doubles in a variant with the same signature as the return value--but initialize it with a tuple of the roots.
      double x1 = (-1.0*b+sqrt(d))/2.0*a;
      double x2 = (-1.0*b-sqrt(d))/2.0*a;
      return std::variant<std::monostate,double,tuple<double,double>>{make_tuple(x1,x2)};
    }
    
  }
}



int main() {

  /*
   * Initialization syntax is not unique
   */
  { 
    // spell it out
    auto sunk = tuple<double,double,double>{1.,0.,-2};
  }
  {
    // brace syntax
    auto sunk = quadratic{1.,0.,-2};
  }

  /*
   * Here is the actual program
   */
  // parenthesis syntax
  // polynomial: x^2 - 2
  auto sunk = quadratic(1.,0.,-2);
  auto [a,b,c] = sunk;
  cout << "coefficients: " << a << "," << b << ',' << c << '\n';

  auto d = discriminant( sunk );
  cout << "discriminant: "
       << d << '\n';

  auto num_solutions = how_many_roots(sunk);
  if ( not num_solutions.has_value() )
    cout << "none\n";
  else
    cout << num_solutions.value() << '\n';

  //testing whether a tuple will be returned
  auto roots = abc_roots( sunk );
  auto [xplus,xminus] = roots;
  cout << xplus << "," << xminus << '\n';

  //testing the variant now...
  //abc_cases is a superior version of the abc_roots function, as it can return a monotype, 1 double, or two doubles.
  //with these alternatives it can account for the 3 types of solutions of the quadratic equation.
  auto root_cases = abc_cases( sunk );
  switch (root_cases.index()) {
  case 0 : cout << "No roots\n"; break;
  case 1 : cout << "Single root: " << get<1>(root_cases); break;
  case 2 : {
    auto xs = get<2>(root_cases);
    auto [xp,xm] = xs;
    cout << "Roots: " << xp << "," << xm << '\n';
  } ; break;
  }

  return 0;
}
