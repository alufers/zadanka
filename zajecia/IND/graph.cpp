#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> komnaty[1000050];
int odleglosc[1000050];
int main() {
  ios_base::sync_with_stdio(false);
  // ilosc zestawow testowych
  int Z;
  cin >> Z;
  cout << "digraph G {\n";
  for (int z = 0; z < Z; z++) {
    // ilosc komnat, ilosc korytarzy, kule
    int n, m, k;
    cin >> n >> m >> k;
    // czyszczenie
    for (int i = 0; i < n; i++) {
      komnaty[i].clear();
      odleglosc[i] = -1;
    }
    // ustawianie zerowej komnaty na odleglosc zero od samej siebie
    odleglosc[0] = 0;
    // wczytywanie
    cout << "   subgraph cluster_" << z << " {\n";
    for (int i = 0; i < m; i++) {
      cout << "     label = \"" << z << " (k = " << k << ")\"\n";
      int a, b;
      cin >> a >> b;
      a -= 1;
      b -= 1;
      komnaty[a].push_back(b);
      komnaty[b].push_back(a);
      cout << "     " << z << "" << b << "->" << z << "" << a << ";\n";
    }
    cout << "   }\n";
  }
  cout << "}\n";
  return 0;
}