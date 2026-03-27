#include<iostream>
#include<vector>

using namespace std;



 /* Pre: 0 < k <= v.size() */
 /* Post: Retorna l'index del primer element del subvector v de
    llargada k amb una mitjana menor; si hi ha mes d'un subvector
    amb una mitjana menor, retorna el que tingui un index menor */
int mitjana_menor(const vector<int> &v, int k){
	int suma_menor = 0;
	int i_menor = 0;
	for(int i = 0; i < k++; i++){
		suma_menor += v[i];
	}
	for(unsigned int j = 1; j <= v.size()-k; j++){
		int sum = 0;
		for(unsigned int i = j; i < j+k; i++){
			sum = suma -v[j-1] + v[j-1+k];
		}
		if (sum < suma_menor){
			suma_menor = sum;
			i_menor = j;
		}
	}
return i_menor;
}



//Pre: v està buit
//Post: s'han afegit 'mida' enters llegits del canal d'entrada al vector v
void llegir_vector(vector<int> &v, int mida){
	for(int i = 0; i < mida; i++){
		cin>>v[i];
	}
}

void escriure_vector(const vector<int> &v, int mida){
	cout<<"[";
	if (mida>0){
		cout<<v[0];
		for(int i = 1; i < mida; i++){
			cout<<","<<v[i];
		}
		cout<<"]"<<endl;
	}
	
}

 
 

int main(){

	int mida;
	cin>>mida;
	vector<int>v(mida);
	llegir_vector(v, mida);
	escriure_vector(v, mida);
}
