/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 20 Oct 2016 09:34:57 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int dp[2][555], pre[2][555], a[555];

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::fill(dp[0], dp[0] + k + 1, 1234567);
  dp[0][0] = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k + 1; ++j) {
      int tmp = dp[cur][k - j] + std::max(0, a[i] - j);
      if (tmp < dp[cur ^ 1][j]) {
        dp[cur ^ 1][
      }
    }
  }

  return 0;
}
