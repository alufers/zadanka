#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip> 
using namespace std;
double wsp[5];
double obliczWartosc(double x) {
  return (wsp[0] * 1) + (wsp[1] * x) + (wsp[2] * x * x) + (wsp[3] * x * x * x) +
         (wsp[4] * x * x * x * x);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> wsp[i];
  }
  double a = 0.0, b = 100.0;
  double srodek = 50.0;
  while (b - a > pow(10.0, -8.0)) {
    srodek = (a + b) / 2;
    if (obliczWartosc(srodek) > 0) {
      a = srodek;
    } else {
      b = srodek;
    }
  }
  cout << setprecision(7) << fixed << srodek << "\n";
  return 0;
}