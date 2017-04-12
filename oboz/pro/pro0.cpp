#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  unsigned long long a, b, c, d;
  cin >> a >> b >> c >> d;
  unsigned long long boki[] = {a,b,c,d};
  std::sort(std::begin(boki), std::end(boki));
  cout << boki[0] * boki[2];
  return 0;
}