#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MILION 1000 * 1000
int pi[2 * MILION + 50];
int main() {
  ios_base::sync_with_stdio(false);

  string wzorzec;

  cin >> wzorzec;

  int j = 0;
  pi[0] = 0;


  string str = wzorzec + '#';
  reverse(wzorzec.begin(), wzorzec.end());
  str += wzorzec;
  
  for (unsigned int i = 1; i < str.size(); i++) {
    while (j > 0 && str[i] != str[j]) {
      j = pi[j - 1];
    }
    if (str[j] == str[i]) {
      j++;
    }

    pi[i] = j;
  }


  cout << pi[str.size() - 1];
  // cout << "\n ===== \n";

  return 0;
}