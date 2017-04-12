#include <iostream>
#include <string>
using namespace std;

int main() {
  long n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string slowo;
    cin >> slowo;
    bool pali = true;
    for (int k = 0; k < ((int)slowo.size() / 2); k++) {
      if (slowo[k] != slowo[slowo.size() - 1 - k]) {
          pali = false;
      }
    }
    cout << (pali ? "TAK" : "NIE") << "\n";
  }

  return 0;
}