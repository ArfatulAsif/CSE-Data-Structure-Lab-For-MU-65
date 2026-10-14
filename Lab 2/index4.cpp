#include <iostream>
using namespace std;

struct Node {
    int data;
};

int main() {
    Node n1;
    n1.data = 50;
    
    // Pointer storing the address of the structure
    Node *ptr = &n1; 
    
    return 0;
}
