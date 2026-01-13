#include <bits/stdtr1c++.h>
using namespace std;

struct Node {
  int value;
  Node *next;
};

Node *root = NULL;

void printLinklist() {
  if (root == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  Node *temp = root;
  while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtStart(int val) {
  Node *newNode = new Node();
  newNode->value = val;
  newNode->next = root;
  root = newNode;
}

void insertAtEnd(int val) {
  Node *newNode = new Node();
  newNode->value = val;
  newNode->next = NULL;

  if (root == NULL) {
    root = newNode;
  } else {
    Node *temp = root;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void insertByPosition(int pos, int val) {
  if (pos <= 0) {
    cout << "Invalid position!" << endl;
    return;
  }

  if (pos == 1) {
    insertAtStart(val);
    return;
  }

  Node *temp = root;
  for (int i = 1; i < pos - 1 && temp != NULL; ++i) {
    temp = temp->next;
  }

  if (temp == NULL) {
    cout << "Position out of range!" << endl;
    return;
  }

  Node *newNode = new Node();
  newNode->value = val;
  newNode->next = temp->next;
  temp->next = newNode;
}

void insertAfterValue(int target, int val) {
  if (root == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  Node *temp = root;
  while (temp != NULL && temp->value != target) {
    temp = temp->next;
  }

  if (temp == NULL) {
    cout << "Value " << target << " not found!" << endl;
    return;
  }

  Node *newNode = new Node();
  newNode->value = val;
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtStart() {
  if (root == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  Node *toDelete = root;
  root = root->next;
  delete toDelete;
}

void deleteAtEnd() {
  if (root == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  if (root->next == NULL) {
    delete root;
    root = NULL;
    return;
  }

  Node *temp = root;
  Node *pre = NULL;

  while (temp->next != NULL) {
    pre = temp;
    temp = temp->next;
  }

  pre->next = NULL;
  delete temp;
}

void deleteByPosition(int pos) {
  if (pos <= 0 || root == NULL) {
    cout << "Invalid position or empty list!" << endl;
    return;
  }

  if (pos == 1) {
    deleteAtStart();
    return;
  }

  Node *temp = root;
  for (int i = 1; i < pos - 1 && temp != NULL; ++i) {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL) {
    cout << "Position out of range!" << endl;
    return;
  }

  Node *toDelete = temp->next;
  temp->next = toDelete->next;
  delete toDelete;
}

void deleteByValue(int val) {
  if (root == NULL) {
    cout << "List is empty!" << endl;
    return;
  }

  if (root->value == val) {
    deleteAtStart();
    return;
  }

  Node *temp = root;
  while (temp->next != NULL && temp->next->value != val) {
    temp = temp->next;
  }

  if (temp->next == NULL) {
    cout << "Value " << val << " not found!" << endl;
    return;
  }

  Node *toDelete = temp->next;
  temp->next = toDelete->next;
  delete toDelete;
}

void clearList() {
  while (root != nullptr) {
    Node *temp = root;
    root = root->next;
    delete temp;
  }
}

int main() {
  int n;
  cout << "Enter the number of nodes : ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cout << "Enter node " << i + 1 << " value :";
    cin >> val;
    insertAtEnd(val);
  }

  printLinklist();

  insertAtStart(7);
  printLinklist();

  insertAtEnd(6);
  printLinklist();

  insertByPosition(3, 26);
  printLinklist();

  deleteAtStart();
  printLinklist();

  deleteAtEnd();
  printLinklist();

  deleteByPosition(2);
  printLinklist();

  deleteByValue(3);
  printLinklist();

  clearList();

  return 0;
}