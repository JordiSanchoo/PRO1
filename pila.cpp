#include<iostream>
#include<stack>
using namespace std;

stack<int> concatenar_pila(stack<int> p1, stack<int> p2){
stack<int> p3;

	if (empty(p1) and empty(pilaux) return 0;
	else{
		if (empty(p1)) return 0;
		else{
			x = p1.top();
			pilaux.push(x);
			p1.pop();
		}
		if (empty(pilaux)) return 0;
		else{
			y = pilaux.top();
			p2.push(y);
			pilaux.pop();
		}
	}
	concatenar_pila(p1,p2);

return p;
}


int main(){

stack<int> p;
int a, b;
	
	while(cin>>a){
		p1.push(p);
	}
	while(cin>>b){
		p2.push(b);
	}
	concatenar_pila(p1, p2);
	
return 0;
}
