#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n = 0;
  cin >> n;
  int max = 0;
  for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      if(tmp > max) {
        max = tmp;
      }
  }
  cout << max;
  return 0;
}