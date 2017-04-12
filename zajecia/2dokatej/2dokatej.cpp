#include <iostream>

using namespace std;

long long pot(int p, int w) {
  return ((w == 0) ? (0) : (pot(p, w - 1) * p));
}

int main() {
  ios_base::sync_with_stdio(false); 
  long long k = 0;
  cin >> k;
  long long wynik = pot(2, k);
  cout << wynik;
  return 0;
}