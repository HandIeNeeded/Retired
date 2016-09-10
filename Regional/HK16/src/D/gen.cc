#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  srand(time(0) * clock());
  int n = rand() % 50 + 4, m = rand() % 50 + 3;
  int k = rand() % 10 + 2;
  cout << n << ' ' << m << ' ' << k << endl;
  for (int i = 0; i < n; ++i) {
    cout << rand() % k << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << rand() % k << ' ';
  }
  cout << endl;
  for (int i = 0; i < m; ++i) {
    int l = rand() % n, r = rand() % n;
    if (l > r) swap(l, r);
    cout << l << ' ' << r << endl;
  }
  return 0;
}


