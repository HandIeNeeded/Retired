/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 20 Aug 2016 01:20:12 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 64;
int dp[N + 1][2], pre[N + 1][2];

int main() {
  std::ios::sync_with_stdio(0);
  using LL = unsigned long long;
  LL a, b;
  std::cin >> a >> b;
  std::bitset<N> A(a), B(b);
  dp[0][0] = 1;
  for (int bit = 0; bit < N; bit++) {
    for (int add = 0; add < 2; add++) if (dp[bit][add]) {
      for (int a = 1; a >= 0; a--) {
        for (int b = 0; b < 2; b++) {
          int c = a + b + add;
          int d = c >> 1;
          c &= 1;
          if ((a ^ b) == B.test(bit) && c == A.test(bit)) {
            dp[bit + 1][d] = 1;
            pre[bit + 1][d] = a + (add << 1);
          }
        }
      }
    }
  }
  if (dp[N][0]) {
    LL x = 0;
    int add = 0;
    for (int bit = N - 1; bit >= 0; bit--) {
      x |= (1ULL * pre[bit + 1][add] & 1) << bit;
      add = (pre[bit + 1][add] & 2) >> 1;
    }
    std::cout << x << ' ' << a - x << std::endl;
  }
  else {
    std::cout << -1 << std::endl;
  }
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
