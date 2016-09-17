/*************************************************************************
  >         File: F.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 14 Sep 2016 09:42:08 PM CST
*************************************************************************/
#include <bits/stdc++.h>
constexpr int N = 1e6 + 5;
constexpr int MO = 1e9 + 7;

int y[N], fact[N], nFact[N];

int Powd(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

inline int Inverse(int x) { return Powd(x, MO - 2); }

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= k + 1; ++i) y[i] = Powd(i, k);
  std::transform(y + 1, y + k + 2, y, y + 1, [](auto a, auto b) {
    return (a + b) % MO;
  });
  fact[0] = nFact[0] = 1;
  int i = 1;
  std::transform(fact + 1, fact + k + 2, fact, fact + 1, [&i] (auto a, auto b) {
    return MO - 1LL * i++ * b % MO;
  });
  for (int i = 1; i <= k + 1; ++i) {
    nFact[i] = 1LL * (n - i) * nFact[i - 1] % MO;
  }
  int answer = 0;
  if (n <= k + 1) {
    std::cout << y[n] << std::endl;
  } else {
    auto preUp = nFact[k + 1];
    auto preDown = fact[k + 1];
    for (int i = 1; i <= k + 1; ++i) {
      int up = 1LL * preUp * (n - i + 1) % MO * Inverse(n - i) % MO;
      int down = 1LL * preDown * i % MO * Inverse(MO - (k + 2 - i)) % MO;
      answer += 1LL * up * Inverse(down) % MO * y[i] % MO;
      if (answer >= MO) answer -= MO;
      preUp = up, preDown = down;
    }
    std::cout << answer << std::endl;
  }
  return 0;
}
