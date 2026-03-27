#include "Punt.hpp"
#include "stackIOpunt.hpp"
#include "queueIOpunt.hpp"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Pre: s està buida i q es una llista de punts
//Post: Pasa els punts de la cua a la pila amb el pateix ordre
void convert (stack<Punt> &s, queue<Punt> &q){
	
	if (not q.empty()){
		Punt n = q.front();
		q.pop();
		convert (s,q);
		//HI: Pasa els punts de la cua a la pila amb el mateix ordre
		//FF: Size de s i de q
		s.push(n);
	}
}

int main(){
	
	queue<Punt> q;
	//Inv: Mentre rebi cues, les pasa a la pila
	while (cin>>q){
		stack<Punt> s;
		cout<<q;
		convert(s,q);
		cout<<s;
	}
}
