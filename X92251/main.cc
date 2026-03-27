#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

void sumAboveOrBelowAux(stack<int>& sint, stack<string>& sstring, stack<int>& result, int sumAbove, int sumBelow) {
    if (!sint.empty()) {
        int current = sint.top();
        sint.pop();
        string currentString = sstring.top();
        sstring.pop();

        if (currentString == "above") {
            sumAbove += current;
            sumAboveOrBelowAux(sint, sstring, result, sumAbove, sumBelow);
        } 
        else { // currentString == "below"
            sumBelow += current;
            sumAboveOrBelowAux(sint, sstring, result, sumAbove, sumBelow);
        }
        result.push(currentString == "above" ? sumAbove : sumBelow);
    }
}


stack<int> sumAboveOrBelow(stack<int> sint, stack<string> sstring) {
    stack<int> result;
    sumAboveOrBelowAux(sint, sstring, result, 0, 0);
    return result;
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS
static stack<int> readStackInt(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

static stack<string> readStackString(string line)
{
    istringstream mycin(line);
    stack<string> s;
    string x;
    while (mycin >> x)
        s.push(x);
    return s;
}

template <typename T>
static void writeStack(stack<T> s)
{
    vector<T> v;
    while (not s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = int(v.size())-1; i >= 0; i--) {
        if (i < int(v.size())-1) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
#endif

int main()  {
    vector<stack<int> > v;
    vector<stack<string> > vs;
    string s;
    while (getline(cin, s)) {
        v.push_back(readStackInt(s));
        getline(cin, s);
        vs.push_back(readStackString(s));
    }
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 15; ++j)
        	s = sumAboveOrBelow(v[i], vs[i]);
        writeStack(s);
    }
}
