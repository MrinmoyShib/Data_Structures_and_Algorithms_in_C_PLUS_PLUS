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

int main() {
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  node1->next = node2;
  node2->next = node3;
  Node *head = node1;

  traverse(head);

  insertByPos(head, 5, 2);
  traverse(head);

  return 0;
}