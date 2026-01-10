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
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  node1->next = node2;
  node2->next = node3;
  Node *head = node1;

  traverse(head);

  updateNodeValur(head, 3, 4);
  traverse(head);

  return 0;
}