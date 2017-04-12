#include <iostream>

using namespace std;
int przedstawiciele[300002];

int find(int x) {
  return przedstawiciele[x] == x ? (x) : (przedstawiciele[x] =
                                              find(przedstawiciele[x]));
}
void Union(int x, int y) {
  //
  przedstawiciele[find(x)] = find(y);
}

int main() {
  ios_base::sync_with_stdio(false);
  int iloscMiast, iloscIstniejacychDrog, iloscZapytan;
  cin >> iloscMiast >> iloscIstniejacychDrog >> iloscZapytan;

  for (int i = 0; i < iloscMiast; i++) {
    przedstawiciele[i] = i;
  }

  for (int i = 0; i < iloscIstniejacychDrog; i++) {
    int a, b;
    cin >> a >> b;
    Union(a, b);
  }

  for (int i = 0; i < iloscZapytan; i++) {
    int a, b, typZapytania;
    cin >> typZapytania >> a >> b;
    switch (typZapytania) {
    case 0: // pytanie
            // cout << "PYTANIE";
      cout << ((find(a) == find(b)) ? "TAK\n" : "NIE\n");
      break;
    case 1: // budowa
      Union(a, b);
      break;
    }
  }

  return 0;
}