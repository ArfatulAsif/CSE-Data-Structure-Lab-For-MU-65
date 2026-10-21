#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int *ptr=&a;

    *ptr=20;//Modifying the original variable using the pointer

    cout << "New value of a: " << a << endl;
    cout << "Dereferenced pointer value: " << *ptr << endl;

    return 0;
}
