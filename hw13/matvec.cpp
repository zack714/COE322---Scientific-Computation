/*
NAME: Christian Aruba
TACC: slopan_karn93
DATE: 12/4/2024
EID: cma3939
*/

#include <iostream>
using std::cout,std::cin;
#include <chrono>
#include <string>
using std::string;

#include <ranges>
using std::ranges::views::iota,
  std::ranges::views::filter,
  std::ranges::views::transform;

#include <numeric>
using std::accumulate;

#include <Eigen/Dense>
using namespace Eigen;
// ::Matrix, Eigen::Vector;
 
/*
 * Jacobi Iterative method with seq
 */
template< typename MatrixType,typename VectorType >
void JacobiSolve1( MatrixType A,VectorType sol,VectorType rhs ) {

  //holds the true solution we'll compare our guess to
  auto tmp{sol};
  
  //cout<<"inital solution: "<<tmp<<'\n';

  // set initial guess to identically one
  int siz = A.rows();
  for ( auto& v : sol ){
    v = 1.;
  }
  
  //cout<<"tmp(1): "<<tmp(2)<<" guess(1): "<<sol(2)<<'\n';
  int it = 1;
  
  // while the difference between elements in the guess and the true solution is greater than a certain amount...
  while (tmp(2)-abs(sol(2))>0.000000001) {
   
    
    //// one step of Jacobi
    for(int i=0;i<siz;i++){

    //REMEMBER: you're working row by row here
      
    //get the ith element on the ith row of the rhs   
    auto rhVal = rhs(i);
    
    //subtract the sum of the products of a element on the i'th row in A in the jth column with the j'th element in tmp (excluding elements on the diagonal) from the ith element of the rhs
    auto nonDiagSum = 0.0;
    
    //loop through j and sum all elements that aren't on the diagonal
    for(int j = 0;j<siz;j++){
      if(j!=i){
	nonDiagSum+=A(i,j)*sol(j);
      }
    }
    //calculate the difference between value in rhs and nonDiagSum
    auto difference  = rhVal-nonDiagSum;
    
    //divide the quantity from the comment above by the element on the diagonal and assign it the the new solution
    auto diagVal = A(i,i);

    //finally, calculate the value in ith row of the solution of your current iteration
    sol(i) = difference/diagVal;
    
    }
    //display iteration and current solution
    cout << "it: " << it << '\n' << sol << '\n';
    
    it++;

    //  cout<<"temp: "<<tmp<<'\n';
    
    //////end of jacobi step
  
  }
}

/*
 * Jacobi Iterative method with ranges
 */
template< typename MatrixType,typename VectorType >
void JacobiSolve2( MatrixType A,VectorType sol,VectorType rhs ) {

  auto tmp{sol};
  // set initial guess to identically one
  int siz = A.rows();
  for ( auto& v : sol ){
    v = 1.;
  }
  // for a number of iteration

  int it = 0;

  while(tmp(2)-abs(sol(2))>0.0000001){

      for(int i = 0; i<siz; i++){
	double sum = 0.0;

	//getting elements before the diagonal
	if(i>0){
	  auto rowBeforeDiag = A.block(i,0,1,i); //moving across the ith row, for i columns
	  auto colBeforeDiag = sol.block(0,0,i,1);//moving cross i rows on the 1st column
	  sum+=(rowBeforeDiag*colBeforeDiag)(0,0); //(0,0) so that sum is scalar, not a matrix
	}

	//getting the elements after the diagonal
	if(i<siz-1){
	  auto rowAfterDiag = A.block(i,i+1,1,siz-i-1); //row i, columns after i+1
	  auto colAfterDiag = sol.block(i+1,0,siz-i-1,1); //rows after i+1, single column
	  sum+=(rowAfterDiag*colAfterDiag)(0,0); //similar to above
	}

	sol(i) = (rhs(i)-sum)/A(i,i);
	it++;
      }
    cout << "it: " << it << '\n' << sol << '\n';
    }

}

int main()
{

  const int siz=5;
  Matrix<double,siz,siz> A;
  Vector<double,siz> sol,rhs,tmp;
  Vector<double,siz> rhsManual;
  cout << "Matrix size: " << A.rows() << "," << A.cols() << " (" << A.size() << ")\n";

  for ( auto& v : rhs )
    v = 1.;
  cout << rhs << '\n';

  for ( auto row : iota(0,siz) ) {
    sol(row) = static_cast<double>( row );
    A(row,row) = siz;
    for ( auto col : iota(0,siz) ) {
      if (row==col) continue;
      A(row,col) = -1;
    }
  }
  cout << "sol:\n" << sol << '\n';
  rhs = A*sol;

  //manually computing matrix-vector product
  for(int i=0;i<A.rows();i++){
    //for the element in the i'th row of A...

    //create a variable called dotsum and initalize it as 0.
    double dotSum = 0.0;
    for(int j=0;j<sol.size();j++){
      //...in the j'th column, multiply it by the j'th element of the vector.
      double tmpDoub = A(i,j)*sol(j);
      //then add the product to dotSum
      dotSum+=tmpDoub;
    }
    //assign dotsum to the i'th element of the product vector.
    rhsManual(i)=dotSum;
  }
  
  cout << "rhs:\n" << rhs << '\n';
  cout<<"rhsManual:\n"<<rhsManual<<'\n';
  cout << "================ Solve 1\n";
  JacobiSolve1( A,sol,rhs );
  cout << "================ Solve 2\n";
  JacobiSolve2( A,sol,rhs );

  Matrix<float,Dynamic,Dynamic> Af(20,20);
  // or: MatrixXf Af(20,20);

  return 0;
}
