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
};

int main() {
  SinglyLinkedList sl;
  return 0;
}


