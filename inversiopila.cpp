#include<iostream>
#include<stack>
using namespace std;

void invertir_pila(stack<int> p){

p.pop();
	while (p.top() != -1){
		cout<<p.top()<<" ";
		p.pop();
	}
	cout<<endl;
}


int main(){

stack<int> pila;
pila.push(0);
pila.push(1);
pila.push(2);
pila.push(3);
pila.push(4);
pila.push(5);
pila.push(-1);
invertir_pila(pila);

}
