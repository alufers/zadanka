#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  int monety[n];
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    monety[i] = tmp;
  }
  int kwota = 0;
  cin >> kwota;

  bool mozna[kwota + 1];
  for (int i = 0; i < kwota + 1; i++) {
    mozna[i] = false;
  }
  mozna[0] = true;

  for (int mon = 0; mon < n; mon++) {
    for (int i = 0; i < kwota + 1; i++) {
      if (mozna[i] == true && i + monety[mon] < kwota + 1) {
          mozna[i + monety[mon]] = true;
      }
    }
  }

  cout << (mozna[kwota] ? "TAK" : "NIE");

  return 0;
}