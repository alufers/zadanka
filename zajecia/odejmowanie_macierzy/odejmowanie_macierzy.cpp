#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int arr1[n][m];
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      cin >> arr1[y][x];
    }
  }
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      int tmp = 0;
      cin >> tmp;
      arr1[y][x] -= tmp;
      cout << arr1[y][x] << " ";
      
    }
    cout << "\n";
  }
  return 0;
}