#include <iostream>
using namespace std;

int main() {

int i;
cin >> i;

if (i>100)
{
	cout<< "That number " << i << " had more than 2 digits." << '\n';
}else if(i<0){
	cout<<"That number " << i << " is negative." << '\n';
}

}
