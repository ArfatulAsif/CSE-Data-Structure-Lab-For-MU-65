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
        if (head == tail) tail = cur;
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

    
    int dequeue() {
        if (head == NULL) {
            cout << "Underflow!\n";
            return -1;
        }
        node *cur = head;
        int x = cur->val;

        if (head == tail) { 
            head = tail = NULL;
        } else {
            head = head->next; 
        }

        delete cur; 
        return x;
    }

    
    int deleteTail() {
        if (head == NULL) {
            cout << "Underflow!\n";
            return -1;
        }
        if (head == tail) { 
            int val = head->val;
            delete head;
            head = tail = NULL;
            return val;
        }

        node *prev = head;
        while (prev->next != tail) { 
            prev = prev->next;
        }

        int val = tail->val;
        delete tail;
        tail = prev;
        tail->next = NULL;

        return val;
    }

   
    int deleteValAfterHead() {
        if (head == NULL || head->next == NULL) {
            cout << "No node exists after head!\n";
            return -1;
        }
        node *toDelete = head->next;
        int val = toDelete->val;

        head->next = toDelete->next; 
        
        if (toDelete == tail) { 
            tail = head;
        }

        delete toDelete;
        return val;
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);
    
    sl.insertAfterHead(15);
    sl.insertBeforeTail(25);
    cout << "List before deletions: ";
    sl.printList(); 

    sl.dequeue();
    cout << "After dequeue (delete head): ";
    sl.printList(); 

    sl.deleteTail();
    cout << "After deleteTail: ";
    sl.printList();

    sl.deleteValAfterHead();
    cout << "After deleteValAfterHead: ";
    sl.printList(); 

    return 0;
}