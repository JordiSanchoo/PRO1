#include<iostream>
#include <stack>
using namespace std;


bool comprova (stack<int> p1, stack<int> p2){
	
	if (p2.empty()) return true;
	if (p1.top() == p2.top()){
		p1.pop();
		p2.pop();
		return comprova(p1,p2);
	}
	else return false;
}


bool subPila(stack<int> p1, stack<int> p2) {

    if (p1.size() < p2.size()){
    	return false;
    }
    else{
    	 if (comprova(p1,p2)) return true;	
    	 else p1.pop();
    }
return subPila(p1,p2);
}



