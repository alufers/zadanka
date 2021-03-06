#include <iostream>

using namespace std;
const int M = 1024 * 1024;
int w[M * 2];
void insert(int x, int val) { /* val==1 to wstawianie, val==-1 to usuwanie */

  if (val == -1 && w[M + x] == 0) {
    cout << "brak\n";
    return;
  }
  if (val == 1 && w[M + x] != 0) {
      return;
  }
  int v = M + x;
  w[v] += val;
  while (v != 1) {
    v /= 2;
    w[v] = w[2 * v] + w[2 * v + 1];
  }
}
void query(int x) {
  int a = 1;

  if (w[1] < x) {
    cout << "brak\n";
    return;
  }
  while (a < M) {
    if (w[a * 2] < x) {
      x -= w[a * 2];
      a = a * 2 + 1;
    } else {
      a = a * 2;
    }
  }

  cout << (a - M) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  int nZ;
  cin >> nZ;

  while (true) {
    char op;
    int a;
    cin >> op >> a;
    // cout << op << "\n";
    if (op == 'K') {
      nZ--;
      if (nZ == 0)
        break;
      for (int i = 0; i < 2 * M; i++) {
        w[i] = 0;
      }
    }
    switch (op) {
    case 'A':
      insert(a, 1);
      break;
    case 'E':
      insert(a, -1);
      break;
    case 'S':
      query(a);
      break;
    }
  }
  return 0;
}