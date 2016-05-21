#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  int t, ca = 1;
  srand(time(0) * clock());
  t = 2;
  cout << t << endl;
  while (t--) {
    int x = rand() % 9 + 1;
    LL m = 1LL * rand() % 100000 * (rand() % 100000);
    int k = rand() % 10000 + 1;
    int c = rand() % k;
    cout << x << ' ' << m << ' ' << k << ' ' << c << endl;
  }
  return 0;
}



