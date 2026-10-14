#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *next;
};
struct Queue {
    Node *front;
    Node *rear;
    Queue (){
        front = NULL;
        rear = NULL;
        cout << "Linked List Queue initialized!\n";
    }
    bool isEmpty (){
        return front == NULL;
    }
};
int main (){
    Queue q;
    if(q.isEmpty()){
        cout << "The queue is currently empty.\n";
    }
    return 0;
}