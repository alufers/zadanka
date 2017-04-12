#include <iostream>
#include <map>
#include <utility>
using namespace std;

int przedstawiciele[100002];
map<pair<int, int>, int> polaczenia;

// o ile a jest ciezsze od b
int masaMiedzy(int a, int b) {
  if (a == b) {
    // cout << "CIERPIENIE CIERPIENIE\n";
    return 0;
  }
  map<pair<int, int>, int>::iterator it1 = polaczenia.find(make_pair(a, b));
  if (it1 != polaczenia.end()) {
    int tmp = it1->second;
    return tmp;
  }
  return -polaczenia.find(make_pair(b, a))->second;
}

void probojWsadzic(int a, int b, int masa) {
  // auto it1 = polaczenia.find(make_pair(a, b));
  // auto it2 = polaczenia.find(make_pair(b, a));
  // if (it1 != polaczenia.end() || it2 != polaczenia.end()) {
  //  return;
  //}
  polaczenia.insert(make_pair(make_pair(a, b), masa));
}

int find(int x) {
  // return przedstawiciele[x] == x ? (x) : (przedstawiciele[x] =
  //                                            find(przedstawiciele[x]));
  if (przedstawiciele[x] == x) {
    return x;
  } else {

    int przedstawiciel = find(przedstawiciele[x]);
    int masaMiedzyXaStarym = masaMiedzy(x, przedstawiciele[x]);
    int masaMiedzyStarymINowym = masaMiedzy(przedstawiciele[x], przedstawiciel);
    /* polaczenia.insert(make_pair(make_pair(przedstawiciel, x),
                                 masaMiedzyXaStarym +
       masaMiedzyStarymINowym));*/
    probojWsadzic(przedstawiciel, x,
                  masaMiedzyXaStarym + masaMiedzyStarymINowym);
    przedstawiciele[x] = przedstawiciel;
    return przedstawiciel;
  }
}
void Union(int x, int y) {
  //
  przedstawiciele[find(x)] = find(y);
}

int main() {
  ios_base::sync_with_stdio(false);
  for (;;) {
    int liczbaLam, liczbaZdarzen;
    cin >> liczbaLam >> liczbaZdarzen;
    if (liczbaLam == 0 && liczbaZdarzen == 0) {
      for (auto it = polaczenia.begin(); it != polaczenia.end(); it++) {
        cout << "A = " << it->first.first << " B = " << it->first.second
             << " MASA = " << it->second << "\n";
      }
      return 0;
    }
    polaczenia.clear();
    for (int i = 0; i < liczbaLam; i++) {
      przedstawiciele[i] = i;
    }
    for (int i = 0; i < liczbaZdarzen; i++) {
      char typZapytania;
      cin >> typZapytania;
      int lamaA, lamaB, masa;
      switch (typZapytania) {
      case '!':

        cin >> lamaA >> lamaB >> masa;
        lamaA--;
        lamaB--;
        polaczenia.insert(make_pair(make_pair(lamaA, lamaB), masa));
        Union(lamaA, lamaB);

        break;
      case '?':

        cin >> lamaA >> lamaB;
        lamaA--;
        lamaB--;
        if (find(lamaA) == find(lamaB)) {
          //  cout << "A" << masaMiedzy(lamaA, przedstawiciele[lamaB])
          //  <<"B"<<masaMiedzy(lamaB, przedstawiciele[lamaB]) << "\n";
          cout << (masaMiedzy(lamaA, przedstawiciele[lamaB]) +
                   masaMiedzy(lamaB, przedstawiciele[lamaB]))
               << "\n";
        } else {
          cout << "UNKNOWN\n";
        }

        break;
      }
    }

    // int lamaA, lamaB;
    // cin >> typZapytania >> lamaA >> lamaB;
  }

  return 0;
}