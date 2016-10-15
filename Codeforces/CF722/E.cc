/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 06 Oct 2016 09:03:58 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
constexpr int N = 2222;
constexpr int K = 2e5 + 5;
constexpr int MO = 1e9 + 7;

std::pair<int, int> bad[N];
std::vector<int> values;
std::vector<LL> dp[N];

namespace FC {
  static constexpr int N = K;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array factorial, inverse, fInverse;

  void GetFactorial() {
    inverse[0] = 0; inverse[1] = factorial[0] = 1;
    fInverse[0] = fInverse[1] = 1;
    for (int i = 1; i <= N - 1; ++i) factorial[i] = 1LL * i * factorial[i - 1] % MO;
    for (int i = 2; i <= N - 1; ++i) inverse[i] = 1LL * (MO - MO / i) * inverse[MO % i] % MO;
    for (int i = 2; i <= N - 1; ++i) fInverse[i] = 1LL * fInverse[i - 1] * inverse[i] % MO;
  }

  int C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return 1LL* factorial[a] * fInverse[b] % MO * fInverse[a - b] % MO;
  }
}

int Powd(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k, s;
  std::cin >> n >> m >> k >> s;
  while (s > 1) values.emplace_back(s), s = (s + 1) / 2;
  values.emplace_back(1);
  for (int i = 0; i < k; ++i) {
    int x, y;
    std::cin >> x >> y;
    bad[i] = {x, y};
  }
  std::sort(bad, bad + k);
  if (bad[k - 1] != std::pair<int, int> {n, m}) bad[k++] = {n, m};



  return 0;
}
