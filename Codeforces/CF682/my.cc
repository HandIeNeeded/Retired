#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int s1[6], s2[6];

int main() {
  int t, ca = 1;
  long long n, m, sum = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int hi = m + i;
    int lo = 1 + i;
    sum += (hi / 5) - (lo / 5);
    if (lo % 5 == 0) sum++;
  }

  cout << sum << endl;
  return 0;
}


