#pragma once
#include "node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void insert(char value);
    void printList();
    Node* getHead() const;
};
LinkedList concatenate(LinkedList& list1, LinkedList& list2);
LinkedList intersection(LinkedList& list1, LinkedList& list2);
int compareStrings(LinkedList& list1, LinkedList& list2);

