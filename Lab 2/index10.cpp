
#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // Execution time grows linearly with the size of 'n'
    for(int i = 0; i < n; i++) {
        cout << "Iteration: " << i << endl;
    }

    return 0;
}
