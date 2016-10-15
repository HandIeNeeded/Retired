/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 06 Oct 2016 10:50:00 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
constexpr int N = 222222;
constexpr int MO = 1e9 + 7;

namespace FC {
  static constexpr int N = ::N;
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

int dp[N];
std::pair<int, int> bad[N];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  std::ios::sync_with_stdio(0);
  FC::GetFactorial();
  int h, w, n;
  std::cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    bad[i] = {x, y};
  }
  bad[n++] = {h, w};
  std::sort(bad, bad + n);
  for (int i = 0; i < n; ++i) {
    dp[i] = FC::C(bad[i].first + bad[i].second - 2, bad[i].first - 1);
    for (int j = 0; j < i; ++j) {
      if (bad[j].second > bad[i].second) continue;
      Add(dp[i], MO - 1LL * dp[j] * FC::C(bad[i].first - bad[j].first + bad[i].second - bad[j].second, bad[i].first - bad[j].first) % MO);
    }
  }
  std::cout << dp[n - 1] << std::endl;

  return 0;
}
