#include <algorithm>
#include <iostream>

using namespace std;

class MozliwaAutostrada {
public:
  int a;
  int b;
  int koszt;
  void dbg() {
    cout << "A = " << this->a << " B = " << this->b
         << " KOSZT = " << this->koszt << "\n";
  }
};

bool operator>(MozliwaAutostrada const &a, MozliwaAutostrada const &b) {
  return a.koszt > b.koszt;
}

bool operator<(MozliwaAutostrada const &a, MozliwaAutostrada const &b) {
  return a.koszt < b.koszt;
}

int przedstawiciele[7005];

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
  int iloscMiast, iloscMozliwychAutostrad;
  cin >> iloscMiast >> iloscMozliwychAutostrad;
  MozliwaAutostrada mozliweAutostrady[iloscMozliwychAutostrad];
  for (int i = 0; i < iloscMiast; i++) {
    przedstawiciele[i] = i;
  }
  for (int i = 0; i < iloscMozliwychAutostrad; i++) {
    int a, b, koszt;
    cin >> a >> b >> koszt;
    MozliwaAutostrada ma;
    ma.a = a;
    ma.b = b;
    ma.koszt = koszt;
    mozliweAutostrady[i] = ma;
  }
  int totalKoszt = 0;
  sort(mozliweAutostrady, mozliweAutostrady + iloscMozliwychAutostrad);
  for (int i = 0; i < iloscMozliwychAutostrad; i++) {
    //mozliweAutostrady[i].dbg();
    //cout << find(mozliweAutostrady[i].a) << " " << find(mozliweAutostrady[i].b) << "\n";
    if (find(mozliweAutostrady[i].a) == find(mozliweAutostrady[i].b)) {
   //   cout << "MEH\n";
      continue;
    }

    totalKoszt += mozliweAutostrady[i].koszt;
    Union(mozliweAutostrady[i].a, mozliweAutostrady[i].b);
  }
  cout << totalKoszt;
  return 0;
}