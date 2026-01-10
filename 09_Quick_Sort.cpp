#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int partition(vector<int> &vec, int start, int end) {
  int idx = start - 1, pivot = vec[end];

  for (int i = start; i < end; i++) {
    if (vec[i] < pivot) {
      idx++;
      swap(vec[i], vec[idx]);
    }
  }
  idx++;
  swap(vec[end], vec[idx]);
  return idx;
}

void Quick_sort(vector<int> &vec, int start, int end) {
  if (start < end) {
    int pivotIdx = partition(vec, start, end);
    Quick_sort(vec, start, pivotIdx - 1);
    Quick_sort(vec, pivotIdx + 1, end);
  }
}

int main() {
  int n;
  cout << "Enter the array size : ";
  cin >> n;

  cout << "Enter the array : ";
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  Quick_sort(vec, 0, vec.size() - 1);

  for (int val : vec) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}