/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 09 Sep 2016 09:02:41 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 5;
char mp[N][N];
using array4 = short[N][N][N][N];
array4 dp;

int cnt[N][N];
int n, m;

void Init() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (mp[i - 1][j - 1] == 'o');
    }
  }
}

int Ask(int x, int y, int p, int q) {
  x++, y++, p++, q++;
  int ans = cnt[p][q] - cnt[x - 1][q] - cnt[p][y - 1] + cnt[x - 1][y - 1];
  if (ans < 0) {
    std::cerr << "hehe" << x << ' ' << y << ' ' << p << ' ' << q << ' ' << ans << std::endl;
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> mp[i];
  Init();
  char a, b, c, d, ex, ey;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (mp[i][j] == 'E') {
    a = i, b = n - 1 - i;
    c = j, d = m - 1 - j;
    ex = i, ey = j;
  }
  for (int u = 0; u < n; ++u) {
    for (int d = 0; d < n; ++d) {
      for (int l = 0; l < m; ++l) {
        for (int r = 0; r < m; ++r) {
          int x, y, p, q;
          x =  ex - u, y = ey - l;
          p = ex + d, q = ey + r;
          dp[u + 1][d][l][r] = dp[u][d][l][r];
          dp[u][d + 1][l][r] = dp[u][d][l][r];
          dp[u][d][l + 1][r] = dp[u][d][l][r];
          dp[u][d][l][r + 1] = dp[u][d][l][r];
          if (x - 1 > d) {
            dp[u + 1][d][l][r] = Ask(x - 1, y, p, q);
          }
          if (p + 1 < n - u) {
            dp[u][d + 1][l][r] = Ask(x, y, p + 1, q);
          }
          if (y - 1 > r) {
            dp[u][d][l + 1][r] = Ask(x, y - 1, p, q);
          }
          if (q + 1 < m - l) {
            dp[u][d][l][r + 1] = Ask(x, y, p, q + 1);
          }
        }
      }
    }
  }
  std::cout << dp[a][b][c][d] << std::endl;
  return 0;
}
