/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 10:07:26 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

const int N = 1005;
const int M = 10005;
const int INF = 1e9 + 7;
std::vector<std::pair<int, int>> edges[N];
int n, m, L, first, last;
int u[M], v[M], w[M], vis[N], pre[N];
LL dp[N], cnt[N];

void NO() {
  std::cout << "NO" << std::endl;
  exit(0);
}

void Dijkstra(int start, int cheat = INF) {
  std::fill(dp, dp + n, -1);
  std::fill(vis, vis + n, 0);
  dp[start] = 0;
  std::priority_queue<std::pair<LL, int>, std::vector<std::pair<LL, int>>, std::greater<std::pair<LL, int>>> q;
  q.emplace(dp[start], start);
  while (!q.empty()) {
    int value, x;
    std::tie(value, x) = q.top(); q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto &p: edges[x]) {
      int y, v, add = 0;
      std::tie(y, v) = p;
      if (v == 0) v = cheat, add = 1;
      if (dp[y] == -1 || dp[y] > dp[x] + v) {
        dp[y] = dp[x] + v;
        cnt[y] = cnt[x] + add;
        pre[y] = x;
        q.emplace(dp[y], y);
      }
      else if (dp[y] == dp[x] + v && cnt[y] > cnt[x] + add) {
        cnt[y] = cnt[x] + add;
        pre[y] = x;
        q.emplace(dp[y], y);
      }
    }
  }
}

std::map<std::pair<int, int>, int> history;
std::set<int> hasTo;

void Modify() {
  int now = last;
  while (now != first) {
    int x = pre[now], y = now;
    if (x > y) std::swap(x, y);
    int idx = history[{x, y}];
    if (w[idx] == 0) {
      hasTo.insert(idx);
    }
    now = pre[now];
  }
  if (hasTo.size()) {
    auto idx = *hasTo.begin();
    w[idx] = L - dp[last] + 1;
    for (auto &y: hasTo) {
      if (y != idx) w[y] = 1;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> m >> L >> first >> last;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    u[i] = x, v[i] = y, w[i] = z;
    if (x > y) std::swap(x, y);
    history[{x, y}] = i;
    edges[x].emplace_back(y, z);
    edges[y].emplace_back(x, z);
  }
  Dijkstra(first);
  std::cerr << "# dp[last] # is " << dp[last] << std::endl;
  if (dp[last] < 0 || dp[last] < L) {
    NO();
  } else if (dp[last] == L) {
    std::cout << "YES" << std::endl;
    for (int i = 0; i < m; ++i) {
      if (w[i] == 0) w[i] = INF;
      std::cout << u[i] << ' '  << v[i] << ' ' << w[i] << std::endl;
    }
  } else {
    Dijkstra(first, 1);
    if (dp[last] > L) NO();
    std::cout << "YES" << std::endl;
    Modify();
    for (int i = 0; i < m; ++i) {
      if (w[i] == 0) w[i] = INF;
      std::cout << u[i] << ' '  << v[i] << ' ' << w[i] << std::endl;
    }
  }
  return 0;
}
