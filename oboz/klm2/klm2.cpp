#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;

class Kamien {
public:
  int x;
  int y;
  /*Kamien(int x, int y) {
    this->x = x;
    this->y = y;
  }*/
  long dist2(Kamien inny) {
    return (((this->x - inny.x) * (this->x - inny.x)) +
            ((this->y - inny.y) * (this->y - inny.y)));
  }
};

class Polaczenie {
public:
  int a;
  int b;
  int dist2;
};

bool operator>(Polaczenie const &a, Polaczenie const &b) {
  return a.dist2 > b.dist2;
}

bool operator<(Polaczenie const &a, Polaczenie const &b) {
  return a.dist2 < b.dist2;
}

Kamien kamienie[1003];

int przedstawiciele[1003];

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
  Polaczenie polaczenia[500005];

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    kamienie[i].x = x;
    kamienie[i].y = y;
    przedstawiciele[i] = i;
  }

  int counter = 0;
  for (int i = 0; i < n; i++) {
    for (int i2 = i + 1; i2 < n; i2++) {
      polaczenia[counter].a = i;
      polaczenia[counter].b = i2;
      polaczenia[counter].dist2 = kamienie[i].dist2(kamienie[i2]);
      counter++;
    }
  }
  sort(polaczenia, polaczenia + counter);
  int maxOdleglosc = 0;
  for (int i = 0; i < counter; i++) {
    if (find(polaczenia[i].a) == find(polaczenia[i].b)) {
      continue;
    }
    Union(polaczenia[i].a, polaczenia[i].b);
    if (polaczenia[i].dist2 > maxOdleglosc) {
      maxOdleglosc = polaczenia[i].dist2;
    }
  }

  //cout << sqrt(maxOdleglosc);
  printf("%.2f", sqrt(maxOdleglosc));
  return 0;
}