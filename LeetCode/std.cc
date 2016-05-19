#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
  int n;
  cin >> n;
  REP(i, n) cin >> a[i];
  sort(a, a + n);
  REP(i, n) cout << a[i] << ' ';
  cout << endl;
  return 0;
}



