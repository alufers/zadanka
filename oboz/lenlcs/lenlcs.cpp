#include <iostream>
#include <string>

using namespace std;

int lcs(string X, string Y) {
  int m = X.size();
  int n = Y.size();
  int L[m + 1][n + 1];
  int i, j;

  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;

      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }
  return L[m][n];
}

int max(int a, int b) { return (a > b) ? a : b; }

int main() {
  ios_base::sync_with_stdio(false);
  string slowo1;
    string slowo2;
    cin /*>> noop*/ >> slowo1 /*>> noop*/ >> slowo2;
    cout << lcs(slowo1, slowo2) << "\n";
  return 0;
}