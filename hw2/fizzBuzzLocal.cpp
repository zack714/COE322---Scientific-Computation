#include<iostream>
using namespace std;

int main(){
int x;

cout<<"Enter a positive number: "<<endl;

cin>>x;

if(x%5==0 && x%3==0 && x!=0){
	cout<<"Fizzbuzz!"<<endl;
}else if(x%3==0 && x!=0){
	cout<<"Fizz!"<<endl;
}else if(x%5==0 && x!=0){
	cout<<"Buzz!"<<endl;
}

}
