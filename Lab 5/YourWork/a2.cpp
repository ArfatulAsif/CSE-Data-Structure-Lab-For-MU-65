#include <iostream>
using namespace std;

struct Node
 {
    int val;
    Node *next;
};

struct Stack
 {
    Node *top;

    Stack() {
        top = NULL;
        cout << "Linked List Stack initialized!\n";
    }
    void push(int x)
    {
     Node *newnode = new Node;
     newnode -> val =x;
     newnode -> next = top;
     top= newnode;
     cout<< "Pushed"<< x<< "onto the stack.\n";
    }
 };
 int main()
 { Stack s;

 s.push(10);

 s.push(20);

 s.push(30);
 return 0;
 }
 
 
 
 



