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
  delete temp;
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

int main() {
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  node1->next = node2;
  node2->next = node3;
  Node *head = node1;

  traverse(head);

  deleteAtEnd(head);
  traverse(head);
  return 0;
}