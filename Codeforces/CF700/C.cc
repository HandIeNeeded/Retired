/*************************************************************************
  > File Name: C.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Sat 23 Jul 2016 01:31:52 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

template<int N, int M, typename Type>
struct MaxFlow{
  int edge, source, sink;
  int level[N], current[N];
  int first[N], next[M << 1], end[M << 1];
  Type cap[M << 1];
  const Type INF = ;

  void Init(int S, int T) {
    source = S, sink = T;
    edge = 1, memset(first, 0, sizeof(first));
  }

  void add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; end[edge] = y; cap[edge] = z;
  }

  void Add(int x, int y, Type z) {
    add(x, y, z);
    add(y, x, 0);
  }

  bool Bfs() {
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(source), level[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[end[go]]) {
        int y = end[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(Type x, Type flow) {
    if (x == sink || flow == 0) {
      return flow;
    }
    Type ans = 0, tmp = 0;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = end[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, min(flow, (Type) cap[go]))) > 0) {
        ans += tmp, flow -= tmp;
        cap[go] -= tmp, cap[go ^ 1] += tmp;
        if (flow == 0) {
          return ans;
        }
      }
    }
    return ans;
  }

  Type Dinic() {
    Type ans = 0;
    while (Bfs()) {
      memcpy(current, first, sizeof(first));
      ans += Dfs(source, INF);
    }	
    return ans;
  }
};
MaxFlow<10000, 10000, int> flow;

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < 2; i++) flow[i].init(a, b);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y) continue;
    flow[0].add(x, y, 1);
    flow[0].add(y, x, 1);
    flow[1].add(x, y, z);
    flow[1].add(y, x, z);
  }
  int path = flow[0].dinic();
  cerr << "Path: " << path << endl;
  if (path > 2) {
    cout << -1 << endl;
  }
  else {
    LL ans = flow[1].dinic();
    if (path == 0) {
      cout << 0 << endl << endl;
      return 0;
    }
    vector<int> res = flow[1].GetAns();
    cout << ans << endl;
    cout << path << endl;
    assert(res.size() == ans);
    for (int i = 0; i < path; i++) {
      cout << res[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
