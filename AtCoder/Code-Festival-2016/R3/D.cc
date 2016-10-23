/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 23 Oct 2016 08:39:58 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

const int N = 333;
char mp[N][N];
int h, w;
LL f[2][N][N], dp[N][N];
bool visited[N][N];

LL Dfs(int a, int b) {
  if (a == h || b == h) return 0;
  else if (visited[a][b]) return dp[a][b];
  else {
    visited[a][b] = 1;
    LL &ans = dp[a][b];
    ans = std::min(Dfs(a + 1, b), Dfs(a, b + 1));
    if (a < b) {
      ans += f[1][b - a][h - b];
    }
    else {
      ans += f[0][a - b][h - a];
    }
    return ans;
  }
}

LL Solve(int a) {
  int l = a, r = a + 1;
  memset(f, 0, sizeof(f));
  memset(dp, 0, sizeof(dp));
  memset(visited, 0, sizeof(visited));
  //l pushed more than r
  for (int i = 0; i < h; ++i) {
    //diff is i
    for (int y = 0; y < h; ++y) {
      int cost = y + i >= h ? 0 : mp[y][l] == mp[y + i][r];
      f[0][i][y + 1] = f[0][i][y] + cost;
    }
  }
  //l pushed less than r
  for (int i = 0; i < h; ++i) {
    for (int y = 0; y < h; ++y) {
      int cost = y + i >= h ? 0 : mp[y][r] == mp[y + i][l];
      f[1][i][y + 1] = f[1][i][y] + cost;
    }
  }
  for (int i = 0; i < h; ++i) assert(f[0][0][i] == f[1][0][i]);
  Dfs(0, 0);
  return dp[0][0];
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> h >> w;
  for (int i = 0; i < h; ++i) std::cin >> mp[i];
  LL ans = 0;
  for (int i = 0; i < w - 1; ++i) ans += Solve(i);
  std::cout << ans << std::endl;
  return 0;
}
