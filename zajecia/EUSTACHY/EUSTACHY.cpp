#include <iostream>
#include <string>

using namespace std;

int tab[502][502][502];
int lcs3(string &a, string &b, string &c) {

 
  for (unsigned int x = 1; x <= a.size(); x++) {
    for (unsigned int y = 1; y <= b.size(); y++) {
      for (unsigned int z = 1; z <= c.size(); z++) {
        if (a[x] == b[y] && b[y] == c[z]) {
          tab[x][y][z] = tab[x - 1][y - 1][z - 1] + 1;
         // tabd =
        } else {
          tab[x][y][z] =
              max(tab[x - 1][y][z], max(tab[x][y - 1][z], tab[x][y][z - 1]));
        }
      }
    }
  }
  return tab[a.size()][b.size()][c.size()];
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 2) {
    string a, b;
    cin >> a >> b;
  } else if (n == 3) {
    string a, b, c;
    cin >> a >> b >> c;
    cout << lcs3(a, b, c);
  }
  return 0;
}