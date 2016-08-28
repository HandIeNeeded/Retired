/*************************************************************************
  >         File: E.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 28 Aug 2016 08:42:27 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 1e5 + 5;
int a[N], L, n;
int dp[N][20];

void Init() {
  for (int i = 0; i < n; i++) {
    dp[i][0] = std::upper_bound(a + i, a + n, a[i] + L) - a - 1;
  }
  for (int step = 1; step < 20; step++) {
    for (int start = 0; start < n; start++) {
      dp[start][step] = dp[dp[start][step - 1]][step - 1];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::cin >> L;
  Init();
  //for (int i = 0; i < n; i++) {
  //  std::cerr << "i: " << i << std::endl;
  //  for (int j = 0; j < 4; j++) {
  //    std::cerr << dp[i][j] << ' ';
  //  }
  //  std::cerr << std::endl;
  //}
  int q;
  std::cin >> q;
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    if (a > b) std::swap(a, b);
    int lo = 0, hi = b - a;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      int now = a;
      for (int step = 0; step < 20; step++) {
        if (mid & (1 << step)) {
          now = dp[now][step];
        }
      }
      if (now >= b) hi = mid;
      else lo = mid;
    }
    std::cout << hi << std::endl;
  }
  return 0;
}
