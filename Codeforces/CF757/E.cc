/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri 13 Jan 2017 01:18:58 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e6 + 6;
const int MO = 1e9 + 7;
int dp[22][N], f[22][N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

void init() {
  for (int j = 0; j < N; ++j) {
    for (int i = 0; i <= 20; ++i) {
      if (j == 0) {
        dp[i][j] = i == 0 ? 1 : 2;
      } else {
        dp[i][j] = i == 0 ? 1 : f[i][j - 1];
      }
      for (int k = 0; k <= i; ++k) {
        Add(f[i][j], dp[k][j]);
      }
    }
  }
}

namespace PM {
  static constexpr int N = 1e3 + 5;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array mark, prime, mobius;
  int count = 0;
  std::vector<int> factor[N];

  void GetPrime() {
    factor[1].emplace_back(1);
    for (int i = 2; i < N; ++i) {
      if (!mark[i]) {
        prime[count++] = i;
        mobius[i] = MO - 1;
        factor[i].emplace_back(i);
      }
      for (int j = 0; j < count && i * prime[j] < N; ++j) {
        int now = i * prime[j];
        mark[now] = prime[j];
        mobius[now] = (MO - mobius[i]) % MO;
        factor[now] = factor[i];
        factor[now].emplace_back(prime[j]);
        if (i % prime[j] == 0) {
          mobius[now] = 0;
          factor[now].pop_back();
          break;
        }
      }
    }
  }
}

int main() {
  init();
  int q;
  scanf("%d", &q);
  PM::GetPrime();
  while (q--) {
    int r, c;
    scanf("%d%d", &r, &c);
    int ans = 1;
    for (int i = 0; i < PM::count && PM::prime[i] * PM::prime[i] <= c; ++i) {
      if (c % PM::prime[i] == 0) {
        int cnt = 0;
        while (c % PM::prime[i] == 0) {
          c /= PM::prime[i];
          cnt++;
        }
        ans = 1LL * ans * dp[cnt][r] % MO;
      }
    }
    if (c > 1) ans = 1LL * ans * dp[1][r] % MO;
    printf("%d\n", ans);
  }

  return 0;
}
