
#include <iostream>
using namespace std;

int main() {
    int n = 4;

    // The inner loop runs 'n' times for every 'n' iterations of the outer loop
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "(" << i << ", " << j << ") ";
        }
        cout << endl;
    }

    return 0;
}
