# Lab 1:

## Getting started with DS Lab Preliminaries

# **Pointers**

1. A very basic programming with pointer

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a; // Pointer stores the address of 'a'
    
    cout << "Value of a: " << a << endl;
    cout << "Memory address of a: " << ptr << endl;
    
    return 0;
}

```

2. A little bit more example with pointer

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a; 
    
    *ptr = 20; // Modifying the original variable using the pointer
    
    cout << "New value of a: " << a << endl;
    cout << "Dereferenced pointer value: " << *ptr << endl;
    
    return 0;
}

```

3. A bit more complex with pointer (Pointer to a Pointer)

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 30;
    int *ptr = &a;       // Pointer to an integer
    int **ptr2 = &ptr;   // Pointer to a pointer

    cout << "Value of a using ptr2: " << **ptr2 << endl;
    cout << "Address of ptr itself: " << ptr2 << endl;

    return 0;
}

```

4. A more more complex with pointer (Dynamic Memory Allocation)

```cpp
#include <iostream>
using namespace std;

int main() {
    // Allocating memory dynamically on the heap
    int *ptr = new int; 
    *ptr = 500;

    cout << "Dynamically allocated value: " << *ptr << endl;

    // Freeing the memory to prevent memory leaks
    delete ptr; 
    ptr = nullptr; // Good practice: point to null after deleting

    return 0;
}

```

# **Structure**

1. A very basic program with structure

```cpp
#include <iostream>
using namespace std;

struct Student {
    int id;
    float cgpa;
};

int main() {
    Student s1;
    s1.id = 101;
    s1.cgpa = 3.75;
    
    cout << "ID: " << s1.id << ", CGPA: " << s1.cgpa << endl;
    return 0;
}

```

2. A little bit more complex (Nested Structure)

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    int zipCode;
};

struct Student {
    int id;
    string name;
    Address studentAddress; // Nested structure inside Student
};

int main() {
    Student s1;
    s1.id = 102;
    s1.name = "Rahim";
    s1.studentAddress.city = "Sylhet";
    s1.studentAddress.zipCode = 3100;
    
    cout << s1.name << " lives in " << s1.studentAddress.city << endl;
    return 0;
}

```

# 3. Array of structure and accessing data

```cpp
#include <iostream>
using namespace std;

struct Student {
    int id;
    float cgpa;
};

int main() {
    Student arr[3]; // Array capable of holding 3 Student records
    
    arr[0].id = 1; arr[0].cgpa = 3.5;
    arr[1].id = 2; arr[1].cgpa = 3.8;
    arr[2].id = 3; arr[2].cgpa = 3.9;
    
    for(int i = 0; i < 3; i++) {
        cout << "Student " << i+1 << " ID: " << arr[i].id << endl;
    }
    
    return 0;
}

```

# **Structure and Pointer**

1. Program with structure and pointer

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
};

int main() {
    Node n1;
    n1.data = 50;
    
    // Pointer storing the address of the structure
    Node *ptr = &n1; 
    
    return 0;
}

```

2. Access data with structure and pointer


```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // Pointer to another Node structure
};

int main() {
    Node n1, n2;
    
    n1.data = 10;
    n2.data = 20;
    
    // Linking n1 to n2
    n1.next = &n2; 
    
    // Accessing n2's data using the pointer inside n1
    cout << "Accessing n2's data through n1: " << n1.next->data << endl;
    
    return 0;
}

```

# **More on structure**

1. Constructor and destructor

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    
    // Constructor triggers automatically upon creation
    Node() { 
        data = 0;
        cout << "Node created and initialized to 0!" << endl;
    }
    
    // Destructor triggers automatically when leaving scope
    ~Node() { 
        cout << "Node destroyed and memory cleaned up!" << endl;
    }
};

int main() {
    Node n1; 
    return 0;
}

```

2. Function in structure

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    
    // Member function bound to the structure
    void printData() { 
        cout << "The stored data is: " << data << endl;
    }
};

int main() {
    Node n1;
    n1.data = 25;
    
    n1.printData(); 
    
    return 0;
}

```

# **Time complexity analysis**

1. Some example of O(1) code

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    
    // Accessing a specific index takes the same amount of time regardless of array size
    cout << "First element: " << arr[0] << endl; 
    
    return 0;
}

```

2. Some example of O(n) code

```cpp
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

```

3. Some example of O(n^2) code

```cpp
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

```
