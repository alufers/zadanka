#include <iostream>
#include <vector>
using namespace std;

const int ELEMENT_COUNT = 1000 * 1000 + 1;
int sizes[ELEMENT_COUNT];
int sets[ELEMENT_COUNT];

int Find(int a) {

  if (sets[a] == a) {
    return a;
  }
  int root = Find(sets[a]);
  sets[a] = root;
  return root;
}

void Union(int a, int b) {
  int a_ = Find(a);
  int b_ = Find(b);
  if (a_ != b_) {
    if (sizes[a_] < sizes[b_]) {
      sets[a] = b_;
      sizes[a_] += sizes[b_];
    } else {
      sets[b] = a_;
      sizes[b_] += sizes[a_];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int zestawy = 0;
  cin >> zestawy;
  for (int k = 0; k < zestawy; k++) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < ELEMENT_COUNT; i++) {
      sets[i] = i;
      sizes[i] = 1;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a -= 1;
      b -= 1;
      Union(a, b);
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (Find(i) != Find(i + 1)) {
        cout << "NIE\n";
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "TAK\n";
    }
  }
}