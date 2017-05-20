#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> komnaty[1000050];
int odleglosc[1000050];
int main() {
  ios_base::sync_with_stdio(false);
  //ilosc zestawow testowych
  int Z;
  cin >> Z;
  for(int z = 0; z < Z; z++) {
      //ilosc komnat, ilosc korytarzy, kule
      int n, m, k;
      cin >> n >> m >> k;
      //czyszczenie
      for(int i = 0; i < n; i++) {
          komnaty[i].clear();
          odleglosc[i] = -1;
          
      }
      //ustawianie zerowej komnaty na odleglosc zero od samej siebie
      odleglosc[0] = 0; 
      //wczytywanie
      for(int i = 0; i < m; i++) {
          int a, b;
          cin >> a >> b;
          a -= 1;
          b -= 1;
          komnaty[a].push_back(b);
          komnaty[b].push_back(a);
      }
      queue<int> bfs;
      vector<int> iloscOddalonych;
      iloscOddalonych.push_back(0);
      bfs.push(0);


      while(bfs.size() > 0) {
          int aktualnaKomnata = bfs.back();
          bfs.pop();
          for(unsigned int i = 0; i < komnaty[aktualnaKomnata].size(); i++) {
            int nastepnaKomnata = komnaty[aktualnaKomnata][i];
            if(odleglosc[nastepnaKomnata] == -1) {
                bfs.push(nastepnaKomnata);
            }
            if(odleglosc[nastepnaKomnata] == -1 || odleglosc[nastepnaKomnata] > odleglosc[aktualnaKomnata] + 1) {
                odleglosc[nastepnaKomnata] = odleglosc[aktualnaKomnata] + 1;
                //cout << "ODLEGLOSC:" << odleglosc[aktualnaKomnata] + 1 << "\n";
                
                if(odleglosc[aktualnaKomnata] + 1 >= iloscOddalonych.size()) {
                    //cout << "NOWY\n";
                    iloscOddalonych.push_back(1);
                } else {
                    iloscOddalonych[odleglosc[aktualnaKomnata] + 1] += 1;
                }
            }
            
          }
      }
      int max = 0;
      int imax = 0;
      for(int i = 0; i < iloscOddalonych.size(); i++) {
         // cout << "ILOS" << i << " " << iloscOddalonych[i] << "\n";
        if(iloscOddalonych[i] > max) {
            max = iloscOddalonych[i];
            imax = i;
        }
      }

      if(max > k) {
          cout << imax << "\n";
      } else {
          cout << "hurray!\n";
      }

  }
  return 0;
}