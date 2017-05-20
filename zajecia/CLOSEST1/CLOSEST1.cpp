#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_ILOSC = 1000020;
pair<int, int> startowe[MAX_ILOSC];
pair<int, int> koncowe[MAX_ILOSC];
int najblizszy[MAX_ILOSC];

int w, h, n, q;
int grid[1002][1002];


queue< pair<int, int> > Q;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> w >> h >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> koncowe[i].first >> koncowe[i].second;
    Q.push(koncowe[i]);
  }
  for (int i = 0; i < q; i++) {
    cin >> startowe[i].first >> startowe[i].second;
    grid[startowe[i].first][startowe[i].second] = -1 * i - 1;
  }

  while(Q.size()) {
      pair<int, int> aktualny = Q.front();
      Q.pop();
      if(grid[aktualny.first][aktualny.second] > 0) {
          continue;
      }
      if(grid[aktualny.first][aktualny.second] < 0) {
          najblizszy[(grid[aktualny.first][aktualny.second] + 1) * -1] = grid[aktualny.first][aktualny.second];
          
      }
      if(grid[aktualny.first + 1][aktualny.second] = 0) {
          grid[aktualny.first + 1][aktualny.second] = aktualnyI;
      }
  }
  
 

  return 0;
}