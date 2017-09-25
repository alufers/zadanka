#include <iostream>

using namespace std;
const int M = 1024 * 1024;
int w[M * 2];
void insert(int x, int val) { /* val==1 to wstawianie, val==-1 to usuwanie */
  int v = M + x;
  w[v] += val;
  while (v != 1) {
    v /= 2;
    w[v] = w[2 * v] + w[2 * v + 1];
  }
}
int query(int a, int b) {
  int va = M + a, vb = M + b;
  /* Skrajne przedziały do rozkładu. */
  int wyn = w[va];
  if (va != vb)
    wyn += w[vb];
  /* Spacer aż do momentu spotkania. */
  while (va / 2 != vb / 2) {
    if (va % 2 == 0)
      wyn += w[va + 1]; /* prawa bombka na lewej ścieżce */
    if (vb % 2 == 1)
      wyn += w[vb - 1]; /* lewa bombka na prawej ścieżce */
    va /= 2;
    vb /= 2;
  }
  return wyn;
}
int main() {
  ios_base::sync_with_stdio(false);
  int nZ;
  cin >> nZ;

  while (true) {
    char op;
    int a, b;
    cin >> op >> a >> b;
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
      insert(a, b);
      break;
    case 'S':
      cout << query(a, b) << "\n";
      break;
    }
  }
  return 0;
}