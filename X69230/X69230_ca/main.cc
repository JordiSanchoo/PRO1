#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

void aux (stack<int>& s, stack<int>& res, int compt, int& res0, int& res1){
	
	if (not s.empty()){
		int top = s.top();
		s.pop();
		++compt;
		aux(s,res, compt, res0, res1);
		
		if (compt%2 == 0){
			res0+= top;
			res.push(res0-res1);
		}
		else{
			res1 += top;
			res.push(res1-res0);
		}
	}
}

stack<int> alternatedSumBelow(stack<int> s){
	stack<int> res;
	int compt = -1, res0 = 0, res1 = 0;
	aux (s, res, compt, res0, res1);
	return res;
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS
static stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

static void writeStack(stack<int> &s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStack(s);
    if (writespace) cout << " ";
    cout << x;
}
#endif

int main()  {
  
    vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 50; ++j)
        	s = alternatedSumBelow(v[i]);
        writeStack(s); cout << endl;
    }
}
