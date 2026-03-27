#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

stack<int> replace0sWithBelowSumPosEven(stack<int> s);

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}


void writeStackRec(stack<int> &s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStackRec(s);
    if (writespace) cout << " ";
    cout << x;
}

void writeStack(stack<int> s)
{
    writeStackRec(s);
    cout << endl;
}

#endif

int main()  {
	vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
    for (int i = 0; i < int(v.size()); ++i)
        writeStack(replace0sWithBelowSumPosEven(v[i]));
}
