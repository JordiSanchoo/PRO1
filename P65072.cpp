#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

bool es_palindrom(stack<int> a){
	
	bool trobat = true;
	stack<int> b;
	stack<int> aux(a);
	
	while(not a.empty()){
		int ultimo = a.top();
		b.push(ultimo);
		a.pop();
	}
	
	while(not b.empty()){
		if (b.top() != aux.top()){
			return trobat = false;
		}
		aux.pop(); b.pop();
	}
	
	return trobat;
	
}
int main(){

	string line;
	while(getline(cin,line)){
		stack<int> p;
		istringstream iss(line);
		int num;
		while(iss >> num){
		p.push(num);		
		}
		
	if (es_palindrom(p) or p.empty()) cout<<"Es un palindrom."<<endl;
	else cout<<"NO es un palindrom."<<endl;
	}

return 0;
}
