#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;
  Node *prev;

  Node(int val) {
    value = val;
    next = NULL;
    prev = NULL;
  }
};

class DoublyLinkedList {
private:
  Node *head;

public:
  DoublyLinkedList() { head = NULL; }

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

  void traverseBackward() {
    if (head == NULL)
      return;
    Node *temp = head;

    while (temp->next != NULL) {
      temp = temp->next;
    }
    cout << "Backward: NULL->";

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

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
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

    temp->next = newNode;
    newNode->prev = temp;
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

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
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
      head->prev = NULL;
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

    temp->prev->next = NULL;
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
    }

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