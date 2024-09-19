#include <iostream>
using namespace std; 

int computeCollatz();
int term = 0;
int numTerm = 0;
int maxTerm = 0;
int main(){

computeCollatz();

return 0;
}



int computeCollatz(){
for(int i = 1 ; i=1000 ; i++) {
	term = i;
	while(i != 1000){
		if(i % 2 == 0){
			i/=2;
			numTerm++;
		}else{
			i = (3*i) + 1;
			numTerm++;
		}
	}
	if(numTerm > maxTerm){
		maxTerm = numTerm;
		cout<<" "<<i<<'\n';
	}	
}
}
