#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *next;
};

struct Stack {
    Node *top;

    Stack (){
        top = NULL;
        cout << "Linked List Stack initialized!\n";
    }

    bool isEmpty(){
    return top == NULL;
    }
};
int main () {

    Stack s;

    if (s.isEmpty()) {
        cout << "The stack is currently empty.\n";
    }

    return 0;
}