#include <iostream>

using namespace std;
int pi[1090007];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int k = 0; k < n; k++) {
    string wzorzec;
    string tekst;
    cin >> tekst >> wzorzec;

    int j = 0;
    pi[0] = 0;

    string str = tekst +"$" + tekst;
    for (int i = 1; i < str.size(); i++) {
      pi[i] = 0;
    }
    for (int i = 1; i < str.size(); i++) {
      while (j > 0 && str[i] != str[j]) {
        j = pi[j - 1];
      }
      if (str[j] == str[i]) {
        j++;
      }

      pi[i] = j;
    }
    int ok = false;
    for (int i = 0; i < str.size(); i++) {
      // cout << "(" << str[i] << ") " << pi[i] << ", ";
      if (pi[i] == wzorzec.size() && !ok) {
        cout << "TAK\n";
        ok = true;
      }
    }
    if (!ok)
      cout << "NIE\n";
    // cout << "\n ===== \n";
  }

  return 0;
}