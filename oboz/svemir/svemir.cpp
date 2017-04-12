#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int ILOSC_PLANET = 10e5;

class Planeta {
public:
  int x;
  int y;
  int z;
  int koszt(Planeta inna) {
    return min(abs(inna.x - this->x),
               min(abs(inna.y - this->y), abs(inna.z - this->z)));
  }
};

class Polaczenie {
public:
  int a;
  int b;
  int koszt;
};

bool operator>(Polaczenie const &a, Polaczenie const &b) {
  return a.koszt > b.koszt;
}

bool operator<(Polaczenie const &a, Polaczenie const &b) {
  return a.koszt < b.koszt;
}

Planeta planety[ILOSC_PLANET];
int przedstawiciele[ILOSC_PLANET];

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
  int n = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    planety[i].x = x;
    planety[i].y = y;
    planety[i].z = z;
    przedstawiciele[i] = i;
  }
  /*// Polaczenie polaczenia[13500000];
  vector<Polaczenie> polaczenia;
  for (int i = 0; i < n; i++) {
    for (int i2 = i + 1; i2 < n; i2++) {
      Polaczenie pol;
      pol.a = i;
      pol.b = i2;
      pol.koszt = planety[i].koszt(planety[i2]);
      polaczenia.push_back(pol);
    }
  }
  
  sort(polaczenia.begin(), polaczenia.end());
  int totalKoszt = 0;
  for (int i = 0; i < polaczenia.size(); i++) {
    if (find(polaczenia[i].a) == find(polaczenia[i].b)) {
      continue;
    }
    Union(polaczenia[i].a, polaczenia[i].b);

    totalKoszt += polaczenia[i].koszt;
  }
*/
  cout << totalKoszt;
  return 0;
}