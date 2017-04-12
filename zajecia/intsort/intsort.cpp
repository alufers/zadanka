#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      arr[i] = tmp;
  }
  sort(arr, arr+n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  
  return 0;
}