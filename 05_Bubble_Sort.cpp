#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;

void bubble_sort(int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        swap(vec[j], vec[j + 1]);
      }
    }
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

  bubble_sort(vec.size());
  print_sort(vec.size());
}