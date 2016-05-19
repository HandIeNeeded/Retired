#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int t, ca = 1;
  t = 10;
  cout << t << endl;
  srand(time(0) % clock());
  REP(i, t) {
    int n = rand() % 50 + 3, m = rand() % 50 + 3;
    if (rand() & 1) cout << "-";
    REP(i, n) cout << rand() % 10;
    cout << ' ';
    if (rand() & 1) cout << "-";
    REP(i, m) cout << rand() % 10;
    cout << endl;
  }
  return 0;
}



