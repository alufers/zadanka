#include <iostream>

using namespace std;

int main() {
  double masa = 0, wzrost = 0;
  cin >> masa >> wzrost;
  double bmi = masa / (wzrost * wzrost);
 // cout << std::fixed << setprecision(6) << bmi << "\n";
 printf("%.6f\n", bmi);
  if (bmi < 20) {
    cout << "NIEDOWAGA";
  } else if (bmi >= 20 && bmi <= 25) {
    cout << "NORMA";
  } else if (bmi > 25 && bmi <= 30) {
    cout << "NADWAGA";
  } else if(bmi > 30) {
      cout << "OTYLOSC";
  }
  return 0;
}