#include <iostream>

using namespace std;

int _$(int _$) { return _$ * _$; }

int $(int _) {
  if (_ == 0)
    return 2;
  if (_ % 2 == 0) {
    return _$($(_ / 2));
  } else {
      return ($((_ - 1)));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  cout << $(n);
  return 0;
}