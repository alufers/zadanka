#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;

    switch (type) {

    case 1:
      int num;
      cin >> num;
      q.push(num);

      break;
    case 0:
      if (q.size() == 0) {
        cout << "PUSTA KOLEJKA\n";
        break;
      }
      q.pop();
      break;
    case 2:
      if (q.size() == 0) {
        cout << "PUSTA KOLEJKA\n";
        break;
      }
      cout << q.front() << "\n";
      break;
    }
  }
  return 0;
}