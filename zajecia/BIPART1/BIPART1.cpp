#include <iostream>
#include <vector>
using namespace std;
int n = 0, m = 0;
vector<int> polaczenia[1000010 / 2];
char kolor[1000010 / 2];
bool zly = false;
void dfs(int w, int ostatniKolor) {

  kolor[w] = (ostatniKolor == 1) ? 2 : 1;
  for (int i = 0; i < polaczenia[w].size(); i++) {
    if (kolor[polaczenia[w][i]] > 0) {
      if (kolor[polaczenia[w][i]] == kolor[w]) {
        zly = true;
        return;
      }
      continue;
    }

    dfs(polaczenia[w][i], kolor[w]);
    if(zly) {
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    polaczenia[i].clear();
    kolor[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    polaczenia[a].push_back(b);
    polaczenia[b].push_back(a);
  }
  for(int i = 0; i < n; i++) {
    if(kolor[i] == 0) {
      dfs(i, 0);
    }
    if(zly) {
      cout << "NIE\n";
      return 0;
    }
  }
  cout << "TAK\n";
  
  //cout << (zly ? "NIE\n" : "TAK\n");

  return 0;
}