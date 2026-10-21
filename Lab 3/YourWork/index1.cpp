#include <iostream>
using namespace std;

// Structure for an individual node
struct node {
    int val;
    node *next;
};

// Class/Structure to manage the Linked List
struct SinglyLinkedList {
    node *head, *tail;

    // Constructor to initialize an empty list
    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Singly Linked List initialized!\n";
    }
};

int main() {
    // Creating the list object
    SinglyLinkedList s1;
    return 0;
}
