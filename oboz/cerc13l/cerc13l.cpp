#include <iostream>

using namespace std;

int ilePrzystankow(double iloscPasazerow) {
  int i = 0;
  while (iloscPasazerow > 0) {
    iloscPasazerow /= 2;
    iloscPasazerow -= 0.5;

    i++;
  }
  return i;
}

int main() {
  ios_base::sync_with_stdio(false);
  /*int iloscTestow;
  cin >> iloscTestow;
  for (int k = 0; k < iloscTestow; k++) {

  }*/
  // cout << iloscPasazerow << "\n";
  //  cout << iloscPasazerow << "\n";
  /*double iloscPasazerow;
  cin >> iloscPasazerow;

  cout << i << "\n";*/

  int ostatniaIlosc = -1;

  for (long i = 1; i < 500000000; i *=2) {
    int ile = ilePrzystankow(i);
    if (ile != ostatniaIlosc) {
      ostatniaIlosc = ile;
      cout << "Dla iprzystankow = " << ile << " n = " << i << "\n";
    }
  }
  return 0;
}