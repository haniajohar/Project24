#include <iostream>
#include "list.h"
using namespace std;
LinkedList::LinkedList() : head(nullptr) {}
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
void LinkedList::insert(char value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
Node* LinkedList::getHead() const {
    return head;
}
void LinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
LinkedList concatenate(LinkedList& list1, LinkedList& list2) {
    LinkedList result;
    Node* current1 = list1.getHead();
    Node* current2 = list2.getHead();

    while (current1 != nullptr) {
        result.insert(current1->data);
        current1 = current1->next;
    }
    while (current2 != nullptr) {
        result.insert(current2->data);
        current2 = current2->next;
    }

    return result;
}
LinkedList intersection(LinkedList& list1, LinkedList& list2) {
    LinkedList result;
    Node* current1 = list1.getHead();
    Node* current2;

    while (current1 != nullptr) {
        current2 = list2.getHead();
        while (current2 != nullptr) {
            if (current1->data == current2->data) {
                result.insert(current1->data);
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}
int compareStrings(LinkedList& list1, LinkedList& list2) {
    Node* current1 = list1.getHead();
    Node* current2 = list2.getHead();

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            return -1;
        }
        if (current1->data > current2->data) {
            return 1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 == nullptr && current2 != nullptr) {
        return -1;
    }
    if (current1 != nullptr && current2 == nullptr) {
        return 1;
    }

    return 0;
}
