# **Lab 5: Stack and Queue (Linked List Implementation)**

---

## **Section A: Stack (LIFO Data Structure)**

Using a Linked List to implement a Stack is highly efficient because it grows and shrinks dynamically. We don't have to worry about a maximum size limit (Stack Overflow is only constrained by system memory).

Since a Stack is **LIFO** (Last In, First Out), we will always add new elements to the **head** (which we will call `top`) and remove elements from the **head**.

### **Part 1: Defining the Node and Stack Structure (Build)**

We define a simple singly linked node. Our `Stack` structure will only need a single pointer, `top`, which keeps track of the highest element.

```cpp
#include <iostream>
using namespace std;

// Structure for an individual node
struct Node {
    int val;
    Node *next;
};

// Structure to manage the Stack
struct Stack {
    Node *top;

    // Constructor to initialize an empty stack
    Stack() {
        top = NULL;
        cout << "Linked List Stack initialized!\n";
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    // Creating the Stack object
    Stack s;
    
    if(s.isEmpty()) {
        cout << "The stack is currently empty.\n";
    }

    return 0;
}

```

---

### **Part 2: Inserting into the Stack (`push`)**

To push an element, we create a new node, point its `next` pointer to the current `top`, and then update `top` to be this new node. This is exactly like inserting at the head of a Singly Linked List.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Stack {
    Node *top;

    Stack() {
        top = NULL;
        cout << "Linked List Stack initialized!\n";
    }

    // Insert an element at the top - Time Complexity: O(1)
    void push(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        
        // Link the new node to the current top element
        newNode->next = top;
        
        // Update top to point to the new node
        top = newNode;
        
        cout << "Pushed " << x << " onto the stack.\n";
    }
};

int main() {
    Stack s;

    // Test pushing elements
    s.push(10);
    s.push(20);
    s.push(30);

    return 0;
}

```

---

### **Part 3: Printing and Deletion (`pop`)**

To remove an element (`pop`), we temporarily store the current `top` node, move the `top` pointer to the next node in the chain, and then delete the old top to free memory. We will also add a `printStack` function to traverse the list.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Stack {
    Node *top;

    Stack() {
        top = NULL;
        cout << "Linked List Stack initialized!\n";
    }

    void push(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = top;
        top = newNode;
    }

    // Remove the top element - Time Complexity: O(1)
    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return -1;
        }
        
        Node *temp = top;        // Hold the current top node
        int poppedVal = temp->val; // Extract the value
        
        top = top->next;         // Move top pointer down the list
        delete temp;             // Free the memory
        
        return poppedVal;
    }

    // Print elements from top to bottom - Time Complexity: O(n)
    void printStack() {
        if (top == NULL) {
            cout << "Stack is Empty!\n";
            return;
        }
        
        cout << "Stack (Top to Bottom): ";
        Node *cur = top;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "\nAfter pushes:\n";
    s.printStack(); // Expected: 30 20 10

    cout << "\nPopped element: " << s.pop() << "\n"; // Removes 30
    
    cout << "\nAfter popping:\n";
    s.printStack(); // Expected: 20 10

    return 0;
}

```

---

---
## **Section B: Queue (FIFO Data Structure)**



### **Part 1: Defining the Node and Queue (Build)**



```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Queue {
    Node *headPtr; // Renamed so we can use 'front()' for the function

    Queue() {
        headPtr = NULL;
        cout << "STL-Style Queue initialized!\n";
    }

    bool empty() { // STL uses empty() instead of isEmpty()
        return headPtr == NULL;
    }
};

int main() {
    Queue q;
    
    if(q.empty()) {
        cout << "The queue is currently empty.\n";
    }

    return 0;
}

```

### **Part 2: Inserting into the Queue (`push_back`)**

Because a queue adds to the _back_ of the line, we use `push_back()`. We traverse to the end of the list and attach the new node.

  



```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Queue {
    Node *headPtr;

    Queue() {
        headPtr = NULL;
        cout << "STL-Style Queue initialized!\n";
    }

    // Insert at the end - STL calls this push_back()
    void push_back(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL; 

        if (headPtr == NULL) {
            headPtr = newNode;
            cout << "Pushed " << x << " to the back.\n";
            return;
        }

        Node *cur = headPtr;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        
        cout << "Pushed " << x << " to the back.\n";
    }
};

int main() {
    Queue q;

    q.push_back(5);
    q.push_back(15);
    q.push_back(25);

    return 0;
}

```

### **Part 3: Viewing (`front`) and Deleting (`pop_front`)**

Just like actual C++ STL, `front()` will return the value at the start of the queue, and `pop_front()` will delete it without returning anything.



```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Queue {
    Node *headPtr;

    Queue() {
        headPtr = NULL;
        cout << "STL-Style Queue initialized!\n";
    }

    void push_back(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL;

        if (headPtr == NULL) {
            headPtr = newNode;
            return;
        }

        Node *cur = headPtr;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    // View the first element without removing it
    int front() {
        if (headPtr == NULL) {
            cout << "Queue is empty!\n";
            return -1; 
        }
        return headPtr->val;
    }

    // Remove the front element (Returns void, just like STL)
    void pop_front() {
        if (headPtr == NULL) {
            cout << "Queue Underflow! Nothing to pop.\n";
            return;
        }

        Node *temp = headPtr;        // Hold the current front node
        headPtr = headPtr->next;     // Move head pointer to the next node

        delete temp;                 // Free the memory
    }

    // Helper to visualize the queue
    void printQueue() {
        if (headPtr == NULL) {
            cout << "Queue is Empty!\n";
            return;
        }
        
        cout << "Queue: ";
        Node *cur = headPtr;
        while (cur != NULL) {
            cout << cur->val;
            if (cur->next != NULL) cout << " <- ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;

    q.push_back(5);
    q.push_back(15);
    q.push_back(25);
    
    cout << "\nAfter pushing elements:\n";
    q.printQueue(); 

    // STL Way: View the front element, then pop it
    cout << "\nFront element is: " << q.front() << "\n";
    cout << "Popping front element...\n";
    q.pop_front(); 
    
    cout << "\nAfter popping:\n";
    q.printQueue(); 

    // Do it again
    cout << "\nFront element is now: " << q.front() << "\n";
    q.pop_front();
    q.pop_front();
    
    cout << "\nAfter popping all elements:\n";
    q.printQueue(); 

    return 0;
}

```
