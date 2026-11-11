#include<iostream>
using namespace std;
struct Node{
int val;
Node *next;
};
struct stack{
Node *top;
stack(){
top==NULL;
cout <<"Linked List Stack initialized!\n";}
void push(int x){
Node *newNode =new Node;
newNode->val=x;
newNode->next =top;
top= newNode;
cout << "Pushed"<< x << "onto the stack.\n";
 }
};
int main (){
stack s;
s.push(10);
s.push(20);
s.push(30);

return 0;
}
