#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int n;

// -----------------------------------------------------------
// Function: Upper_Bound
// Returns the first index where vec[index] > val
// Works only on sorted arrays in non-decreasing order
// If all elements are <= val, returns n (end of array)
// -----------------------------------------------------------
int Upper_Bound(int val) {
  int low = 0, high = n - 1;
  int ans = n; // Default answer = n, means "not found"

  while (low <= high) {
    int mid = (low + high) / 2; // Middle index

    // Case 1: Current element is strictly greater than val
    if (vec[mid] > val) {
      ans = mid;      // vec[mid] could be the answer
      high = mid - 1; // Move left to find earlier occurrence
    }
    // Case 2: Current element is <= val
    else {
      low = mid + 1; // Move right to find a bigger element
    }
  }

  return ans; // First index with element > val
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

  // Call Upper_Bound function
  int result = Upper_Bound(y);

  // Output the result
  cout << "Upper bound index = " << result;

  return 0;
}
