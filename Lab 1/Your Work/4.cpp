#include<iostream>
using namespace std;
int main()
{
    //Allocating memory dynamically on the heap
    int *ptr=new int;
    *ptr=500;

    cout << "Dynamically allocated value: " << *ptr << endl;

    //Freeing the memory to prevent memory leaks
    delete ptr;

    return 0;
}
