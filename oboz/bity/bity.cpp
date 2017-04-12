#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  long x, k;
  cin >> x >> k;
  
  long ktore = 0;
  long y = 1;    


  while (true) {
    if ((y + x) == (y | x)) {
      ktore++;
      if (ktore >= k) {
        cout << y;
        return 0;
      }
    }
    y++;
  }
  return 0;
}