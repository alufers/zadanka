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
  for (int i = 0; i < ELEMENT_COUNT; i++) {
    sets[i] = i;
    sizes[i] = 1;
  }
  Union(1, 2);
  Union(2, 3);
  Union(8, 9);
  cout << "Find(3) = " << Find(3) << "\n";
  cout << "Find(9) = " << Find(9) << "\n";
  cout << "Union(3, 8)\n";
  Union(3, 8);
  cout << "Find(9) = " << Find(9) << "\n";
  return 0;
}