#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int iloscTestow;
  cin >> iloscTestow;
  for (int k = 0; k < iloscTestow; k++) {
    int ilePrzyst;
    cin >> ilePrzyst;
    cout << ((1 << ilePrzyst) - 1) << "\n";
  }
  return 0;
}