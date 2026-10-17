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

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        if (head == NULL && tail == NULL) {
            head = tail = cur;
            return;
        }
        tail->next = cur;
        tail = cur;
    }

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

    
    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = head->next; 
        head->next = cur;       
        
        if (head == tail) { 
            tail = cur;
        }
    }

    
    void insertBeforeTail(int x) {
        if (head == NULL || head == tail) {
            node *cur = new node;
            cur->val = x;
            cur->next = head;
            head = cur;
            if (tail == NULL) tail = cur;
            return;
        }
        node *prev = head;
        while (prev->next != tail) { 
            prev = prev->next;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        prev->next = cur;
    }
void insertAfterVal(int toFind, int toAdd) {
        node *cur = head;
        while (cur != NULL && cur->val != toFind) {
            cur = cur->next;
        }
        if (cur != NULL) {
            node *newNode = new node;
            newNode->val = toAdd;
            newNode->next = cur->next;
            cur->next = newNode;
            if (cur == tail) tail = newNode; 
        } else {
            cout << "Value " << toFind << " not found!\n";
        }
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);
    cout << "After enqueue: ";
    sl.printList(); 

    sl.insertAfterHead(15);
    cout << "After insertAfterHead(15): ";
    sl.printList(); 

    sl.insertBeforeTail(25);
    cout << "After insertBeforeTail(25): ";
    sl.printList(); 

    sl.insertAfterVal(15, 17);
    cout << "After insertAfterVal(15, 17): ";
    sl.printList(); 

    return 0;
}
