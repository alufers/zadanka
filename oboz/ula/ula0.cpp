#include <iostream>

using namespace std;
int najwiekszyWspolnyMianownik(int a, int b)
{
    while((a != 0 && b != 0) && b != a)
    {
        if(a < b)
        {
            b = b % a;
        }
        else
        {
            a = a % b;
        }
    }

    return a == 0 ? b : a;
}

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int licz = a * c * e, mian = b * d * f;
  int njp = najwiekszyWspolnyMianownik(licz, mian);
  licz /= njp;
  mian /= njp;
  cout << licz << "/" << mian;
  return 0;
}