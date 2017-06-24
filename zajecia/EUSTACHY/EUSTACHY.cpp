#include <iostream>
#include <string>

using namespace std;

int tabl[502][502][502];
int lcs3l(string &a, string &b, string &c) {

  for (unsigned int x = 1; x <= a.size(); x++) {
    for (unsigned int y = 1; y <= b.size(); y++) {
      for (unsigned int z = 1; z <= c.size(); z++) {
        if (a[x] == b[y] && b[y] == c[z]) {
          tabl[x][y][z] = tabl[x - 1][y - 1][z - 1] + 1;
          // tabd =
        } else {
          tabl[x][y][z] =
              max(tabl[x - 1][y][z], max(tabl[x][y - 1][z], tabl[x][y][z - 1]));
        }
      }
    }
  }
  return tabl[a.size()][b.size()][c.size()];
}

int tab[2][2][2][26];
int tabd[2][2][2];
int lcs3(string &a, string &b, string &c) {
  
  for (unsigned int x = 1; x <= 1; x++) {
    for (unsigned int y = 1; y <= 1; y++) {
      for (unsigned int z = 1; z <= 1; z++) {
         for (int k = 0; k < 26; k++) {
           tab[x][y][z][k] = 0;
         }
      }
    }
  }
  for (unsigned int x = 1; x <= a.size(); x++) {
    for (unsigned int y = 1; y <= b.size(); y++) {
      for (unsigned int z = 1; z <= c.size(); z++) {
        if (a[x] == b[y] && b[y] == c[z]) { //wszystkie 3 takie same
          tabd[x % 2][y % 2][z % 2] =
              tabd[(x - 1 + 2) % 2][(y - 1 + 2) % 2][(z - 1 + 2) % 2] + 1; //
          for (int k = 0; k < 26; k++) {

            if (k == b[y] - 'a' && tabd[(x - 1 + 2) % 2][(y - 1 + 2) % 2][(z - 1 + 2) % 2] + 1 ==
                tabd[x % 2][y % 2][z % 2]) {

              tab[x % 2][y % 2][z % 2][k] =
                  tab[(x - 1 + 2) % 2][(y - 1 + 2) % 2][(z - 1 + 2) % 2][k] + 0;
            }
          }
        } else {
          tabd[x % 2][y % 2][z % 2] =
              max(tabd[(x - 1 + 2) % 2][y % 2][z % 2],
                  max(tabd[x % 2][(y - 1 + 2) % 2][z % 2],
                      tabd[x % 2][y % 2][(z - 1 + 2) % 2]));
          for (int k = 0; k < 26; k++) {
            cout << "HALO\n";
            tab[x % 2][y % 2][z % 2][k] = 0;
            if(tabd[x % 2][y % 2][z % 2] == tabd[(x - 1 + 2) % 2][y % 2][z % 2]) {
               tab[x % 2][y % 2][z % 2][k] += tab[(x - 1 + 2) % 2][y % 2][z % 2][k];
            }
            if(tabd[x % 2][y % 2][z % 2] == tabd[x % 2][(y - 1 + 2) % 2][z % 2]) {
               tab[x % 2][y % 2][z % 2][k] += tab[x % 2][(y - 1 + 2) % 2][z % 2][k];
            }
            if(tabd[x % 2][y % 2][z % 2] == tabd[x % 2][y % 2][(z - 1 + 2) % 2]) {
               tab[x % 2][y % 2][z % 2][k] += tab[x % 2][y % 2][(z - 1 + 2) % 2][k];
            }
            /*tab[x % 2][y % 2][z % 2][k] =
                max(,
                    max(tab[x % 2][(y - 1 + 2) % 2][z % 2][k],
                        [k]));*/
          }
        }
      }
    }
  }
  int sum = 0;
  for (int k = 0; k < 26; k++) {
    cout << (char)(k + 'a') << " = " << tab[a.size() % 2][b.size() % 2][c.size() % 2][k] << "\n";
    sum += tab[a.size() % 2][b.size() % 2][c.size() % 2][k];
  }
  return sum;
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
    cout << lcs3l(a, b, c) << " " << lcs3(a, b, c);
  }
  return 0;
}