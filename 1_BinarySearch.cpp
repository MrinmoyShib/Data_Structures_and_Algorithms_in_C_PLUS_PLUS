#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;

int Binary_Search(int val) {
  int low = 0, high = n - 1 ;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (vec[mid] == val) {
      return mid;
    } else if (vec[mid] > val) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int main() {
  int x, y;

  cout << "Enter the Array size:";
  cin >> n;
  cout << "Enter the array:";
  for (int i = 0; i < n; i++) {
    cin >> x;
    vec.push_back(x);
  }
  cout << "Enter search element : ";
  cin >> y;
  int result = Binary_Search(y);
  cout << result;
  return 0;
}
