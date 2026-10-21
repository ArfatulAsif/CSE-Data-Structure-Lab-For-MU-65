#include<iostream>
using namespace std;
int main()
{
    int a=30;
    int *ptr= &a;  //Pointer to an integer
    int **ptr2= &ptr;  //Pointer to a pointer

    cout << "Value of a using ptr2: " << **ptr2 << endl;
    cout << "Adress of ptr itself: " << ptr2 << endl;

    return 0;
}
