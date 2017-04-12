#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  long n;
  cin >> n;
  long long liczby[n];
  long long miny[n];
  for (long i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    liczby[i] = tmp;
    // cout << liczby[i];
  }
  long long min = liczby[n - 1];
  for (long i = n - 1; i >= 0; i--) {
    if (liczby[i] < min) {
      min = liczby[i];
    }
    miny[i] = min;
  }
  for (long i = 0; i < n; i++) {
    cout << miny[i] << " ";
    // cout << liczby[i];
  }
  return 0;
}