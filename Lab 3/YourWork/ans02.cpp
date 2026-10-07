#include <iostream>
using namespace std;
struct node {
     int val;
     node *next;
};
struct SinglyLinkedList{
    node *head, *tail;
    SinglyLinkedList(){
        head = NULL;
        tail= NULL;
        cout << "Singly Linked List initialized!\n";
        }
        void enqueue(int x){
              node *cur = new node;
              cur->val = x;
              cur->next = NULL;
              if(head == NULL && tail== NULL){
                 head=tail=cur;
                 return;
              }
              tail->next = cur ;
              tail = cur;

              }
              void printlist() {
                   cout << "SinglyLinkedList: ";
                   node *cur = head;
                   if (cur == NULL){
                       cout <<"List is Empty!\n";
                       return;
                   }
                  while(cur != NULL){
                    cout << cur->val << "-> ";
                    cur = cur->next;
                  }
                  cout << "NULL\n";

                   }

    };
    int main()
    {
        SinglyLinkedList s1;

        s1.enqueue(10);
        s1.enqueue(20);
        s1.enqueue(30);
        s1.printlist();
        return 0;
    }
