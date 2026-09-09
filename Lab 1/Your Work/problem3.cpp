#include<iostream>
using namespace std;
int main()
{
    int a = 30;
    int *ptr = &a;
    int **ptr2 = &ptr;

    cout<< "Value of a using ptr2:"<< **ptr2 << endl;
    cout<< "Address of ptr itself:"<< ptr2 <<endl;

    return 0;
   
}