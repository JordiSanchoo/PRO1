#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "stack.hpp"

void imprimeix(Stack<int> s)
{
	// Aquest procediment imprimeix una pila per pantalla
	Stack<int> saux;
    while (!s.empty()) {
        saux.push(s.top());
        s.pop();
    }
    bool writespace = false;
    while (!saux.empty()) {
        if (writespace) cout << " ";
        writespace = true;
        cout << saux.top();
        saux.pop();
    }
}

int main()
{
    Stack<int> s;
    string command;
    while (cin >> command) {
        if (command == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "top") {
            cout << s.top() << endl;
        } else if (command == "size") {
            cout << s.size() << endl;
        } else if (command == "mul") {
            int n;
            cin >> n;
            s.mul(n);
        } else if (command == "print") {
            imprimeix(s);
            cout << endl;
        }
    }
}