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

void insertByVal(Node *&head, int target, int val) {
  Node *newNode = new Node(val);
  Node *pre = head;

  while (pre != NULL && pre->value != target) {
    pre = pre->next;
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

  insertByVal(head, 2, 4);
  traverse(head);

  return 0;
}