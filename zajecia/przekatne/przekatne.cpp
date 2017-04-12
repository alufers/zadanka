#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      cin >> arr[i][k];
    }
  }
  int maxSuma = 0;
  int numMaxSumy = 0;
  int y = n - 1, x = 0;
  int num = 1;

  while (num < n * 2) {
    //  cout << "X = " << x << " Y = " << y << "\n";
    int tx, ty;
    tx = x;
    ty = y;
    int aktualnaSuma = 0;
    while (tx < n && ty < n) {
        aktualnaSuma += arr[ty][tx];
        tx ++;
        ty ++;
    }
    if(aktualnaSuma >= maxSuma) {
        maxSuma = aktualnaSuma;
        numMaxSumy = num;
    }
    if (y == 0) {
      x++;
    } else {
      y--;
    }
    num++;
  }
  cout << numMaxSumy << " " << maxSuma;

  return 0;
}