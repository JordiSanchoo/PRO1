#include <iostream>
#include <string>
#include <stack>
#include "utilitats.hpp"
#include "esborraSenars.hpp"

using namespace std;


int main() 
{
	stack<int> P;

	llegeix (P);
	esborraSenars (P);
	escriu (P);

	return 0;
}

