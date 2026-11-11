#include <iostream>
using namespace std;

struct student{
    int id;
    float cgpa;
    };
int main ()
{
student arr[3];
arr[0].id = 1;arr[0].cgpa = 3.5;
arr[1].id = 2; arr[1].cgpa =3.8;
arr[3].id =3;arr[2].cgpa =3.9;

for(int i =0; i < 3; i++)
{
cout << "Student"<< i+1<< "ID:"<< arr [i].id<< endl;
}
return 0;
}
