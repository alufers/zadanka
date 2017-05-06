#include <iostream>
#include <vector>
using namespace std;
int n = 0, m = 0;
vector<int> polaczenia[1100000];
bool odwiedzony[1100000];
void dfs(int w) {
    
    odwiedzony[w] = true;
    for(int i = 0; i < polaczenia[w].size(); i++) {
        if(odwiedzony[polaczenia[w][i]]) continue;
        dfs(polaczenia[w][i]);
    }
}
bool sprawdz() {
    for (int i = 0; i < n; i++) {
        
        if(!odwiedzony[i]) {
            return false;
        }
    }
    return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  int zestawy = 0;
  cin >> zestawy;
  for (int k = 0; k < zestawy; k++) {
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        polaczenia[i].clear();
        odwiedzony[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        polaczenia[a].push_back(b);
        polaczenia[b].push_back(a);
    }
    dfs(0);
    cout << (sprawdz() ? "TAK\n" : "NIE\n");
    
  }

  return 0;
}