#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

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


// Pre:  Sigui S el valor inicial de la pila s que es rep com a paràmetre.
//       Els valors guardats a S son majors o iguals a 0.
// Post: Sigui S' la pila retornada. S i S' tenen el mateix nombre d'elements.
//       A més a més, per a cada posició p de S', si S té un valor x diferent de 0 a posició p,
//       llavors S' també té x a posició p.
//       En canvi, si S té valor 0 a posició p, llavors el valor de S' a posició p és
//       la suma de tots els valors de S a posició parell per sota de p.
stack<int> replace0sWithBelowSumPosEven(stack<int> s, int sum = 0) {
   
    if (s.empty()) return stack<int>();

    int top = s.top();
    s.pop();

    if (top == 0) {
        stack<int> sub = replace0sWithBelowSumPosEven(s, sum); // Llamada recursiva para obtener la suma de los elementos pares anteriores.
        int tempSum = 0; // Variable temporal para almacenar la suma de los elementos pares anteriores.
        while (!sub.empty()) { // Iteramos sobre la pila de suma para obtener la suma de los elementos pares anteriores.
            tempSum += sub.top();
            sub.pop();
            if (!sub.empty()) sub.pop(); // Descartamos el siguiente elemento para obtener solo los elementos pares.
        }
        top = tempSum; // Asignamos la suma de los elementos pares anteriores a top.
    } else if (s.size() % 2 == 0) { // Si el índice del elemento es par, actualizamos la suma.
        sum += top;
    }

    stack<int> result = replace0sWithBelowSumPosEven(s, sum);
    result.push(top);
    return result;
}



int main()  {
	vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
    for (int i = 0; i < int(v.size()); ++i)
        writeStack(replace0sWithBelowSumPosEven(v[i]));
}
