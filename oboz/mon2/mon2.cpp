#include <algorithm>
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
  sort(monety, monety + n);
  int kwota = 0;
  cin >> kwota;

  bool mozna[kwota + 1];
  int ileMonet[kwota + 1];
  for (int i = 0; i < kwota + 1; i++) {
    mozna[i] = false;
    ileMonet[i] = 1000000000;
  }
  mozna[0] = true;
  ileMonet[0] = 0;

  for (int mon = 0; mon < n; mon++) {
    for (int i = 0; i < kwota + 1; i++) {
      if (mozna[i] == true && i + monety[mon] < kwota + 1) {
        mozna[i + monety[mon]] = true;
        if (ileMonet[i + monety[mon]] > 1 + ileMonet[i]) {
          ileMonet[i + monety[mon]] = 1 + ileMonet[i];
        }
      }
    }
  }

  if (mozna[kwota]) {
    /*int ilosc = 0;
    int aktualnyIndex = kwota;
    while (aktualnyIndex != 0) {
      //cout << "biore " << uzytaMoneta[aktualnyIndex] << "\n";
      aktualnyIndex -= uzytaMoneta[aktualnyIndex];
      ilosc++;
    }*/
    cout << ileMonet[kwota];
  } else {
    cout << "NIE";
  }
  // cout << (mozna[kwota] ? "TAK" : "NIE");

  return 0;
}