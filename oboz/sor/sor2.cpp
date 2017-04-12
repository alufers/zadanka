#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long ciag[n];
  long posort[n];
  for (int i = 0; i < n; i++) {
    long tmp = 0;
    cin >> tmp;
    ciag[i] = tmp;
    posort[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int k = 1; k < n; k++) {
      if (ciag[k - 1] > ciag[k]) {
        cout << ciag[k - 1] << " " << ciag[k] << "\n";
        long tmp = ciag[k];
        ciag[k] = ciag[k - 1];
        ciag[k - 1] = tmp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ciag[i] << " ";
  }
  return 0;
}