#include<iostream>
using namespace std;

int suma_digits(int x){

int suma = 0;

	if (x < 10) suma = x;
	else {
		suma = x%10 + suma_digits(x/10);
	}
	
return suma;
}


int main(){

int x;
cin>>x;

cout<<suma_digits(x)<<endl;

}
