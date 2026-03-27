#include<iostream>
using namespace std;

int main(){
	
	cout<< "Seqüència d'enters acabada en 0: "<<endl;
	int x, suma = 0;
	
	while (x != 0){
		cin>>x;
		suma += x;
	}
	cout<<"Suma = "<<suma<<endl;

}
