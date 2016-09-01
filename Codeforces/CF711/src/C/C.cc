/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 29 Aug 2016 09:54:35 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

const int N = 111;
LL dp[N][N][N];
int color[N], mp[N][N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  
  for (int i = 1; i <= n; i++) std::cin >> color[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> mp[i][j];
    }
  }

  //idx beauty color
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int c = 0; c <= m; c++) {
        dp[i][j][c] = 1LL << 60;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int idx = 1; idx <= n; idx++) {
    for (int beauty = 0; beauty <= k; beauty++) {
      for (int color = 0; color <= m; color++) {
        if (::color[idx] == 0) {
          for (int newColor = 1; newColor <= m; newColor++) {
            int diff = color != newColor;
            dp[idx][beauty + diff][newColor] = std::min(dp[idx][beauty + diff][newColor], dp[idx - 1][beauty][color] + mp[idx][newColor]);
          }
        }
        else {
          int diff = ::color[idx] != color;
          dp[idx][beauty + diff][::color[idx]] = std::min(dp[idx][beauty + diff][::color[idx]], dp[idx - 1][beauty][color]);
        }
      }
    }
  }
  LL answer = 1LL << 60;
  for (int color = 1; color <= m; color++) {
    answer = std::min(answer, dp[n][k][color]);
  }
  if (answer == 1LL << 60) answer = -1;
  std::cout << answer << std::endl;
  return 0;
}
