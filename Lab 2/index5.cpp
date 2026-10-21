#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // Pointer to another Node structure
};

int main() {
    Node n1, n2;
    
    n1.data = 10;
    n2.data = 20;
    
    // Linking n1 to n2
    n1.next = &n2; 
    
    // Accessing n2's data using the pointer inside n1
    cout << "Accessing n2's data through n1: " << n1.next->data << endl;
    
    return 0;
}
