#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int n;

int Lower_Bound(int val) {
  int low = 0, high = n - 1;

  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (vec[mid] == val) {
      ans = mid;
      high = mid - 1;
    }

    else if (vec[mid] > val) {
      ans = mid;
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return ans;
}
int main() {
  int x, y;

  cout << "Enter the Array size: ";
  cin >> n;

  cout << "Enter the array (must be sorted): ";
  for (int i = 0; i < n; i++) {
    cin >> x;
    vec.push_back(x);
  }

  cout << "Enter search element: ";
  cin >> y;

  int l1 = Lower_Bound(y); // first index >= y
  int l2 = l1 - 1;         // element just smaller than y
  int result;

  // Edge cases
  if (l1 >= n) {       // y is larger than all elements
    result = l2;       // pick the last element
  } else if (l2 < 0) { // y is smaller than all elements
    result = l1;       // pick the first element
  } else {
    int r1 = abs(vec[l1] - y);
    int r2 = abs(vec[l2] - y);

    if (r1 > r2) {
      result = l2;
    } else if (r1 == r2) {
      result = l2; // choose smaller element if tie
    } else {
      result = l1;
    }
  }
  cout << "The nearest is : " << vec[result];

  return 0;
}
