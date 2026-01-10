#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;

void selection_sort(int n) {
  for (int i = 0; i < n - 1; i++) {
    int smallestIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (vec[j] < vec[smallestIndex]) {
        smallestIndex = j;
      }
    }
    swap(vec[i], vec[smallestIndex]);
  }
}

void print_sort(int n) {
  for (int i = 0; i < n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main() {
  int x;
  cout << "Enter array size : ";
  cin >> n;
  cout << "Enter a unsorted array : ";

  for (int i = 0; i < n; i++) {
    cin >> x;
    vec.push_back(x);
  }

  selection_sort(vec.size());
  print_sort(vec.size());
}
