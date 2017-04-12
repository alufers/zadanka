#include <iostream>
#include <cstdio>
using namespace std;
int k, n;
int wyw = 0;
int fib(int i) {
  if (wyw < k) {
    //cout << i << "\n";
    printf("%d\n", i);
  } else {
      return 234;
  }
  wyw++;
  if (i == 0) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  return fib(i - 1) + fib(i - 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  fib(n);
  return 0;
}