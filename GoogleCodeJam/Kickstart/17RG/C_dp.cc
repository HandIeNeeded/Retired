/*************************************************************************
  >         File: C_dp.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 22 Oct 2017 04:31:47 PM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 44;
int mp[N][N];
int dp[N][N][N][N];
int v[N][N][N][N];

void update(int &x, int y) {
  if (x == -1) x = y;
  else if (y != -1) x = std::min(x, y);
}

void init(int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int a = i + 1; a <= n; ++a) {
        for (int b = j + 1; b <= m; ++b) {
          int &ans = v[i][j][a][b];
          update(ans, v[i][j][a][b - 1]);
          update(ans, v[i][j][a - 1][b]);
          update(ans, mp[a - 1][b - 1]);
        }
      }
    }
  }
}

int get(int a, int b, int c, int d) {
  return v[a][b][c][d];
}

int solve(int a, int b, int c, int d) {
  if (a == c - 1 && b == d - 1) return 0;
  if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
  int& ans = dp[a][b][c][d];
  int min = get(a, b, c, d);
  for (int i = a + 1; i < c; ++i) {
    ans = std::max(ans, min + solve(a, b, i, d) + solve(i, b, c, d));
  }
  for (int j = b + 1; j < d; ++j) {
    ans = std::max(ans, min + solve(a, b, c, j) + solve(a, j, c, d));
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int t, cas = 1;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        for (int a = 0; a <= n; ++a) {
          for (int b = 0; b <= m; ++b) {
            dp[i][j][a][b] = v[i][j][a][b] = -1;
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> mp[i][j];
      }
    }
    init(n, m);
    std::cout << "Case #" << cas++ << ": " << solve(0, 0, n, m) << std::endl;
  }

  return 0;
}
