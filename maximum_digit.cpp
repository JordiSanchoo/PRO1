#include <iostream>
using namespace std;

// Pre: x >= 0
// Post: Retorna el màxim dígit de la representació decimal de x.

int maximumDigit(int x){

	int ultim = x%10;
		
	if (x == 0) return 0;
	else {
		if (ultim > maximumDigit(x/10)) return ultim;
		else return maximumDigit(x/10);
	}
}

int main(){

int x;
cin>>x;

cout<<maximumDigit(x)<<endl;
}
