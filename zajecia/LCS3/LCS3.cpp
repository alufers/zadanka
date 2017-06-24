#include <iostream>
#include <string>

using namespace std;

int tab[1002][1002];

bool jestPodciagiem(string a, string x) {
  int xpos = 0;
  for (int i = 0; i < a.size(); i++) {
    if (x[xpos] == a[i]) {
      xpos++;
      if (xpos == x.size() - 1) {
        return true;
      }
    }
  }
  return false;
}



int main() {
  ios_base::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b >> c;
  if(!jestPodciagiem(a, c) || !jestPodciagiem(b, c)) {
    cout << "NIE\n";
  }

  cout << "TAK\n";
  return 0;
}