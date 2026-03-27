#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "sumOfValues.hpp"

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
        cout << sumOfValues(first) << endl;
        while (first != NULL) {
            Item *current = first;
            first = first->next;
            delete current;
        }
    }
}
