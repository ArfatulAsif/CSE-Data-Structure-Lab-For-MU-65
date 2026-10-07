# **Lab 4: Doubly Linked List**

---


## **Part 1: Defining the Node and Doubly Linked List Structure**

In a **Doubly Linked List (DLL)**, each node contains two pointers: `next` (pointing to the subsequent node) and `prev` (pointing to the preceding node). This allows bi-directional traversal (forward and backward).

```cpp
#include <iostream>
using namespace std;

// Structure for an individual node in a Doubly Linked List
struct node {
    int val;
    node *next;
    node *prev; // Pointer to the previous node
};

// Structure to manage the Doubly Linked List
struct DoublyLinkedList {
    node *head, *tail;

    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Doubly Linked List initialized!\n";
    }
};

int main() {
    // Creating the list object
    DoublyLinkedList dl;
    
    return 0;
}

```

**Key Concepts:**

* **`prev` pointer:** Points to the previous node in the list. For the `head` node, `head->prev` is always `NULL`.
* **`next` pointer:** Points to the next node in the list. For the `tail` node, `tail->next` is always `NULL`.
* **Two-way linkage:** When linking two nodes `A` and `B`, you must update both `A->next = B` and `B->prev = A`.

---

## **Part 2: Base Operations (Enqueue at Tail, Enqueue at Head & Bi-directional Print)**

We add the ability to append elements at the end (`enqueue`) while maintaining both `next` and `prev` pointers. We also add forward (`printListForward`) and reverse (`printListReverse`) printing to demonstrate bi-directional traversal.

```cpp
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node *prev;
};

struct DoublyLinkedList {
    node *head, *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Doubly Linked List initialized!\n";
    }

    // Insert element AFTER the tail - Time Complexity: O(1)
    void enqueueTail(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        cur->prev = NULL;

        if (head == NULL && tail == NULL) { // Empty list
            head = tail = cur;
            return;
        }

        tail->next = cur; // Link old tail forward to new node
        cur->prev = tail; // Link new node backward to old tail
        tail = cur;       // Move tail pointer to new node
    }

    // Insert element BEFORE the head - Time Complexity: O(1)
    void enqueueHead(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        cur->prev = NULL;

        if (head == NULL && tail == NULL) { // Empty list
            head = tail = cur;
            return;
        }

        cur->next = head; // Link new node forward to current head
        head->prev = cur; // Link current head backward to new node
        head = cur;       // Move head pointer to new node
    }

    // Print from head to tail - Time Complexity: O(n)
    void printListForward() {
        cout << "Forward:  NULL <- ";
        node *cur = head;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->next != NULL) cout << " <-> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }

    // Print from tail to head - Time Complexity: O(n)
    void printListReverse() {
        cout << "Reverse:  NULL <- ";
        node *cur = tail;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->prev != NULL) cout << " <-> ";
            cur = cur->prev;
        }
        cout << " -> NULL\n";
    }
};

int main() {
    DoublyLinkedList dl;

    // Test Enqueue at Tail
    dl.enqueueTail(20);
    dl.enqueueTail(30);

    // Test Enqueue at Head
    dl.enqueueHead(10);
    dl.enqueueHead(5);

    // Expected List: 5 <-> 10 <-> 20 <-> 30
    dl.printListForward(); // Output: NULL <- 5 <-> 10 <-> 20 <-> 30 -> NULL
    dl.printListReverse(); // Output: NULL <- 30 <-> 20 <-> 10 <-> 5 -> NULL

    return 0;
}

```

---

## **Part 3: Adding Insertion Functions**

We expand the class to handle insertions: immediately after the head, immediately before the tail, and after a specific value. Every insertion must explicitly update up to 4 pointer links (`next` and `prev` for both surrounding nodes).

```cpp
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node *prev;
};

struct DoublyLinkedList {
    node *head, *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Doubly Linked List initialized!\n";
    }

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        cur->prev = NULL;

        if (head == NULL && tail == NULL) {
            head = tail = cur;
            return;
        }

        tail->next = cur;
        cur->prev = tail;
        tail = cur;
    }

    void printListForward() {
        cout << "Forward:  NULL <- ";
        node *cur = head;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->next != NULL) cout << " <-> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }

    void printListReverse() {
        cout << "Reverse:  NULL <- ";
        node *cur = tail;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->prev != NULL) cout << " <-> ";
            cur = cur->prev;
        }
        cout << " -> NULL\n";
    }

    // Insert a new node right after head node - Time Complexity: O(1)
    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = head->next;
        cur->prev = head;

        if (head->next != NULL) {
            head->next->prev = cur;
        } else {
            tail = cur; // If head was also tail, update tail pointer
        }

        head->next = cur;
    }

    // Insert a new node right before tail node - Time Complexity: O(1)
    void insertBeforeTail(int x) {
        if (tail == NULL || head == tail) {
            // Empty or single element list
            node *cur = new node;
            cur->val = x;
            cur->next = head;
            cur->prev = NULL;

            if (head != NULL) head->prev = cur;
            head = cur;
            if (tail == NULL) tail = cur;
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        cur->prev = tail->prev;

        tail->prev->next = cur;
        tail->prev = cur;
    }

    // Insert 'toAdd' right after target value 'toFind' - Time Complexity: O(n)
    void insertAfterVal(int toFind, int toAdd) {
        node *cur = head;
        while (cur != NULL && cur->val != toFind) {
            cur = cur->next;
        }

        if (cur != NULL) {
            node *newNode = new node;
            newNode->val = toAdd;
            newNode->next = cur->next;
            newNode->prev = cur;

            if (cur->next != NULL) {
                cur->next->prev = newNode;
            } else {
                tail = newNode; // Inserting after tail updates tail pointer
            }

            cur->next = newNode;
        } else {
            cout << "Value " << toFind << " not found!\n";
        }
    }
};

int main() {
    DoublyLinkedList dl;

    dl.enqueue(10);
    dl.enqueue(20);
    dl.enqueue(30);
    cout << "After enqueue: \n";
    dl.printListForward();

    dl.insertAfterHead(15);
    cout << "\nAfter insertAfterHead(15): \n";
    dl.printListForward();

    dl.insertBeforeTail(25);
    cout << "\nAfter insertBeforeTail(25): \n";
    dl.printListForward();

    dl.insertAfterVal(15, 17);
    cout << "\nAfter insertAfterVal(15, 17): \n";
    dl.printListForward();
    dl.printListReverse();

    return 0;
}

```


---

## **Part 4: Adding Deletion Functions (Complete Program)**

Notice the advantage of a Doubly Linked List when deleting the tail: `deleteTail()` is **$\mathcal{O}(1)$** instead of $\mathcal{O}(n)$ (which required traversal in a Singly Linked List) because `tail->prev` directly accesses the second-to-last node.

```cpp
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node *prev;
};

struct DoublyLinkedList {
    node *head, *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        cout << "Doubly Linked List initialized!\n";
    }

    void enqueue(int x) {
        node *cur = new node;
        cur->val = x;
        cur->next = NULL;
        cur->prev = NULL;

        if (head == NULL && tail == NULL) {
            head = tail = cur;
            return;
        }

        tail->next = cur;
        cur->prev = tail;
        tail = cur;
    }

    void printListForward() {
        cout << "Forward:  NULL <- ";
        node *cur = head;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->next != NULL) cout << " <-> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }

    void printListReverse() {
        cout << "Reverse:  NULL <- ";
        node *cur = tail;
        if (cur == NULL) {
            cout << "List is Empty!\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val;
            if (cur->prev != NULL) cout << " <-> ";
            cur = cur->prev;
        }
        cout << " -> NULL\n";
    }

    void insertAfterHead(int x) {
        if (head == NULL) {
            enqueue(x);
            return;
        }
        node *cur = new node;
        cur->val = x;
        cur->next = head->next;
        cur->prev = head;

        if (head->next != NULL) {
            head->next->prev = cur;
        } else {
            tail = cur;
        }
        head->next = cur;
    }

    void insertBeforeTail(int x) {
        if (tail == NULL || head == tail) {
            node *cur = new node;
            cur->val = x;
            cur->next = head;
            cur->prev = NULL;

            if (head != NULL) head->prev = cur;
            head = cur;
            if (tail == NULL) tail = cur;
            return;
        }

        node *cur = new node;
        cur->val = x;
        cur->next = tail;
        cur->prev = tail->prev;

        tail->prev->next = cur;
        tail->prev = cur;
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
            newNode->prev = cur;

            if (cur->next != NULL) {
                cur->next->prev = newNode;
            } else {
                tail = newNode;
            }
            cur->next = newNode;
        } else {
            cout << "Value " << toFind << " not found!\n";
        }
    }

    // Removes the head node - Time Complexity: O(1)
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
            head->prev = NULL; // New head's prev must be NULL
        }

        delete cur;
        return x;
    }

    // Removes the tail node - Time Complexity: O(1) [Unlike Singly Linked List O(n)]
    int deleteTail() {
        if (tail == NULL) {
            cout << "Underflow!\n";
            return -1;
        }

        node *cur = tail;
        int x = cur->val;

        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev; // Move tail back using prev pointer
            tail->next = NULL; // New tail's next must be NULL
        }

        delete cur;
        return x;
    }

    // Removes the node immediately following the head node - Time Complexity: O(1)
    int deleteValAfterHead() {
        if (head == NULL || head->next == NULL) {
            cout << "No node exists after head!\n";
            return -1;
        }

        node *toDelete = head->next;
        int val = toDelete->val;

        head->next = toDelete->next;

        if (toDelete->next != NULL) {
            toDelete->next->prev = head;
        } else {
            tail = head; // If we deleted the tail node
        }

        delete toDelete;
        return val;
    }
};

int main() {
    DoublyLinkedList dl;

    dl.enqueue(10);
    dl.enqueue(20);
    dl.enqueue(30);

    dl.insertAfterHead(15);
    dl.insertBeforeTail(25);
    
    cout << "List before deletions:\n";
    dl.printListForward(); // Expected: NULL <- 10 <-> 15 <-> 20 <-> 25 <-> 30 -> NULL

    dl.dequeue();
    cout << "\nAfter dequeue (delete head):\n";
    dl.printListForward(); // Expected: NULL <- 15 <-> 20 <-> 25 <-> 30 -> NULL

    dl.deleteTail();
    cout << "\nAfter deleteTail (O(1) operation):\n";
    dl.printListForward(); // Expected: NULL <- 15 <-> 20 <-> 25 -> NULL

    dl.deleteValAfterHead();
    cout << "\nAfter deleteValAfterHead:\n";
    dl.printListForward(); // Expected: NULL <- 15 <-> 25 -> NULL
    dl.printListReverse(); // Expected: NULL <- 25 <-> 15 -> NULL

    return 0;
}

```

