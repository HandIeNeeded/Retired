/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu May  4 10:34:36 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

constexpr int N = 1e5 + 5;
std::vector<int> edges[N];
int now;
int f[N], vis[N], size[N];
using LL = long long;
LL sum[N], dia[N];
int length[N];
std::vector<int> ids[N];

int n, m, q;
int find (int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

int dis[2][N];

int bfs(int x, std::vector<int> &ids, int id, int &fuck) {
  ++now;
  int *distance = dis[id];
  vis[x] = now, distance[x] = 0;
  std::queue<int> q;
  q.push(x);
  ids.clear();
  while (q.size()) {
    x = q.front(); q.pop();
    ids.push_back(x);
    for (auto &y: edges[x]) {
      if (vis[y] == now) continue;
      distance[y] = distance[x] + 1;
      vis[y] = now;
      q.push(y);
    }
  }
  int best = -1;
  int mx = -1;
  for (auto &x: ids) {
    if (distance[x] > mx) {
      mx = distance[x];
      best = x;
    }
  }
  fuck = mx;
  return best;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) f[i] = i, size[i] = 1;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
    if (find(x) != find(y)) {
      int tx = find(x), ty = find(y);
      f[tx] = ty;
      size[ty] += size[tx];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      std::vector<int> ids;
      int x;
      int A = bfs(i, ids, 0, x);
      int B = bfs(A, ids, 0, x);
      bfs(B, ids, 1, x);
      dia[x] = x;
      for (auto &y: ids) {
        length[y] = std::max(dis[0][y], dis[1][y]);
      }
      ::ids[find(A)] = ids;
      x = find(A);
      std::sort(::ids[x].begin(), ::ids[x].end());
    }
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    std::cin >> x >> y;
    if (find(x) == find(y)) {
      std::cout << -1 << std::endl;
    } else {
      int tx = find(x), ty = find(y);
      int least = std::max(dia[tx], dia[ty]);
      std::cout << std::fixed << std::setprecision(10) << ans + 1 << std::endl;
    }
  }

  return 0;
}
