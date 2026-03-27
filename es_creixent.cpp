#include<iostream>
using namespace std;

bool es_creixent(int n){

	if (n<10) return true;
	else if ((n%10)<((n/10)%10)) return false;
	else return es_creixent(n/10);

}

int main(){

int a;
cin>>a;

if (es_creixent(a)) cout<<"true"<<endl;
else cout<<"false"<<endl;

}
