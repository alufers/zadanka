#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int stala = 1e5 + 3;

int abs(int a) { return a < 0 ? -a : a; }
int max3(int a, int b, int c) { return max(a, max(b, c)); }
/*int dp(vector<int> &kolumny, int i) {
  if (i < 0) {
    return 0;
  }
  return max(dp(kolumny, i - 1),
             max(dp(kolumny, i - 2) + kolumny[i], dp(kolumny, i - 3)));
  // return max3(dp(kolumny, i - 1), dp(kolumny, i - 2) + kolumny[i],
  // dp(kolumny, i - 3));
}
*/
int dp[stala][3];
int main() {
  ios_base::sync_with_stdio(false);
  int z = 0;
  cin >> z;
  for (int k = 0; k < z; k++) {
    int n = 0;
    cin >> n;

    vector<int> wartosci;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      wartosci.push_back(tmp);
      dp[i][0] = 0;
      dp[i][1] = 0;
      dp[i][2] = 0;
    }
    dp[0][0] = 0;
    dp[0][1] = wartosci[0];
    dp[0][2] = wartosci[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = wartosci[i] + dp[i - 1][0];
      dp[i][2] = wartosci[i] + dp[i - 1][1];
    }
    cout << max3(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]) << "\n";
  }
  return 0;
}