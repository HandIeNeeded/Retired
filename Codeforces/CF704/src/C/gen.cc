#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int cnt[100];

int main() {
  ios::sync_with_stdio(0);
  srand(time(0) * clock());
  int n = rand() % 5 + 10, m = rand() % 10 + 30;
  cout << n << ' ' << m << endl;
  for (int i = 0; i < n; i++) {
    int x = rand() % 2 + 1;
    if (x == 1) {
      int x = rand() % m + 1;
      while (cnt[x] == 2) x = rand() % m + 1;
      cout << 1 << ' ' << x << endl;
      cnt[x]++;
    }
    else {
      int x = rand() % m + 1;
      int y = rand() % m + 1;
      while (cnt[x] == 2) x = rand() % m + 1;
      while (cnt[y] == 2) y = rand() % m + 1;
      cnt[x]++, cnt[y]++;
      cout << 2 << ' ' << x << ' ' << y << endl;
    }
  }
  return 0;
}


