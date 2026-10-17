#include<iostream>
using namespace std;
int main()
{
int a=30;
int *ptr=&a;
int**ptr2=&ptr;
cout<<"value ofa using ptr2:"<<**ptr2<<endl;
cout<<"address of ptr itself:"<<ptr2<<endl;
return 0;
}
