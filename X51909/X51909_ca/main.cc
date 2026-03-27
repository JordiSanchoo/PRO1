#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;


void interca(stack<int>& q1, stack<int>& q2, stack<int>& q3){
	if (q1.empty() and q2.empty()) return;

	if (q1.size()>q2.size()){
		int top1 = q1.top();
		q1.pop();
		interca(q1,q2,q3);
		q3.push(top1);
	}
	else{
		if (not q2.empty()){
			int top1 = q1.top();
			q1.pop();
			int top2 = q2.top();
			q2.pop();
			interca(q1,q2,q3);
			q3.push(top1);
			q3.push(top2);
		}
	}
}

// Pre:  Siguin [a1,a2,...,an] i [b1,b2,...,bm] els valors inicials de q1 i q2, respectivament.
// Post: En el cas n>=m, la cua retornada és [a1,b1,a2,b2,...,am,bm,a{m+1},a{m+2},...,an].
//       En el cas n<m, la cua retornada és [b1,a1,b2,a2,...,bn,an,b{n+1},b{n+2},...,bm].
stack<int> intercal(stack<int> q1, stack<int> q2){
	stack<int> res;
	if (q1.size() >= q2.size()) interca(q1,q2,res);
	else interca(q2,q1,res);
	return res;
}

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
    string s;
    while (getline(cin, s)) {
        stack<int> s1 = readStack(s);
        getline(cin, s);
        stack<int> s2 = readStack(s);
        getline(cin, s);
        writeStack(intercal(s1, s2));
    }
}
