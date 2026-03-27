#include <stack>
#include <iostream>
using namespace std;

void concatena_piles(stack<int> &p, stack<int> &q, stack<int> &concatp){
	int arriba;
		
	if (p.empty()){
		if (not q.empty()) concatp = q;
		
	}
	else{
		if (q.empty()) concatp = p;
		else{
			arriba = p.top();
			p.pop();
			concatena_piles(p, q, concatp);
			concatp.push(arriba);
		}
		
	}
	
}
/* Pre: p = P i q = Q i concatp es buida */
/* Post: concatp conte a dalt els elements de P en 
   el mateix ordre, i a sota els elements de Q en el mateix
   ordre */
