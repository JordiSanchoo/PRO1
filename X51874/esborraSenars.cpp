#include<iostream>
#include<stack>
using namespace std;


void esborraSenars (stack<int> &P){
	stack<int> aux;
	
	while (!P.empty()){
		
		if (P.top()%2 != 0){
			P.pop();
		}
		else {
			aux.push(P.top());
			P.pop();
		}
	}
	while (!aux.empty()){
		P.push(aux.top());
		aux.pop();
	}
}
