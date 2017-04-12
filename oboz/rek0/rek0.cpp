#include <iostream>
#include <map>
using namespace std;

map<long long, long long> cache;

long long f(long long n) {
   //cout <<"ZAPYT"<< n << "\n";
  if(cache.find(n) != cache.end()) {

    return cache[n];
  }

  if (n > 1) {
    long long result = f(n / 2) + f(n / 3) + f(n / 4) + f(n / 5) + f(n / 6) + f(n / 7);
    cache[n] = result;
    return result;
  } else if (n == 1) {
    return 6;
  } else {
    return 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cache[1] = 6;
  cache[0] = 1;
  long long n = 0;
  cin >> n;
  // f(1);
  cout << f(n);
  //cout << n;
  return 0;
}
