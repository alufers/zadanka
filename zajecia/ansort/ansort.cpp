#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace std;

class Pozycja {
public:
  int x;
  int y;
  void wypiszSie() { cout << this->x << " " << this->y << "\n"; }
  float kat() { return atan(this->y / this->x); }
};
bool operator<(Pozycja &a, Pozycja &b) {
    return a.kat() < a.kat();
}
bool operator>(Pozycja &a, Pozycja &b) {
    return a.kat() > a.kat();
}
int main() {
  ios_base::sync_with_stdio(false);
  srand (time(NULL));
  int n = 0;
  cin >> n;
  Pozycja pozycje[n];
  for (int i = 0; i < n; i++) {
    cin >> pozycje[i].x >> pozycje[i].y;
  }
  sort(pozycje, pozycje + n);
  
  for (int i = 0; i < n; i++) {
    pozycje[i].wypiszSie();
  }

  return 0;
}