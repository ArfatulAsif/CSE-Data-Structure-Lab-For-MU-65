#include<iostream>
using namespace std;
struct Node{
    int val;
    Node *next;
};
struct stack{
    Node *top;
    stack()
{
    top=NULL;
    cout<<"Linked List Stack initalized!\n";
}
bool isEmpty()
{
    return top ==NULL;
}
};
int main()
{
stack s;
if(s.isEmpty())
{
    cout<<"The stack is currently empty.\n";
}
return 0;
}