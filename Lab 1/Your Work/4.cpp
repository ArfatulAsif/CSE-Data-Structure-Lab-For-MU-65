#include <iostream>
using namespace std;

int main() {

    int *ptr = new int;
    *ptr = 500;

    cout << "Dynamically allocated value: " << *ptr << endl;

    delete ptr;

    return 0;
}
