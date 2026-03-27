#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#include "queue.hpp"

int mystoi(string s)
{
    istringstream mycin(s);
    int x;
    mycin >> x;
    return x;
}

int main()
{
    Queue<string> q;
    string command;
    while (cin >> command) {
        if (command == "push") {
            string s;
            cin >> s;
            q.push(s);
        } else if (command == "pop") {
            q.pop();
        } else if (command == "front") {
            cout << q.front() << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else {
            string s = command.substr(1, int(command.size())-2);
            int i = mystoi(s);
            cout << q[i] << endl;
        }
    }
}
