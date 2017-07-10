#include <iostream>

using namespace std;
int pi[100];
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

    for (int i = 1; i < wzorzec.size(); i++) {
      while (j > 0 && wzorzec[i] != wzorzec[j]) {
        j = pi[j];
        
      }
      if (wzorzec[j] == wzorzec[i]) {
        j++;
      }

      pi[i] = j;
    }
    for (int i = 0; i < wzorzec.size(); i++) {
      cout << pi[i] << ", ";
    }
    cout << "\n";
  }

  return 0;
}