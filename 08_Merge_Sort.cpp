#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

void merge(vector<int> &vec, int start, int mid, int end) {
  vector<int> temp;
  int i = start;
  int j = mid + 1;

  while (i <= mid && j <= end) {
    if (vec[i] <= vec[j]) {
      temp.push_back(vec[i]);
      i++;
    } else {
      temp.push_back(vec[j]);
      j++;
    }
  }

  while (i <= mid) {
    temp.push_back(vec[i]);
    i++;
  }
  while (j <= end) {
    temp.push_back(vec[j]);
    j++;
  }

  for (int i = 0; i < temp.size(); i++) {
    vec[i + start] = temp[i];
  }
}

void merge_sort(vector<int> &vec, int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;

    merge_sort(vec, start, mid);
    merge_sort(vec, mid + 1, end);

    merge(vec, start, mid, end);
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

  merge_sort(vec, 0, vec.size() - 1);

  for (int val : vec) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
