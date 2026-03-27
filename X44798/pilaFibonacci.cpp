#include<iostream>
#include <stack>
using namespace std;

//Pre: true.
//Post: retorna true si P conté una seqüència Fibonacci
bool pilaFibonacci(stack<int> P){
	bool resultat = false;
	int primer, segon, n;
	
	if (P.size() == 2){ //Cas base
		n = P.top();
		P.pop();
		if (n == 1 and P.top() == 1) resultat = true;
	}
	
	else{
		primer = P.top();
		P.pop();
		segon = P.top();
		P.pop();
		if ((primer - segon) == P.top()) resultat = true; 
		P.push(segon);
		if(resultat == true) resultat = pilaFibonacci(P);
		//HI: P conte la sequencia fibonacci
		//FF: El size de P
    }
	return resultat;
}
