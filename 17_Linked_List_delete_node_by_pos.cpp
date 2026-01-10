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

void deleteAtStart(Node *&head) {
  if (head == NULL) {
    return;
  }

  Node *temp = head;
  head = head->next;
  free(temp);
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

int main() {
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  node1->next = node2;
  node2->next = node3;
  Node *head = node1;

  traverse(head);

  deleteByPos(head, 2);
  traverse(head);

  return 0;
}