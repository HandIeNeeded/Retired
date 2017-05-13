/*************************************************************************
  >         File: 1425.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 29 Oct 2016 10:24:19 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 5e6 + 5;
const int MO = 1e9 + 7;

int Powd(int x, LL y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

namespace PM {
  static constexpr int N = 5e6 + 5;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array mark, prime, value;
  int count = 0;

  void GetPrime(int n, LL k) {
    value[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!mark[i]) {
        prime[count++] = i;
        value[i] = Powd(i, k);
      }
      for (int j = 0; j < count && i * prime[j] < N; ++j) {
        int now = i * prime[j];
        mark[now] = prime[j];
        value[now] = 1LL * value[prime[j]] * value[i] % MO;
        if (i % prime[j] == 0) {
          break;
        }
      }
    }
    for (int i = 2; i <= n; ++i) Add(value[i], value[i - 1]);
  }
}

int main() {
  int n, q;
  LL k;
  while (scanf("%d%lld%d\n", &n, &k, &q) > 0) {
    PM::GetPrime(n, k);
    int l, r;
    while (q--) {
      scanf("%d%d", &l, &r);
      int ans = PM::value[r];
      Add(ans, MO - PM::value[l - 1]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
