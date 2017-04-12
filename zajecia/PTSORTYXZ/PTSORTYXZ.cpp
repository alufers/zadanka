#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  pair<int, pair<int, int>  > arr[n];
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    arr[i] = make_pair(y, make_pair(x, z));
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    cout << arr[i].second.first << " " << arr[i].first << " " << arr[i].second.second << "\n";
  }

  return 0;
}