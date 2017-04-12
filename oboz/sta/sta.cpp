#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  stack<int> q;
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
        cout << "PUSTY STOS\n";
        break;
      }
      q.pop();
      break;
    case 2:
      if (q.size() == 0) {
        cout << "PUSTY STOS\n";
        break;
      }
      cout << q.top() << "\n";
      break;
    }
  }
  return 0;
}