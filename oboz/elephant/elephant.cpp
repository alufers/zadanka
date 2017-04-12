#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*int lcs(vector<int> X, vector<int> Y, int offset) {
  int m = X.size();
  int n = Y.size();
  int L[m + 1][n + 1];
  int i, j;

  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (X[i - 1] == (Y[j - 1] + offset))
        L[i][j] = L[i - 1][j - 1] + 1;

      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }
  return L[m][n];
}*/

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> calosc;
  vector<int> wzorzec;
  int dlugoscCalosci, dlugoscWzorca;
  cin >> dlugoscCalosci >> dlugoscWzorca;
  for (int i = 0; i < dlugoscCalosci; i++) {
    int tmp;
    cin >> tmp;
    calosc.push_back(tmp);
  }
  for (int i = 0; i < dlugoscWzorca; i++) {
    int tmp;
    cin >> tmp;
    wzorzec.push_back(tmp);
  }
  /* int maxWzorca = 0;
   for (int i = 0; i < dlugoscWzorca; i++) {
     if (wzorzec[i] > maxWzorca) {
       maxWzorca = wzorzec[i];
     }
   }
   int maxCalosci = 0;
   for (int i = 0; i < dlugoscCalosci; i++) {
     if (calosc[i] > maxCalosci) {
       maxCalosci = calosc[i];
     }
   }
  // int ilo = 0;

     if (lcs(calosc, wzorzec, i) == dlugoscWzorca) {
       ilo++;
     }*/
  for (int i = 0; i < dlugoscWzorca - 1; i++) {
    wzorzec[i] = wzorzec[i] - wzorzec[i + 1];
  }
  wzorzec[dlugoscWzorca - 1] = 0;
  for (int i = 0; i < dlugoscCalosci - 1; i++) {
    calosc[i] = calosc[i] - calosc[i + 1];
  }
  calosc[dlugoscCalosci - 1] = 0;
  int ilo = 0;
  if (includes(calosc.begin(), calosc.end(), calosc.begin(),
               calosc.end())) {
     ilo += 1;
  }
  cout << ilo;

  return 0;
}