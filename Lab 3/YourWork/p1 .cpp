#include<iostream>
using namespace std;
struct node {
     int val;
     node*next;
     };
struct singlylinkedlist{
  node*head,*tail;
singlylinkedlist() {
  head= NULL;
  tail= NULL;
cout << "singly linked list initialized!\n";
   }
};
int main (){
singlylinkedlist s1;
return 0;
}
