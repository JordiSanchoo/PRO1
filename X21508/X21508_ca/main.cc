#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

void suma(stack<int>& q1, stack<int>& q2, stack<int>& res){
	
	if (q1.empty() and q2.empty()){
		return;
	}
	int top1 = 0;
	int top2 = 0;
	if (q1.size() > q2.size()){
		if (not q1.empty()){
		top1 = q1.top();
		q1.pop();
		}
	}
	else {
		if (not q1.empty()){
		top1 = q1.top();
		q1.pop();
		}
		if (not q2.empty()){
			top2 = q2.top();
			q2.pop();		
		}
	}

	suma(q1,q2,res);
	res.push(top1+top2);
}

stack<int> suma_piles(const stack<int> &p1, const stack<int> &p2){
	
	stack<int> q1 = p1;
	stack<int> q2 = p2;
	stack<int> res;
	if (q2.size()>q1.size()) swap(q1,q2);
	suma(q1,q2,res);
	
	return res;
}



#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

stack<int> readStack(const string &line) {
	istringstream mycin(line);
	stack<int> s;
	int x;
	while (mycin >> x) {
		s.push(x);
	}
	return s;
}

void readStack(const string &line, stack<int> &p1, stack<int> &p2) {
	int i1 = line.find('[');	
	int i2 = line.find(']', i1+1);	
	int i3 = line.find('[', i2+1);
	int i4 = line.find(']', i3+1);
	p1 = readStack(line.substr(i1+1, i2-i1-1));
	p2 = readStack(line.substr(i3+1, i4-i3-1));
}

void writeStackRec(stack<int> &s) {
	if (not s.empty()) {
		int x = s.top();
		s.pop();
    bool writespace = not s.empty();
    writeStackRec(s);
    if (writespace) cout << " ";
    cout << x;
  }
}

void writeStack(stack<int> s) {
	cout << '[';
	writeStackRec(s);
  cout << ']';
	cout << endl;
}

#endif

int main() {
	string l;
	while (getline(cin, l)) {
		stack<int> p1, p2;
		readStack(l, p1, p2);
		writeStack(suma_piles(p1, p2));
	}	
	return 0;
}
