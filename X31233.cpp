#include<iostream>
#include<stack>
using namespace std;

void invertir_pila(stack<int> &a){

    stack<int> pilaux;

    while (!a.empty()) {
        pilaux.push(a.top());
        a.pop();
    }

    while (!pilaux.empty()) {
        a.push(pilaux.top());
        pilaux.pop();
    }
}	

void concatena_piles(stack<int> &p, stack<int> &q, stack<int> &concatenatp){
	
	invertir_pila(p);

    concatenatp.push(p.top());
    p.pop();

    if (p.empty()) {
        invertir_pila(q);

        while (!q.empty()) {
            concatenatp.push(q.top());
            q.pop();
        }
    } else {
        concatena_piles(p, q, concatenatp);
    }

}


int main(){

	int primera, segunda, nums;
	stack<int> a;
	stack<int> b;
	stack<int> x;
	cin>>primera;
	
	for(int i = 0; i < primera; i++){
		cin>> nums;
		a.push(nums);
	}
	cin>>segunda;
	for(int i = 0; i < segunda; i++){
		cin>> nums;
		b.push(nums);
	}
	
	
	concatena_piles(a, b, x);
	
	cout << "Pila concatenada:" << endl;
    while (!x.empty()) {
        cout << x.top() << " ";
        x.pop();
    }

    return 0;

}
