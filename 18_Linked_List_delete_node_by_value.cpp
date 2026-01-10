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

int main() {
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  node1->next = node2;
  node2->next = node3;
  Node *head = node1;

  traverse(head);

  insertByVal(head, 3);
  traverse(head);

  return 0;
}