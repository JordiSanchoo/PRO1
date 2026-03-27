#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

int main(){
	
	int num_pil;
	cin>>num_pil;
	string paraula;
	string linea;
	vector<stack<string> > pilas(num_pil); 
	
	getline(cin,linea);
	for (int i = 0; i < num_pil; i++){
		getline(cin,linea);
		istringstream iss(linea);
		while (iss>>paraula){
			pilas[i].push(paraula);
		}
	}
	
	getline(cin,linea);

	
	while (getline(cin, linea)){
		istringstream iss(linea);
		iss>>paraula;
		if (paraula == "PRESTEC"){
			int num;
			iss>>num;
			if (num > 0 and num <= num_pil and not(pilas[num-1].empty())){
			pilas[num-1].pop();
			}
		}
		else {
			string titol;
			iss>>titol;
			int num;
			iss>>num;
			if (num > 0 and num <= num_pil){
				pilas[num-1].push(titol);
			}
		}
	}
	
	 for (int i = 0; i < num_pil; i++) {
        cout << "Pila " << i + 1 << ":";
        stack<string> temp_stack;
        while (!pilas[i].empty()) {
            temp_stack.push(pilas[i].top());
            pilas[i].pop();
        }
        vector<string> temp_vector;
        while (!temp_stack.empty()) {
            temp_vector.push_back(temp_stack.top());
            temp_stack.pop();
        }
        for (unsigned int j = 0; j < temp_vector.size(); j++) {
            cout << " " << temp_vector[j];
        }
        cout << endl;
    }
	return 0;
}
