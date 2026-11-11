#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node *prev;
};

struct DoublyLinkedList {
    node *head, *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Doubly Linked List initialized!\n";
    }

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        cur->prev = NULL;

        if (head == NULL && tail == NULL) {
            head = tail = cur;
            return;
        }

        tail->next = cur;
        cur->prev = tail;
        tail = cur;
    }

    void printListForward() {
        cout << "Forward:  NULL <- ";
        node *cur = head;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->next != NULL) cout << " <-> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }

    void printListReverse() {
        cout << "Reverse:  NULL <- ";
        node *cur = tail;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->prev != NULL) cout << " <-> ";
            cur = cur->prev;
        }
        cout << " -> NULL\n";
    }


    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = head->next;
        cur->prev = head;

        if (head->next != NULL) {
            head->next->prev = cur;
        } else {
            tail = cur;
        }

        head->next = cur;
    }

    void insertBeforeTail(int x) {
        if (tail == NULL || head == tail) {

            node *cur = new node;
            cur->val = x;
            cur->next = head;
            cur->prev = NULL;

            if (head != NULL) head->prev = cur;
            head = cur;
            if (tail == NULL) tail = cur;
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        cur->prev = tail->prev;

        tail->prev->next = cur;
        tail->prev = cur;
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
            newNode->prev = cur;

            if (cur->next != NULL) {
                cur->next->prev = newNode;
            } else {
                tail = newNode;
            }

            cur->next = newNode;
        } else {
            cout << "Value " << toFind << " not found!\n";
        }
    }
};

int main() {
    DoublyLinkedList dl;

    dl.enqueue(10);
    dl.enqueue(20);
    dl.enqueue(30);
    cout << "After enqueue: \n";
    dl.printListForward();

    dl.insertAfterHead(15);
    cout << "\nAfter insertAfterHead(15): \n";
    dl.printListForward();

    dl.insertBeforeTail(25);
    cout << "\nAfter insertBeforeTail(25): \n";
    dl.printListForward();

    dl.insertAfterVal(15, 17);
    cout << "\nAfter insertAfterVal(15, 17): \n";
    dl.printListForward();
    dl.printListReverse();

    return 0;
}
