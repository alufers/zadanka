#include <algorithm>
#include <iostream>
using namespace std;

void zestaw(int i) {
  int n = 0;
  cin >> n;
  long zestaw[n];
  for (int k = 0; k < n; k++) {
    long tmp;
    scanf("%ld", &tmp);

    zestaw[k] = tmp;
  }
  std::sort(zestaw, zestaw + n);
  for (int k = 0; k < n - 2; k++) {
    if (zestaw[k] == zestaw[k + 1] && zestaw[k] == zestaw[k + 2]) {
      printf("TAK\n");
      return;
    }
  }
  /*for (int k = 0; k < n; k++) {

    int powt = 0;
    for (int m = 0; m <= k; m++) {
      if (zestaw[m] == zestaw[k]) {
        powt++;
        if (powt >= 3) {

          printf("TAK\n");
          return;
        }
      }
    }
  }*/
  printf("NIE\n");
}
int main() {
  int q;
  // cin >> q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    zestaw(i);
  }
  return 0;
}