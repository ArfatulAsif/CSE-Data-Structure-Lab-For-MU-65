#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

struct SinglyLinkedList {
    node *head, *tail;

    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Singly Linked List initialized!\n";
    }

    // Time Complexity: O(1)
    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;

        if (head == NULL && tail == NULL) { // Empty list
            head = tail = cur;
            return;
        }
        
        tail->next = cur; // Link old tail to new node
        tail = cur;       // Update tail pointer
    }

    // Time Complexity: O(n)
    void printList() {
        cout << "SinglyLinkedList: ";
        node *cur = head;
        
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        
        while (cur != NULL) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sl;

    // Test Enqueue
    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);
    
    // Test Print
    sl.printList(); // Expected: 10 -> 20 -> 30 -> NULL
    
    return 0;
}
