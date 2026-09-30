# Lab 3: Singly Linked List 



## **Part 1: Defining the Node and Linked List Structure**

This is the starting point. We define the `node` structure, the `SinglyLinkedList` class, and a constructor. You can compile and run this to ensure your basic memory structure is set up correctly.

```cpp
#include <iostream>
using namespace std;

// Structure for an individual node
struct node {
    int val;
    node *next;
};

// Class/Structure to manage the Linked List
struct SinglyLinkedList {
    node *head, *tail;

    // Constructor to initialize an empty list
    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Singly Linked List initialized!\n";
    }
};

int main() {
    // Creating the list object
    SinglyLinkedList sl;
    
    return 0;
}

```

**Key Concepts:**

* **`node`**: Contains `val` (data) and a self-referential pointer `next` that points to another `node` structure.
* **`head`** & **`tail`**: Point to the first and last nodes. When both are `NULL`, the list is empty.

---

## **Part 2: Adding Base Operations (Enqueue & Print)**

We add the ability to insert elements at the end (`enqueue`) and traverse the list to view the elements (`printList`). The `main` function is updated to test these additions.

```cpp
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

struct SinglyLinkedList {
    node *head, *tail;

    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Singly Linked List initialized!\n";
    }

    // Time Complexity: O(1)
    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;

        if (head == NULL && tail == NULL) { // Empty list
            head = tail = cur;
            return;
        }
        
        tail->next = cur; // Link old tail to new node
        tail = cur;       // Update tail pointer
    }

    // Time Complexity: O(n)
    void printList() {
        cout << "SinglyLinkedList: ";
        node *cur = head;
        
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        
        while (cur != NULL) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sl;

    // Test Enqueue
    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);
    
    // Test Print
    sl.printList(); // Expected: 10 -> 20 -> 30 -> NULL
    
    return 0;
}

```

---

## **Part 3: Adding Insertion Functions**

We expand the class to handle specific insertion scenarios: immediately after the head, immediately before the tail, and after a specific value. The `main` function now tests all insertion types.

```cpp
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

struct SinglyLinkedList {
    node *head, *tail;

    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Singly Linked List initialized!\n";
    }

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        if (head == NULL && tail == NULL) {
            head = tail = cur;
            return;
        }
        tail->next = cur;
        tail = cur;
    }

    void printList() {
        cout << "SinglyLinkedList: ";
        node *cur = head;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    // Insert a new value right after the head node
    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = head->next; 
        head->next = cur;       
        
        if (head == tail) { 
            tail = cur;
        }
    }

    // Insert a value right before the tail node
    void insertBeforeTail(int x) {
        if (head == NULL || head == tail) {
            node *cur = new node;
            cur->val = x;
            cur->next = head;
            head = cur;
            if (tail == NULL) tail = cur;
            return;
        }
        node *prev = head;
        while (prev->next != tail) { 
            prev = prev->next;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        prev->next = cur;
    }

    // Insert 'toAdd' right after 'toFind'
    void insertAfterVal(int toFind, int toAdd) {
        node *cur = head;
        while (cur != NULL && cur->val != toFind) {
            cur = cur->next;
        }
        if (cur != NULL) {
            node *newNode = new node;
            newNode->val = toAdd;
            newNode->next = cur->next;
            cur->next = newNode;
            if (cur == tail) tail = newNode; 
        } else {
            cout << "Value " << toFind << " not found!\n";
        }
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);
    cout << "After enqueue: ";
    sl.printList(); 

    sl.insertAfterHead(15);
    cout << "After insertAfterHead(15): ";
    sl.printList(); 

    sl.insertBeforeTail(25);
    cout << "After insertBeforeTail(25): ";
    sl.printList(); 

    sl.insertAfterVal(15, 17);
    cout << "After insertAfterVal(15, 17): ";
    sl.printList(); 

    return 0;
}

```

---

## **Part 4: Adding Deletion Functions (Complete Program)**

Finally, we add the deletion operations. Memory management is critical here—we must use the `delete` keyword to free dynamic memory and prevent memory leaks. The `main` function now demonstrates the full lifecycle of the list.

```cpp
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

struct SinglyLinkedList {
    node *head, *tail;

    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Singly Linked List initialized!\n";
    }

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        if (head == NULL && tail == NULL) {
            head = tail = cur;
            return;
        }
        tail->next = cur;
        tail = cur;
    }

    void printList() {
        cout << "SinglyLinkedList: ";
        node *cur = head;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = head->next;
        head->next = cur;
        if (head == tail) tail = cur;
    }

    void insertBeforeTail(int x) {
        if (head == NULL || head == tail) {
            node *cur = new node;
            cur->val = x;
            cur->next = head;
            head = cur;
            if (tail == NULL) tail = cur;
            return;
        }
        node *prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        prev->next = cur;
    }

    void insertAfterVal(int toFind, int toAdd) {
        node *cur = head;
        while (cur != NULL && cur->val != toFind) {
            cur = cur->next;
        }
        if (cur != NULL) {
            node *newNode = new node;
            newNode->val = toAdd;
            newNode->next = cur->next;
            cur->next = newNode;
            if (cur == tail) tail = newNode;
        } else {
            cout << "Value " << toFind << " not found!\n";
        }
    }

    // Removes the first node and frees its memory
    int dequeue() {
        if (head == NULL) {
            cout << "Underflow!\n";
            return -1;
        }
        node *cur = head;
        int x = cur->val;

        if (head == tail) { 
            head = tail = NULL;
        } else {
            head = head->next; 
        }

        delete cur; 
        return x;
    }

    // Traverses to find the second-to-last node, updates tail, deletes old tail
    int deleteTail() {
        if (head == NULL) {
            cout << "Underflow!\n";
            return -1;
        }
        if (head == tail) { 
            int val = head->val;
            delete head;
            head = tail = NULL;
            return val;
        }

        node *prev = head;
        while (prev->next != tail) { 
            prev = prev->next;
        }

        int val = tail->val;
        delete tail;
        tail = prev;
        tail->next = NULL;

        return val;
    }

    // Removes the node immediately following the head
    int deleteValAfterHead() {
        if (head == NULL || head->next == NULL) {
            cout << "No node exists after head!\n";
            return -1;
        }
        node *toDelete = head->next;
        int val = toDelete->val;

        head->next = toDelete->next; 
        
        if (toDelete == tail) { 
            tail = head;
        }

        delete toDelete;
        return val;
    }
};

int main() {
    SinglyLinkedList sl;

    sl.enqueue(10);
    sl.enqueue(20);
    sl.enqueue(30);
    
    sl.insertAfterHead(15);
    sl.insertBeforeTail(25);
    cout << "List before deletions: ";
    sl.printList(); // Expected: 10 -> 15 -> 20 -> 25 -> 30 -> NULL

    sl.dequeue();
    cout << "After dequeue (delete head): ";
    sl.printList(); // Expected: 15 -> 20 -> 25 -> 30 -> NULL

    sl.deleteTail();
    cout << "After deleteTail: ";
    sl.printList(); // Expected: 15 -> 20 -> 25 -> NULL

    sl.deleteValAfterHead();
    cout << "After deleteValAfterHead: ";
    sl.printList(); // Expected: 15 -> 25 -> NULL

    return 0;
}

```
