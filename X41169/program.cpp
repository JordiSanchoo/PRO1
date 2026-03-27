#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "copy.hpp"

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
    string line;
    while (getline(cin, line)) {
        istringstream mycin(line);
        Item* first = NULL;
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
        Item* copyfirst = copy(first);
        writeSequence(first);
        makeRandomSequence(first);
        deleteSequence(first);
        writeSequence(copyfirst);
        deleteSequence(copyfirst);
    }
}
