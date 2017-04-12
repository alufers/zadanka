#include <iostream>

using namespace std;

int main() {
  long n;
  ios_base::sync_with_stdio(false);
  cin >> n;
  unsigned long long max = 0;
  for (int i = 0; i < n; i++) {
    unsigned long long licz = 0;
    cin >> licz;
    if (licz > max) {
      max = licz;
    }
  }
  cout << max;
  return 0;
}