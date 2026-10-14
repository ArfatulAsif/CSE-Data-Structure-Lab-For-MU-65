#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
struct queue
{
    Node *front;
    Node *rear;
    queue()
    {
    front = NULL;
    rear = NULL;
    cout << "Linked List queue initialized!\n";
    }

    void enqueue(int x)
    {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next= NULL;
        if(front == NULL && rear == NULL )
        {
            front = rear = newNode;
            cout << "Enqueued " << x << "to the queue.\n";
            return;

        }
        rear->next = newNode;
        rear = newNode;
        cout << "Enqueued " << x << " to the queue.\n";

    }
};
int main()
{
    queue q;
q.enqueue(5);
q.enqueue(15);
q.enqueue(25);
return 0;
}
