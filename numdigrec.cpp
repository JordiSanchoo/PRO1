#include<iostream>
using namespace std;

int nombre_digits(int n){

int compt = 1;

	if (n<10) return compt;
	else {
		compt = nombre_digits(n/10);
		compt++;
	}
	return compt;
}

int main(){

int a;
cin>>a;
cout<<nombre_digits(a)<<endl;

}
