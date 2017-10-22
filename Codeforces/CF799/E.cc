/*************************************************************************
  >         File: E.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri May 12 01:29:45 2017
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

#define MST(a, b) memset(a, b, sizeof(a))
using LL = long long;

constexpr int N = 2e5 + 5;
constexpr int M = 2e6 + 5;
constexpr LL inf = 0x3f3f3f3f3f3f3f3f;
LL cost[N];

struct MinCostFlow{
  LL pre[N], dp[N], vis[N], source, sink;
  LL fi[N], ne[M << 1], en[M << 1], cap[M << 1], cost[M << 1], edge;

  void init(int S, int T) {
    source = S, sink = T;
    MST(fi, 0), edge = 1;
  }

  void _add(int x, int y, LL z, LL w) {
    ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z, cost[edge] = w;
  }

  void add(int x, int y, LL z, LL w) {
    _add(x, y, z, w);
    _add(y, x, 0, -w);
  }

  bool spfa() {
    MST(dp, 0x3f);
    std::queue<int> q;
    q.push(source), vis[source] = 1, dp[source] = pre[source] = 0;

    while (q.size()) {
      int x = q.front(); q.pop();
      for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
        int y = en[go];
        if (dp[y] > dp[x] + cost[go]) {
          dp[y] = dp[x] + cost[go];
          pre[y] = go;
          if (!vis[y]) {
            vis[y] = 1;
            q.push(y);
          }
        }
      }
      vis[x] = 0;
    }
    return dp[sink] != inf;
  }

  std::pair<LL, LL> minCost() {
    LL cost = 0, flow = 0;
    while (spfa()) {
      //if (dp[sink] >= 0) break; 最小费用流(不要求最大流)
      LL tmp = inf;
      for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
        tmp = std::min(tmp, cap[go]);
      }
      for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
        cap[go] -= tmp;
        cap[go ^ 1] += tmp;
      }
      cost += tmp * dp[sink];
      flow += tmp;
    }
    return {cost, flow};
  }
}flow;

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) std::cin >> cost[i + 1];
  int s = n + 1, t = s + 1, ss = t + 1;
  int A = ss + 1, B = A + 1;
  int S = B + 1, T = S + 1;
  flow.init(S, T);
  flow.add(t, s, inf, 0);
  flow.add(s, ss, m, 0);
  for (int i = 1; i <= n; ++i) flow.add(ss, i, 1, 0);
  std::vector<int> like[2];
  for (int i = 0; i < 2; ++i) {
    int x;
    std::cin >> x;
    int target = i == 0 ? A : B;
    for (int j = 0; j < x; ++j) {
      int y;
      std::cin >> y;
      like[i].push_back(y);
      flow.add(y, target, 1, cost[y]);
    }
  }
  flow.add(A, t, inf, 0);
  flow.add(B, t, inf, 0);
  flow.add(A, T, k, 0);
  flow.add(B, T, k, 0);
  flow.add(S, t, k, 0);
  flow.add(S, t, k, 0);
  LL ans = -1;
  auto answer = flow.minCost();
  std::cerr << "# answer.first # is " << answer.first << std::endl;
  std::cerr << "# answer.second # is " << answer.second << std::endl;
  if (answer.second == m) {
    ans = answer.first;
  }
  for (int i = 0; i < 2; ++i) {
    std::sort(like[i].begin(), like[i].end());
  }
  std::vector<int> bothLike(std::max(like[0].size(), like[1].size()));
  int size = std::set_intersection(like[0].begin(), like[0].end(), like[1].begin(), like[1].end(), bothLike.begin()) - bothLike.begin();
  if (size < k) {
    //assert(answer.second < m);
  }
  std::cout << ans << std::endl;

  return 0;
}
