#include <algorithm>
#include <iostream>

using namespace std;

class MozliwaKrawedz {
public:
  int a;
  int b;
  int koszt;
  int numer;
  void dbg() {
    cout << "NUMER = " << this->numer << " A = " << this->a
         << " B = " << this->b << " KOSZT = " << this->koszt << "\n";
  }
};

bool operator>(MozliwaKrawedz const &a, MozliwaKrawedz const &b) {

  return a.koszt > b.koszt;
}

bool operator<(MozliwaKrawedz const &a, MozliwaKrawedz const &b) {
  return a.koszt < b.koszt;
}

const int ELEMENT_COUNT = 7006;
int sizes[ELEMENT_COUNT];
int sets[ELEMENT_COUNT];

int Find(int a) {

  if (sets[a] == a) {
    return a;
  }
  int root = Find(sets[a]);
  sets[a] = root;
  return root;
}

void Union(int a, int b) {
  int a_ = Find(a);
  int b_ = Find(b);
  if (a_ != b_) {
    if (sizes[a_] < sizes[b_]) {
      sets[a_] = b_;
      sizes[a_] += sizes[b_];
    } else {
      sets[b_] = a_;
      sizes[b_] += sizes[a_];
    }
  }
}

void dumpSets() {
  for (int i = 0; i < ELEMENT_COUNT; i++) {
    cout << "S[" << i << "] = " << sets[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int iloscWiezcholkow, iloscMozliwychKrawedzi;
  cin >> iloscWiezcholkow >> iloscMozliwychKrawedzi;
  MozliwaKrawedz mozliweKrawedzie[iloscMozliwychKrawedzi];
  for (int i = 0; i < ELEMENT_COUNT; i++) {
    sets[i] = i;
    sizes[i] = 1;
  }
  for (int i = 0; i < iloscMozliwychKrawedzi; i++) {
    int a, b, koszt;
    cin >> a >> b >> koszt;
    MozliwaKrawedz ma;
    a--;
    b--;
    ma.a = a;
    ma.b = b;
    ma.koszt = koszt;
    ma.numer = i + 1;
    mozliweKrawedzie[i] = ma;
  }
  int totalKoszt = 0;
  stable_sort(mozliweKrawedzie, mozliweKrawedzie + iloscMozliwychKrawedzi);
  for (int i = 0; i < iloscMozliwychKrawedzi; i++) {
    //cout << "----\n";
    //mozliweKrawedzie[i].dbg();
    // cout << find(mozliweKrawedzie[i].a) << " " <<
    // find(mozliweKrawedzie[i].b) << "\n";
    if (Find(mozliweKrawedzie[i].a) == Find(mozliweKrawedzie[i].b)) {
      //   cout << "MEH\n";
      //cout << mozliweKrawedzie[i].a << " oraz " << mozliweKrawedzie[i].b
      //     << " sa juz polaczone.\n";
      continue;
    }

    cout << mozliweKrawedzie[i].numer << "\n";
    Union(mozliweKrawedzie[i].a, mozliweKrawedzie[i].b);
    ///dumpSets();
    //cout << "====\n";
  }

  return 0;
}