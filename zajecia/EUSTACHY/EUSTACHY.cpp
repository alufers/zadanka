#include <iostream>

using namespace std;

int tab[502][502][502];

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 2) {
    string a, b;
    cin >> a >> b;
  } else if (n == 3) {
    string a, b, c;
    cin >> a >> b >> c;
  }
  return 0;
}
