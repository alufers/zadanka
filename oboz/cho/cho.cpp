#include <bitset>
#include <iostream>

using namespace std;

void dumpBin(int a) {
  std::bitset<32> x(a);
  std::cout << x;
}

void doTask(int ndex) {
  int liczbaPrzepisow;           // R
  int liczbaSkladnikow;          // P
  int liczbaDan;                 // N
  int liczbaSkladnikowWSpizarni; // M
  cin >> liczbaPrzepisow >> liczbaSkladnikow >> liczbaDan >>
      liczbaSkladnikowWSpizarni;
  int skladnikiDostepne = 0;
  for (int i = 0; i < liczbaSkladnikowWSpizarni; i++) {
    int tmp;
    cin >> tmp;
    skladnikiDostepne = skladnikiDostepne | (1 << tmp);
  }
  int ceny[liczbaSkladnikow];
  for (int i = 0; i < liczbaSkladnikow; i++) {
    int tmp;
    cin >> tmp;
    ceny[i] = tmp;
  }
  int przepisy[liczbaPrzepisow];
  // int ileDanMoznaZrobic[liczbaPrzepisow];
  for (int i = 0; i < liczbaPrzepisow; i++) {
    przepisy[i] = 0;
    for (int d = 0; d < liczbaSkladnikow; d++) {
      int tmp;
      cin >> tmp;
      if (tmp == 1) {
        przepisy[i] = przepisy[i] | (1 << d);
      }
    }
    przepisy[i] = przepisy[i] & ~skladnikiDostepne;
  }

  int minKoszt = 0;
  bool first = true;
  for (int komb = 0; komb < (1 << liczbaSkladnikow); komb++) {
    int usat = 0;
    for (int i = 0; i < liczbaPrzepisow; i++) {
      //cout << "\n";
      if ((przepisy[i] & ~komb) == 0) {
        usat++;
        if (usat >= liczbaDan) {

          int currKoszt = 0;
          /*dumpBin(komb);
          cout << "\n";*/
          for (int k = 0; k < liczbaSkladnikow; k++) {
           /* cout << "k = " << k << " ";
            dumpBin((1 << k));
            cout << " ";
            dumpBin((komb & (1 << k)));
            cout << " ";
            cout << ((komb & (1 << k)) != 0);
            cout << " ";*/
            if (komb & (1 << k)) { // jest tak przepis to dodac koszt
            /*  cout << "dodaje\n";*/
              currKoszt += ceny[k];
            }
          }
         /* cout << "Koszt" << currKoszt << "\n";*/
          if (first || currKoszt < minKoszt) {
            minKoszt = currKoszt;
            first = false;
          }
          break;
        }
      }
    }
  }

  cout << minKoszt << "\n";

  // dumpBin(skladnikiDostepne);
}

int main() {
  ios_base::sync_with_stdio(false);
  int q = 0;
  cin >> q;
  for (int i = 0; i < q; i++) {
    doTask(i);
  }
  return 0;
}