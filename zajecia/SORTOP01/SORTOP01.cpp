#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> polaczenia[100008];
int stopienWchodzacy[100008];

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  // V, E
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    polaczenia[a].push_back(b);
    stopienWchodzacy[b]++;
  }
  vector<int> wyjscie;
  priority_queue<int, vector<int>, less<int> > kolejka;
  for (int i = 0; i < n; i++) {
    if (stopienWchodzacy[i] == 0) {
      kolejka.push(i);
    }
  }
  while (kolejka.size()) {
    int aktualnyWierzcholek = kolejka.top();
    //cout << (aktualnyWierzcholek + 1) << "\n";
    kolejka.pop();
    for (int i = 0; i < polaczenia[aktualnyWierzcholek].size(); i++) {
      stopienWchodzacy[polaczenia[aktualnyWierzcholek][i]]--;
      if (stopienWchodzacy[polaczenia[aktualnyWierzcholek][i]] == 0) {
          kolejka.push(polaczenia[aktualnyWierzcholek][i]);
      }
    }
    wyjscie.push_back(aktualnyWierzcholek);
  }

  if(wyjscie.size() < n) {
      cout << "NIE\n";
      return 0;
  }

  for(int i = 0; i < wyjscie.size(); i++) {
      cout << (wyjscie[i] + 1) << " ";
  }

  return 0;
}