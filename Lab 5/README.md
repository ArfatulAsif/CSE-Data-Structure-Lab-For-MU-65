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

Because a Queue is **FIFO** (First In, First Out), elements are added at one end and removed from the other. To keep our operations at $\mathcal{O}(1)$ time complexity, we maintain two pointers: `front` (equivalent to head) and `rear` (equivalent to tail).

### **Part 1: Defining the Node and Queue Structure (Build)**

We will initialize an empty queue where both `front` and `rear` pointers are set to `NULL`.

```cpp
#include <iostream>
using namespace std;

// Structure for an individual node
struct Node {
    int val;
    Node *next;
};

// Structure to manage the Queue
struct Queue {
    Node *front;
    Node *rear;

    // Constructor to initialize an empty queue
    Queue() {
        front = NULL;
        rear = NULL;
        cout << "Linked List Queue initialized!\n";
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    // Creating the Queue object
    Queue q;
    
    if(q.isEmpty()) {
        cout << "The queue is currently empty.\n";
    }

    return 0;
}

```

---

### **Part 2: Inserting into the Queue (`enqueue`)**

To enqueue, we create a new node and add it to the `rear` (tail) of the linked list. If the queue is empty, the new node becomes both the `front` and the `rear`.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Queue {
    Node *front;
    Node *rear;

    Queue() {
        front = NULL;
        rear = NULL;
        cout << "Linked List Queue initialized!\n";
    }

    // Insert an element at the rear - Time Complexity: O(1)
    void enqueue(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL; // As it's added at the rear, next is always NULL

        // If the queue is completely empty
        if (front == NULL && rear == NULL) {
            front = rear = newNode;
            cout << "Enqueued " << x << " to the queue.\n";
            return;
        }

        // Otherwise, attach to the current rear and update the rear pointer
        rear->next = newNode;
        rear = newNode;
        
        cout << "Enqueued " << x << " to the queue.\n";
    }
};

int main() {
    Queue q;

    // Test enqueueing elements
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    return 0;
}

```

---

### **Part 3: Printing and Deletion (`dequeue`)**

To dequeue, we remove the node at the `front` (head) of the list. We must store the front node in a temporary pointer, advance the `front` pointer, and delete the old node to avoid memory leaks. If the queue becomes empty after deletion, we also must reset `rear` to `NULL`.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Queue {
    Node *front;
    Node *rear;

    Queue() {
        front = NULL;
        rear = NULL;
        cout << "Linked List Queue initialized!\n";
    }

    void enqueue(int x) {
        Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL;

        if (front == NULL && rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Remove the front element - Time Complexity: O(1)
    int dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! Nothing to dequeue.\n";
            return -1;
        }

        Node *temp = front;        // Hold the current front node
        int dequeuedVal = temp->val; // Extract the value

        front = front->next;       // Move front pointer to the next node

        // If moving the front pointer made the queue empty, reset rear to NULL
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;               // Free the memory
        return dequeuedVal;
    }

    // Print elements from front to rear - Time Complexity: O(n)
    void printQueue() {
        if (front == NULL) {
            cout << "Queue is Empty!\n";
            return;
        }
        
        cout << "Queue (Front to Rear): ";
        Node *cur = front;
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

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    
    cout << "\nAfter enqueues:\n";
    q.printQueue(); // Expected: 5 <- 15 <- 25

    cout << "\nDequeued element: " << q.dequeue() << "\n"; // Removes 5
    
    cout << "\nAfter dequeue:\n";
    q.printQueue(); // Expected: 15 <- 25

    q.dequeue(); // Removes 15
    q.dequeue(); // Removes 25
    
    cout << "\nAfter dequeueing all elements:\n";
    q.printQueue(); // Expected: Queue is Empty!

    return 0;
}

```
