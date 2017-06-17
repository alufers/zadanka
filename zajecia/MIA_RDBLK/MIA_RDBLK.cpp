#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int infty = 1000000000; // uwaga na limit
int n, m;
vector<pair<int, int>> adj[100000];

vector<int> waga;

struct cmp {
  // czy a jest mniejsze od b
  bool operator()(const int &a, const int &b) {
    if (waga[a] < waga[b])
      return true;
    if (waga[a] > waga[b])
      return false;
    return a < b;
  }
};

set<int, cmp> kopiec; // ;-)
vector<int> sciezka;

void dijkstra(int s) {
  int v, u, c;
  waga.clear();          // kasuje wektor
  waga.resize(n, infty); //

  waga[s] = 0;
  kopiec.clear();
  kopiec.insert(s);

  while (!kopiec.empty()) {
    u = *(kopiec.begin());
    kopiec.erase(kopiec.begin());

    for (int i = 0; i < adj[u].size(); i++) {
      v = adj[u][i].first;
      c = adj[u][i].second;
      if (waga[u] + c < waga[v]) {
        // uaktualniamy wagę wierzchołka v
        if (kopiec.find(v) != kopiec.end()) {
          kopiec.erase(kopiec.find(v));
        } else {
          sciezka.push_back(v);
        }

        waga[v] = waga[u] + c;
        kopiec.insert(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  // int n, m; // wierzcholki, krawedzie
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;

    cin >> a >> b >> c;
    a--;
    b--;
    // adj[a] = make_pair();
    adj[a].push_back(pair<int, int>(b, c));
    adj[b].push_back(pair<int, int>(a, c));
  }
  dijkstra(0);

  return 0;
}