/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Tue 13 Sep 2016 11:20:02 PM CST
*************************************************************************/
#include <bits/stdc++.h>
constexpr int N = 1e5 + 5;
std::vector<std::pair<int, int>> edges[N];
int dp[N], vis[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    edges[x].emplace_back(y, z);
    edges[y].emplace_back(x, z);
  }
  std::queue<int> q;
  q.emplace(1);
  dp[1] = 1;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (auto &p: edges[x]) {
      int y, color;
      std::tie(y, color) = p;
      if (!dp[y]) {
        q.emplace(y);
        dp[y] = dp[x] + 1;
        Dfs(y, color, q);
      }
    }
  }
  std::cout << dp[n] - 1 << std::endl;
  return 0;
}
