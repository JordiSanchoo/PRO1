#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;


stack<int> remove01(stack<int> s){
	if (s.empty()) {
        return s;
    }

    int t=s.top();
    s.pop();
    
    remove01(s);
    
    int mida += 1;

    if (((t==0 and mida%2==0) or (t==1 and mida%2==1))) {
        s.push(t);
    }

    return s;
}

stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

void writeStack(stack<int> &s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStack(s);
    if (writespace) cout << " ";
    cout << x;
}

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
    vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 100; ++j)
        	s = remove01(v[i]);
        writeStack(s); cout << endl;
    }
}
