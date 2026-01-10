#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int n;

// -----------------------------------------------------------
// Custom implementation of lower_bound()
// Returns the first index where vec[index] >= val
// Assumes that the array is sorted in non-decreasing order
// -----------------------------------------------------------
int Lower_Bound(int val) {
  int low = 0, high = n - 1;

  // Default answer = n (means: val goes at the end)
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2; // middle index

    // Case 1: found val, but move LEFT to find first occurrence
    if (vec[mid] == val) {
      ans = mid;
      high = mid - 1; // check earlier positions
    }
    // Case 2: mid value is greater → potential answer
    else if (vec[mid] > val) {
      ans = mid;      // vec[mid] >= val, good candidate
      high = mid - 1; // search left part
    }
    // Case 3: mid value is smaller → go right
    else {
      low = mid + 1;
    }
  }

  return ans; // ans will be first index >= val, or n if none
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

  // Calling lower bound
  int result = Lower_Bound(y);

  // Print resulting index
  cout << "Lower bound index = " << result;

  return 0;
}
