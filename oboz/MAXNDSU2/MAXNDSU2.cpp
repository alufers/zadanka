#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector <int> vec;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  return 0;
}