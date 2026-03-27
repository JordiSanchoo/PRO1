#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "push_back.hpp"

bool readSequence(Item* (&first))
{
    string line;
	if (!getline(cin, line)) return false;
    istringstream mycin(line);
    first = NULL;
    int value;
    if (mycin >> value) {
    	first = new Item();
    	first->value = value;
        Item* current = first;
        while (mycin >> value) {
        	current->next = new Item();
            current = current->next;
            current->value = value;
        }
        current->next = NULL;
    }
    return true;
}

void writeSequence(Item* first)
{
    bool writespace = false;
    while (first != NULL) {
        if (writespace) cout << " ";
        writespace = true;
        cout << first->value;
        first = first->next;
    }
    cout << endl;
}

void deleteSequence(Item* first)
{
    while (first != NULL) {
        Item *current = first;
        first = first->next;
        delete current;
    }
}

void makeRandomSequence(Item* first)
{
    while (first != NULL) {
        first->value = rand()%1000;
        first = first->next;
    }
}

int main()
{
    Item* first;
    while (readSequence(first)) {
        int value;
        cin >> value;
        string s;
        getline(cin,s);
        push_back(first, value);
        writeSequence(first);
        deleteSequence(first);
    }
}
