#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
struct stack
{
    Node *top;
    stack()
    {
        top = NULL;
        cout << "Linked List Stack initalized!\n";
    }
    void push(int x)
    {
        Node *NewNode = new Node;
        NewNode->val = x;
        NewNode->next = top;
        top = NewNode;
        cout << "Pushed " << x << " onto the stack.\n";
    }
};
int main()
{
    stack s;
    s.push(10);
    s.push(20);    
    s.push(30);
    return 0;
}