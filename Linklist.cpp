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

  Node *newNode = new Node(val);
  Node *temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
}

void insertByPos(Node *&head, int val, int pos) {
  if (pos == 1) {
    insertAtHead(head, val);
    return;
  }

  Node *newNode = new Node(val);
  Node *pre = head;
  int count = 1;

  while (count < pos - 1) {
    pre = pre->next;
    count++;
  }

  newNode->next = pre->next;
  pre->next = newNode;
}

void insertByVal(Node *&head, int target, int val) {
  Node *newNode = new Node(val);
  Node *pre = head;

  while (pre != NULL && pre->value != target) {
    pre = pre->next;
  }

  newNode->next = pre->next;
  pre->next = newNode;
}

void deleteAtStart(Node *&head) {
  if (head == NULL) {
    return;
  }

  Node *temp = head;
  head = head->next;
  free(temp);
}

void deleteAtEnd(Node *&head) {
  if (head == NULL) {
    return;
  }
  if (head->next == NULL) {
    deleteAtStart(head);
    return;
  }

  Node *secondlast = head;
  while (secondlast->next->next != NULL) {
    secondlast = secondlast->next;
  }

  Node *last = secondlast->next;
  secondlast->next = NULL;
  free(last);
}

void deleteByPos(Node *&head, int pos) {
  if (pos == 1) {
    deleteAtStart(head);
    return;
  }

  Node *pre = head;
  int count = 1;

  while (count < pos - 1) {
    pre = pre->next;
    count++;
  }

  Node *curr = pre->next;
  pre->next = pre->next->next;
  free(curr);
}

void insertByVal(Node *&head, int value) {
  Node *pre = NULL;
  Node *temp = head;

  while (temp != NULL && temp->value != value) {
    pre = temp;
    temp = temp->next;
  }

  pre->next = temp->next;
  free(temp);
}

void updateNodeValur(Node *&head, int pos, int updatedvalue) {
  Node *temp = head;
  int count = 1;

  while (count < pos) {
    temp = temp->next;
    count++;
  }

  temp->value = updatedvalue;
}

int main() {

  Node *head = NULL;

  int n;
  cout << "How many nodes? ";
  cin >> n;

  cout << "Enter " << n << " values: ";
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    insertAtEnd(head, val);
  }

  cout << "Your linked list: ";
  traverse(head);
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

  insertByVal(head, 3);
  traverse(head);

  updateNodeValur(head, 1, 2);
  traverse(head);

  return 0;
}