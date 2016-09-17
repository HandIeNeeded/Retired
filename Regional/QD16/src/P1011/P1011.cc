/*************************************************************************
  >         File: P1011.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 12:49:02 PM CST
*************************************************************************/
#include <bits/stdc++.h>
template<int N, int E, typename Type, Type INF>
class MaxFlow {
public:
  int edge, source, sink;
  int level[N], current[N];
  int first[N], next[E << 1], to[E << 1];
  Type cap[E << 1];

  void Init(int S, int T) {
    source = S, sink = T;
    edge = 1, memset(first, 0, sizeof(first));
  }

  void add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; 
    to[edge] = y; cap[edge] = z;
  }

  void Add(int x, int y, Type z) {
    add(x, y, z);
    add(y, x, 0);
  }

  Type Dinic() {
    Type ans = 0;
    while (Bfs()) {
      memcpy(current, first, sizeof(first));
      ans += Dfs(source, INF);
    }	
    return ans;
  }

private:
  bool Bfs() {
    std::queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(source), level[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[to[go]]) {
        int y = to[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(int x, Type flow) {
    if (x == sink || flow == 0) return flow;
    Type ans = 0, tmp;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = to[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, std::min(flow, cap[go]))) > 0) {
        ans += tmp, flow -= tmp;
        cap[go] -= tmp, cap[go ^ 1] += tmp;
        if (flow == 0) break;
      }
    }
    return ans;
  }
};
MaxFlow<10005, 200005, int, int(1e9)> solver;
const int N = 10005;
const int M = 100005;
std::vector<int> edges[N];
int A[M], B[M], C[M];
int dp[2][N];

void Bfs(int start, int* dp) {
  std::fill(dp, dp + N, -1);
  std::queue<int> q({start});
  dp[start] = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (auto &y: edges[x]) {
      if (dp[y] >= 0) continue;
      dp[y] = dp[x] + 1;
      q.emplace(y);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    solver.Init(1, n);
    for (int i = 1; i <= n; ++i) edges[i].clear();
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      A[i] = x, B[i] = y, C[i] = z;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    Bfs(1, dp[0]), Bfs(n, dp[1]);
    assert(dp[0][n] == dp[1][1]);
    int distance = dp[0][n];
    for (int i = 0; i < m; ++i) {
      int x = A[i], y = B[i], z = C[i];
      if (dp[0][x] + 1 + dp[1][y] == distance || dp[0][y] + 1 + dp[1][x] == distance) {
        solver.Add(x, y, z);
        solver.Add(y, x, z);
      }
    }
    printf("%d\n", solver.Dinic());
  }
  return 0;
}
