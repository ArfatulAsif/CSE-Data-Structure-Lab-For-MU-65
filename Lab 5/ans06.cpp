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
    Queue()
     {
        front = NULL;
        rear = NULL;
        cout << "Linked List Queue initialized!\n";
    }

 void enqueue(int x)
 {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL;
        if (front == NULL && rear == NULL)
            {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
 int dequeue() {
        if (front == NULL)
            {
            cout << "Queue Underflow! Nothing to dequeue.\n";
            return -1;
        }
        Node *temp = front;
        int dequeuedVal = temp->val;

        front = front->next;
        if (front == NULL)
            {
            rear = NULL;
        }
        delete temp;
        return dequeuedVal;
    }

    void printQueue()
     {
        if (front == NULL)
            {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue (Front to Rear): ";
        Node *cur = front;
        while (cur != NULL)
            {
            cout << cur->val;
            if (cur->next != NULL) cout << " <- ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main()
 {
    queue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    cout << "\nAfter enqueues:\n";
    q.printQueue();
    cout << "\nDequeued element: " << q.dequeue() << "\n";
    cout << "\nAfter dequeue:\n";
    q.printQueue();
    q.dequeue();
    q.dequeue();
    cout<< " \nAfter dequeueing all elements:\n";
    q.printQueue();
    return 0;
 }
