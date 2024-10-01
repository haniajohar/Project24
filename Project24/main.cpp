#include <iostream>
#include "list.h"
using namespace std;

int main() {
    LinkedList list1, list2;
    list1.insert('a');
    list1.insert('b');
    list1.insert('c');
    list2.insert('b');
    list2.insert('c');
    list2.insert('d');
    LinkedList concatenatedList = concatenate(list1, list2);
    cout << "Concatenated List: ";
    concatenatedList.printList();
    LinkedList intersectedList = intersection(list1, list2);
    cout << "Intersection List: ";
    intersectedList.printList();
    int comparisonResult = compareStrings(list1, list2);
    if (comparisonResult == 0) {
        cout << "The strings are equal." << endl;
    }
    else if (comparisonResult < 0) {
        cout << "The first string is lexicographically smaller." << endl;
    }
    else {
        cout << "The first string is lexicographically greater." << endl;
    }

    return 0;
}