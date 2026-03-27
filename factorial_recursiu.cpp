#include<iostream>
using namespace std;

int factorial(int n){

if (n == 0) return 1;
if (n == 1) return n;	
else {
	n = n * factorial(n-1);
	}

return n;
}

int main(){

int a;
cin>>a;
cout<<factorial(a)<<endl;

return 0;
}
