#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int *ptr = &a;

    cout << "value of a: " << a << endl;
    cout << "Memory address of a: " << ptr << endl;

    return 0;

}
