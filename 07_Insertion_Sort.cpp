#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;

void insertion_sort(int n) {
  for (int i = 1; i < n; i++) {
    int current = vec[i];
    int previous = i - 1;
    while (previous >= 0 && vec[previous] > current) {
      vec[previous + 1] = vec[previous];
      previous--;
    }
    vec[previous + 1] = current;
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

  insertion_sort(vec.size());
  print_sort(vec.size());
}
