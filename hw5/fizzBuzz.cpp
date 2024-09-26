#include <iostream>
using namespace std; 

int main() {
	int x;
	
	cin>>x;
	
	if(x%3==0 && x%5==0){	
	cout<<"Fizzbuzz!"<<endl;
	}else if(x%3==0){
	cout<<"Fizz!"<<endl;
	}else if (x%5==0){
	cout<<"Buzz!"<<endl;
	}
	
}
