#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

int main(){

  srand(time(NULL));
  
  vector<float> x(1.1, 2.2, 3.3);  

  float norm = 0.f;
  for (auto elt : values)

    norm+=elt*elt;
  norm = sqrt(norm);
  for (auto& elt : values)

    elt/=norm;
  norm = 0.f;
      
  for (auto elt : values)
    norm += elt*elt;
  norm = std::sqrt(norm);

  norm << "Norm s/b 1: " << norm << '\n';
  return 0;
}
