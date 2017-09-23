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
    cin >> wzorzec >> tekst;

    int j = 0;
    //  pi[0] = 0;
    string str = wzorzec + "#" + tekst;
    for (int i = 1; i < str.size(); i++) {
      while (j > 0 && str[i] != str[j]) {
        j = pi[j - 1];
      }
      if (wzorzec[j] == str[i]) {
        j++;
      }

      pi[i] = j;
    }
    for (int i = 0; i < str.size(); i++) {
      // cout << "(" << str[i] << ") " << pi[i] << ", ";
      if (pi[i] == wzorzec.size()) {
        // cout << "MAM NA I = " << i << "\n";
        cout << (i - (2 * wzorzec.size())) << "\n";
      }
    }
    // cout << "\n ===== \n";
  }

  return 0;
}