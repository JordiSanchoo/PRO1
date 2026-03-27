#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "queue.hpp"

struct Container {
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
        if (this == &c) return;
    	word = c.word;
    }
	Container &operator=(const Container &c)
	{
    	word = c.word;
        return *this;
	}
};

int main()
{
    Queue<Container> q;
    string command;
    while (cin >> command) {
        if (command == "push") {
            Container c;
            cin >> c.word;
            q.push(c);
        } else if (command == "pop") {
            q.pop();
        } else if (command == "front") {
            cout << q.front().word << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "moveSecondToLast") {
			q.moveSecondToLast();
        }
    }
}
