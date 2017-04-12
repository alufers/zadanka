#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> vec;
  int liczbaOperacji = 0;
  cin >> liczbaOperacji;
  for (int i = 0; i < liczbaOperacji; i++) {
    string op;
    cin >> op;
    if (op == "push") {
      int tmp;
      cin >> tmp;
      vec.insert(vec.begin(), tmp);
    } else if (op == "top") {
      if (vec.size() == 0) {
        continue;
      }
      cout << vec[vec.size() - 1] << "\n";
    } else if (op == "pop") {
      if (vec.size() == 0) {
        continue;
      }
      vec.pop_back();
    }
  }
  cout << "all done\n";
  return 0;
}