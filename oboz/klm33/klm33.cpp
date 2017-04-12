#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int a;
  cin >> a >> a;
  string wzorzec, txt;
  cin >> wzorzec >> txt;
  int currentI = 0;
  for(int i = 0; i < txt.size(); i++) {
    if(txt[i] == wzorzec[currentI]) {
        currentI++;
    } else {
        currentI = 0;
    }
  }
  cout << currentI << "\n";
  return 0;
}