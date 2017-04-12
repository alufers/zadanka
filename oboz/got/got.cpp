#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

long naIleKombinacjiPodzbior(int *arr, int n, int start, int koniec) {
  if (start == koniec) {
    return 1;
  }
  
}

int main() {
  ios_base::sync_with_stdio(false);

  int n = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arr[i] = tmp;
  }

  return 0;
}
