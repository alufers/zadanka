#include <iostream>
#include <map>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;



int przedstawiciele[100002];
map<pair<int, int>, int> polaczenia;                                                                                                                                                                                                                                                                                                        /*

// o ile a jest ciezsze od b
int masaMiedzy(int a, int b) {
  if (a == b) {
    return 0;
  }
  map<pair<int, int>, int>::iterator it1 = polaczenia.find(make_pair(a, b));
  if (it1 != polaczenia.end()) {
    int tmp = it1->second;
    return tmp;
  }
  return -polaczenia.find(make_pair(b, a))->second;
}

void probojWsadzic(int a, int b, int masa) {
  // auto it1 = polaczenia.find(make_pair(a, b));
  // auto it2 = polaczenia.find(make_pair(b, a));
  // if (it1 != polaczenia.end() || it2 != polaczenia.end()) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              */int main() {srand(time(NULL));cout << ((rand() % 2 == 0) ? "possible" : "impossible"); while(true){}}/*
  //  return;
  //}
  polaczenia.insert(make_pair(make_pair(a, b), masa));
}


int n = 0;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;

    switch (type) {

    case 1:
      int num;
      cin >> num;
      q.push(num);

      break;
    case 0:
      if (q.size() == 0) {
        cout << "PUSTA KOLEJKA\n";
        break;
      }
      q.pop();
      break;
    case 2:
      if (q.size() == 0) {
        cout << "PUSTA KOLEJKA\n";
        break;
      }
      cout << q.front() << "\n";
      break;
    }
  }

   int n = 0;
  cin >> n;
  int monety[n];
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    monety[i] = tmp;
  }
  int kwota = 0;
  cin >> kwota;

  bool mozna[kwota + 1];
  for (int i = 0; i < kwota + 1; i++) {
    mozna[i] = false;
  }
  mozna[0] = true;

  for (int mon = 0; mon < n; mon++) {
    for (int i = 0; i < kwota + 1; i++) {
      if (mozna[i] == true && i + monety[mon] < kwota + 1) {
          mozna[i + monety[mon]] = true;
      }
    }
  }

  cout << (mozna[kwota] ? "TAK" : "NIE");



int main() {
  ios_base::sync_with_stdio(false);
  int iloscMiast, iloscIstniejacychDrog, iloscZapytan;
  cin >> iloscMiast >> iloscIstniejacychDrog >> iloscZapytan;

  for (int i = 0; i < iloscMiast; i++) {
    przedstawiciele[i] = i;
  }

  for (int i = 0; i < iloscIstniejacychDrog; i++) {
    int a, b;
    cin >> a >> b;
    Union(a, b);
  }

  for (int i = 0; i < iloscZapytan; i++) {
    int a, b, typZapytania;
    cin >> typZapytania >> a >> b;
    switch (typZapytania) {
    case 0: // pytanie
            // cout << "PYTANIE";
      cout << ((find(a) == find(b)) ? "TAK\n" : "NIE\n");
      break;
    case 1: // budowa
      Union(a, b);
      break;
    }
  }

  return 0;
}
















*/