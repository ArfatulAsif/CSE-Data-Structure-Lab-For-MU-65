#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
    node *prev;
};
struct DoublyLinkedList
{
    node *head, *tail;

    DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;
        cout<<"Doubly Linked List initialized!\n";
    }
};
int main()
{
    DoublyLinkedList dl;
    return 0;
}
