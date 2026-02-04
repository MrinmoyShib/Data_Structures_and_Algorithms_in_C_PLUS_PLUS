#include <bits/stdc++.h>
using namespace std;

// 1. Node Structure: Updated for Doubly Linked List
struct Node {
  int value;
  Node *next;
  Node *prev; // NEW: Pointer to the previous node

  Node(int val) {
    value = val;
    next = NULL;
    prev = NULL; // Initialize prev to NULL
  }
};

// 2. Class: Manages the Doubly Linked List
class DoublyLinkedList {
private:
  Node *head;

public:
  DoublyLinkedList() { head = NULL; }

  // Destructor: Cleans up memory automatically
  ~DoublyLinkedList() {
    while (head != NULL) {
      deleteAtStart();
    }
  }

  // --- Traversal ---
  void traverse() {
    Node *temp = head;
    cout << "Forward:  NULL->";
    while (temp != NULL) {
      cout << temp->value << "<->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  // NEW: Backward Traversal (Bonus feature of DLL)
  void traverseBackward() {
    if (head == NULL)
      return;
    Node *temp = head;
    // Go to the last node
    while (temp->next != NULL) {
      temp = temp->next;
    }
    cout << "Backward: NULL->";
    // Walk backwards
    while (temp != NULL) {
      cout << temp->value << "<->";
      temp = temp->prev;
    }
    cout << "NULL" << endl;
  }

  // --- Insertion Methods ---
  void insertAtHead(int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
      head = newNode;
      return;
    }

    newNode->next = head; // 1. New node points forward to head
    head->prev = newNode; // 2. Old head points backward to new node
    head = newNode;       // 3. Update head
  }

  void insertAtEnd(int val) {
    if (head == NULL) {
      insertAtHead(val);
      return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = newNode; // 1. Last node points to new node
    newNode->prev = temp; // 2. New node points back to last node
  }

  void insertByPos(int val, int pos) {
    if (pos <= 0) {
      return;
    }
    if (pos == 1) {
      insertAtHead(val);
      return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp != NULL) {
      temp = temp->next;
      count++;
    }

    if (temp == NULL) {
      return;
    }

    Node *newNode = new Node(val);

    // Linking logic
    newNode->next = temp->next; // New node points to next neighbor
    newNode->prev = temp;       // New node points back to current node

    if (temp->next != NULL) {     // If there is a next neighbor...
      temp->next->prev = newNode; // ...tell it to point back to new node
    }
    temp->next = newNode; // Current node points to new node
  }

  void insertByVal(int target, int val) {
    Node *temp = head;
    while (temp != NULL && temp->value != target) {
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    } // Target not found

    Node *newNode = new Node(val);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
  }

  // --- Deletion Methods ---
  void deleteAtStart() {
    if (head == NULL) {
      return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL) {
      head->prev = NULL; // Important: New head has no previous node
    }

    delete temp;
  }

  void deleteAtEnd() {
    if (head == NULL) {
      return;
    }

    if (head->next == NULL) {
      deleteAtStart();
      return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }

    // temp is now the last node
    temp->prev->next =
        NULL; // Tell the 2nd to last node to forget the last node
    delete temp;
  }

  void deleteByPos(int pos) {
    if (head == NULL || pos <= 0) {
      return;
    }
    if (pos == 1) {
      deleteAtStart();
      return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos && temp != NULL) {
      temp = temp->next;
      count++;
    }

    if (temp == NULL) {
      return;
    }

    // temp is the node to delete. We just link its neighbors.
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
      temp->next->prev = temp->prev;
    }

    delete temp;
  }

  void deleteByVal(int value) {
    if (head == NULL) {
      return;
    }

    if (head->value == value) {
      deleteAtStart();
      return;
    }

    Node *temp = head;
    while (temp != NULL && temp->value != value) {
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    } // Value not found

    // Link neighbors
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
      temp->next->prev = temp->prev;
    }

    delete temp;
  }

  // --- Update Method ---
  void updateNodeValue(int pos, int updatedvalue) {
    if (head == NULL || pos <= 0) {
      return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos && temp != NULL) {
      temp = temp->next;
      count++;
    }

    if (temp == NULL) {
      return;
    }

    temp->value = updatedvalue;
  }
};

int main() {
  DoublyLinkedList list;

  int n;
  cout << "Enter number of nodes: ";
  cin >> n;

  cout << "Enter values: ";
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    list.insertAtEnd(val);
  }

  cout << "Initial List: " << endl;
  list.traverse();

  cout << "\n--- Insertion Tests ---" << endl;
  list.insertAtHead(3);
  cout << "After insertAtHead(3): ";
  list.traverse();

  list.insertAtEnd(4);
  cout << "After insertAtEnd(4): ";
  list.traverse();

  list.insertByPos(5, 2);
  cout << "After insertByPos(5, 2): ";
  list.traverse();

  list.insertByVal(2, 7);
  cout << "After insertByVal(2, 3): ";
  list.traverse();

  cout << "\n--- Deletion Tests ---" << endl;
  list.deleteAtStart();
  cout << "After deleteAtStart(): ";
  list.traverse();

  list.deleteAtEnd();
  cout << "After deleteAtEnd(): ";
  list.traverse();

  list.deleteByPos(3);
  cout << "After deleteByPos(3): ";
  list.traverse();

  list.deleteByVal(3);
  cout << "After deleteByVal(3): ";
  list.traverse();

  cout << "\n--- Update Test ---" << endl;
  list.updateNodeValue(1, 2);
  cout << "After updateNodeValue(1, 2): ";
  list.traverse();

  // Bonus: Prove it works backwards
  cout << "\n--- Reverse Traversal Check ---" << endl;
  list.traverseBackward();

  return 0;
}