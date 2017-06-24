#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int tab[1002][1002];

int main() {
  ios_base::sync_with_stdio(false);
  int _;
  string a, b;
  cin >> _ >> a >> _ >> b;

  tab[0][0] = 0;
  for (int i = 0; i < a.size(); i++) {
    tab[i][0] = i;
  }
  for (int i = 0; i < b.size(); i++) {
    tab[0][i] = i;
  }
  for (int y = 1; y < b.size(); y++) {
    for (int x = 1; x < a.size(); x++) {
      tab[x][y] = min(tab[x - 1][y], tab[x][y - 1]) + 1;
      if (a[x] == b[y]) {
        tab[x][y] = min(tab[x][y], tab[x - 1][y - 1]);
      }/* else {
        tab[x][y] = min(tab[x][y], tab[x - 1][y - 1] + 1);
      }*/
    }
  }

  cout << tab[a.size() - 1][b.size() - 1];
  return 0;
}