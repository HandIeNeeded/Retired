#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int t, ca = 1;
  t = 2;
  cout << t << endl;
  srand(time(0) % clock());
  REP(i, t) {
    int n = rand() % 15 + 3;
    int k = rand() % 200 + 2;
    cout << n << ' ' << k << endl;
    REP(i, n) {
      cout << rand() % 200 + 1 << ' ';
    }
    cout << endl;
    REP(i, n) {
      int x;
      if (rand() % 7 < 2) x = 1;
      else x = 0;
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}



