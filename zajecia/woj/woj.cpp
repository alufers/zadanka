#include <algorithm>
#include <iostream>
//#include <pair>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  pair<int, int> populacja[n];
  // bool jestUBERMOCARSTWEM[n];
  vector<int> mozliwieNajlepsze;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    populacja[i] = make_pair(tmp, i);
    // jestUBERMOCARSTWEM[i] = true;
  }
  sort(populacja, populacja + n);
  for (int i = 0; i < n; i++) {
    int aktualnaPopulacja = populacja[i].first;
    // for (int b = 0; b < i; b++) {
    //  aktualnaPopulacja += populacja[b];
    //}
    bool jestSlabe = false;
    for (int k = 0; k < n; k++) {
      if (k == i)
        continue;
      if (aktualnaPopulacja >= populacja[k].first) {
        aktualnaPopulacja += populacja[k].first;
      } else {

        jestSlabe = true;
      }
    }
    if (!jestSlabe)
      mozliwieNajlepsze.push_back(populacja[i].second);
  }
  sort(mozliwieNajlepsze.begin(), mozliwieNajlepsze.end());
  for (int i = 0; i < mozliwieNajlepsze.size(); i++) {
    cout << (mozliwieNajlepsze[i] + 1) << "\n";
  }
  return 0;
}