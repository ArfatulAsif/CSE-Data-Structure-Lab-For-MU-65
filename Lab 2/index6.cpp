
#include <iostream>
using namespace std;

struct Node {
    int data;

    // Constructor triggers automatically upon creation
    Node() {
        data = 0;
        cout << "Node created and initialized to 0!" << endl;
    }

    // Destructor triggers automatically when leaving scope
    ~Node() {
        cout << "Node destroyed and memory cleaned up!" << endl;
    }
};

int main() {
    Node n1;
    return 0;
}
