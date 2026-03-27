#include<iostream>
#include<stack>
using namespace std;

void escriu_de_base_a_cim(stack<int>& pila){
stack<int> p2;
	while (not pila.empty()){
			
		int p = pila.top();
		pila.pop();
		p2.push(p);	
	}
	while(not p2.empty()){
		cout<<p2.top()<<" ";
		p2.pop();
	}
cout<<endl;
}

void escriu_de_cim_a_base(stack<int>& pila){

	while (not pila.empty()){
		
		int p = pila.top();
		cout<<p<<" ";
		pila.pop();
	}
cout<<endl;
}


int main(){

stack<int> p1;
p1.push(2);
p1.push(3);
p1.push(4);
p1.push(1);
p1.push(8);
p1.push(6);

escriu_de_base_a_cim(p1);
escriu_de_cim_a_base(p1);

}
