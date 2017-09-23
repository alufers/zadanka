#include <iostream>

using namespace std;

const int ELEMENT_COUNT = 7006;
int sizes[ELEMENT_COUNT];
int sets[ELEMENT_COUNT];

int Find(int a) {

    if (sets[a] == a) {
        return a;
    }
    int root = Find(sets[a]);
    // sets[a] = root;
    return root;
}

void Union(int a, int b) {
    int a_ = Find(a);
    int b_ = Find(b);
    if (a_ != b_) {
        if (sizes[a_] < sizes[b_]) {
            sets[a_] = b_;
            sizes[a_] += sizes[b_];
        } else {
            sets[b_] = a_;
            sizes[b_] += sizes[a_];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    while (true) {
        int iloscLam, iloscZdarzen;
        cin >> iloscLam >> iloscZdarzen;
        cout << iloscLam << iloscZdarzen << "\n";
        if (iloscLam == 0 && iloscZdarzen == 0) { // zakoncz program
            return 0;
        }
        for (int i = 0; i < iloscZdarzen; i++) {
            char typ;
            int a, b;
            cin >> typ >> a >> b;
            cout << typ;
            
            switch (typ) {
            case '?':
                break;
            case '!':
                break;
            default:
                // cout << "???????????????\n?\n";
                break;
            }
        }
    }
    return 0;
}