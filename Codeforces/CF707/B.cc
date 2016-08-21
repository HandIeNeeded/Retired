/*************************************************************************
  >         File: B.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 20 Aug 2016 09:40:20 PM CST
*************************************************************************/
#include <bits/stdc++.h>

using pii = std::pair<long long, int>;
const int N = 100000 + 5;
std::vector<int> edges[N], val[N];
int visited[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  if (k == 0 || k == n) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    edges[x].push_back(y);
    edges[y].push_back(x);
    val[x].push_back(z);
    val[y].push_back(z);
  }
  int ans = INT_MAX;
  for (int i = 0; i < k; i++) {
    int x;
    std::cin >> x;
    visited[x] = 1;
  }
  for (int i = 1; i <= n; i++) if (visited[i]) {
    int x = i;
    for (int j = 0; j < edges[x].size(); j++) {
      int y = edges[x][j];
      int z = val[x][j];
      if (!visited[y]) {
        ans = std::min(ans, z);
      }
    }
  }
  if (ans == INT_MAX) ans = -1;
  std::cout << ans << std::endl;
  return 0;
}
