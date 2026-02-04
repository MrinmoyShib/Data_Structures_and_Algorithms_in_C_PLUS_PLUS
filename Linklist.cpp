#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *next;

  Node(int val) {
    value = val;
    next = NULL;
  }
};

void traverse(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->value << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void insertAtHead(Node *&head, int val) {
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void insertAtEnd(Node *&head, int val) {
  if (head == NULL) {
    insertAtHead(head, val);
    return;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new Node(val);
}

void insertByPos(Node *&head, int val, int pos) {
  if (pos <= 0)
    return;

  if (pos == 1) {
    insertAtHead(head, val);
    return;
  }

  Node *pre = head;
  int count = 1;

  while (count < pos - 1 && pre != NULL) {
    pre = pre->next;
    count++;
  }

  if (pre == NULL)
    return;

  Node *newNode = new Node(val);
  newNode->next = pre->next;
  pre->next = newNode;
}

void insertByVal(Node *&head, int target, int val) {
  Node *temp = head;

  while (temp != NULL && temp->value != target) {
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  Node *newNode = new Node(val);
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtStart(Node *&head) {
  if (head == NULL)
    return;

  Node *temp = head;
  head = head->next;
  delete temp;
}

void deleteAtEnd(Node *&head) {
  if (head == NULL)
    return;

  if (head->next == NULL) {
    deleteAtStart(head);
    return;
  }

  Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  delete temp->next;
  temp->next = NULL;
}

void deleteByPos(Node *&head, int pos) {
  if (head == NULL || pos <= 0)
    return;

  if (pos == 1) {
    deleteAtStart(head);
    return;
  }

  Node *pre = head;
  int count = 1;

  while (count < pos - 1 && pre != NULL) {
    pre = pre->next;
    count++;
  }

  if (pre == NULL || pre->next == NULL)
    return;

  Node *temp = pre->next;
  pre->next = temp->next;
  delete temp;
}

void deleteByVal(Node *&head, int value) {
  if (head == NULL)
    return;

  if (head->value == value) {
    deleteAtStart(head);
    return;
  }

  Node *pre = head;
  Node *temp = head->next;

  while (temp != NULL && temp->value != value) {
    pre = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  pre->next = temp->next;
  delete temp;
}

void updateNodeValue(Node *&head, int pos, int updatedvalue) {
  if (head == NULL || pos <= 0)
    return;

  Node *temp = head;
  int count = 1;

  while (count < pos && temp != NULL) {
    temp = temp->next;
    count++;
  }

  if (temp == NULL)
    return;

  temp->value = updatedvalue;
}

int main() {
  Node *head = NULL;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    insertAtEnd(head, val);
  }

  /*
  int values[] = {1, 2, 3, 4, 5};
  Node *head = NULL;

  for (int val : values) {
    insertAtEnd(head, val);
  }
  */

  /*
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *head = node1;
    */

  traverse(head);

  insertAtHead(head, 3);
  traverse(head);

  insertAtEnd(head, 4);
  traverse(head);

  insertByPos(head, 5, 2);
  traverse(head);

  insertByVal(head, 2, 3);
  traverse(head);

  deleteAtStart(head);
  traverse(head);

  deleteAtEnd(head);
  traverse(head);

  deleteByPos(head, 3);
  traverse(head);

  deleteByVal(head, 3);
  traverse(head);

  updateNodeValue(head, 1, 2);
  traverse(head);

  return 0;
}
