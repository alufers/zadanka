#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int nominaly[n];
  for (int i = 0; i < n; i++) {
    int b;

    cin >> b;
    nominaly[i] = b;
  }
  std::sort(nominaly, nominaly + n);
  int kwota = 0;
  int ilo = 0;
  cin >> kwota;
  while (kwota != 0) {
    for (int i = 0; i < n; i++) {
      if (nominaly[i] < kwota) {
        kwota -= nominaly[i];
        ilo++;
      }
    }
  }
  cout << ilo;
  return 0;
}