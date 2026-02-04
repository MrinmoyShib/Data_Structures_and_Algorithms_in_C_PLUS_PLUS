#include <bits/stdc++.h>
using namespace std;

// 1. Node Structure: Defines what a "Node" looks like
struct Node {
  int value;
  Node *next;

  Node(int val) {
    value = val;
    next = NULL;
  }
};

// 2. LinkedList Class: Manages the 'head' and all operations
class LinkedList {
private:
  Node *head;

public:
  // Constructor: Automatically runs when you create the list
  LinkedList() { head = NULL; }

  // Destructor: Automatically cleans up memory when the program ends
  ~LinkedList() {
    while (head != NULL) {
      deleteAtStart();
    }
  }

  // --- Traversal ---
  void traverse() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->value << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  // --- Insertion Methods ---
  void insertAtHead(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(int val) {
    if (head == NULL) {
      insertAtHead(val);
      return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = new Node(val);
  }

  void insertByPos(int val, int pos) {
    if (pos <= 0) {
      return;
    }

    if (pos == 1) {
      insertAtHead(val);
      return;
    }

    Node *pre = head;
    int count = 1;

    while (count < pos - 1 && pre != NULL) {
      pre = pre->next;
      count++;
    }

    if (pre == NULL) {
      return;
    }

    Node *newNode = new Node(val);
    newNode->next = pre->next;
    pre->next = newNode;
  }

  void insertByVal(int target, int val) {
    Node *temp = head;

    while (temp != NULL && temp->value != target) {
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // --- Deletion Methods ---
  void deleteAtStart() {
    if (head == NULL) {
      return;
    }

    Node *temp = head;
    head = head->next;
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
    while (temp->next->next != NULL) {
      temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
  }

  void deleteByPos(int pos) {
    if (head == NULL || pos <= 0) {
      return;
    }

    if (pos == 1) {
      deleteAtStart();
      return;
    }

    Node *pre = head;
    int count = 1;

    while (count < pos - 1 && pre != NULL) {
      pre = pre->next;
      count++;
    }

    if (pre == NULL || pre->next == NULL) {
      return;
    }

    Node *temp = pre->next;
    pre->next = temp->next;
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

    Node *pre = head;
    Node *temp = head->next;

    while (temp != NULL && temp->value != value) {
      pre = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }

    pre->next = temp->next;
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
  // 1. Create the Object
  LinkedList list;

  int n;
  cout << "Enter number of nodes: ";
  cin >> n;

  cout << "Enter values: ";
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    list.insertAtEnd(val); // Notice: we don't pass 'head' anymore
  }

  cout << "Initial List: ";
  list.traverse();

  // 2. Call methods using the dot (.) operator
  list.insertAtHead(3);
  cout << "After insertAtHead(3): ";
  list.traverse();

  list.insertAtEnd(4);
  cout << "After insertAtEnd(4): ";
  list.traverse();

  list.insertByPos(5, 2); // Insert 5 at position 2
  cout << "After insertByPos(5, 2): ";
  list.traverse();

  list.insertByVal(2, 3); // Insert 3 after finding 2
  cout << "After insertByVal(2, 3): ";
  list.traverse();

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

  list.updateNodeValue(1, 2); // upvate value at position 1
  cout << "After updateNodeValue(1, 2): ";
  list.traverse();

  return 0;
}