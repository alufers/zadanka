#include <iostream>

using namespace std;

int najlepszyWynik(int **plansza, int liczbaWierszy, int liczbaKolumn, int x,
                   int y) {
  int punktyWDol = -1;
  int punktyWPrawo = -1;
  //cout << "PATRZE NA X = " << x << " Y = " << y << "\n";
  if (x + 1 < liczbaKolumn) {
    punktyWPrawo =
        najlepszyWynik(plansza, liczbaWierszy, liczbaKolumn, x + 1, y);
  }

  if (y + 1 < liczbaWierszy) {
    punktyWDol = najlepszyWynik(plansza, liczbaWierszy, liczbaKolumn, x, y + 1);
  }
  //cout << "PRAWO = " << punktyWPrawo << " DOL = " << punktyWDol << "\n";
  if (punktyWDol == -1 && punktyWPrawo == -1) {
   // cout << " KONIEC\n";
    return plansza[x][y];
  }
  
  if (punktyWDol == -1) {
    return plansza[x][y] + punktyWPrawo;
  }
  if (punktyWPrawo == -1) {
    return plansza[x][y] + punktyWDol;
  }
  return (punktyWPrawo > punktyWDol ? punktyWPrawo : punktyWDol) + plansza[x][y];
}

void doTask() {
  int liczbaWierszy, liczbaKolumn;
  cin >> liczbaWierszy >> liczbaKolumn;
  int **plansza = new int *[liczbaWierszy];

  for (int x = 0; x < liczbaKolumn; x++) {
    plansza[x] = new int[liczbaKolumn];
  }
  for (int y = 0; y < liczbaWierszy; y++) {
    for (int x = 0; x < liczbaKolumn; x++) {
      cin >> plansza[x][y];
    }
  }
  cout << najlepszyWynik(plansza, liczbaWierszy, liczbaKolumn, 0, 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    doTask();
  }
  return 0;
}