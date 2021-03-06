/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 08 Aug 2016 11:12:22 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
char colors[3] = "rb";
int idx[N];
pair<int, int> p[N];

template<int N, int E, typename Type, Type INF>
class MaxFlow {
public:
  int edge, node, bridge, src, dst, source, sink;
  int level[N], current[N];
  int first[N], next[E << 1], to[E << 1];
  Type cap[E << 1], hasTo;

  int Node() { return node++; }

  void Init() {
    node = 4, edge = 1;
    hasTo = src = 0, dst = 1, source = 2, sink = 3;
    memset(first, 0, sizeof(first));
    bridge = Add(sink, source, INF);
  }

  int add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; 
    to[edge] = y; cap[edge] = z;
    return edge;
  }

  int Add(int x, int y, Type z) {
    add(y, x, 0);
    return add(x, y, z);
  }

  void LRAdd(int x, int y, Type L, Type R) {
    if (L == 0) Add(x, y, R);
    else {
      hasTo += L;
      Add(src, y, L);
      Add(x, dst, L);
      Add(x, y, R - L);
    }
  }

  Type Dinic() {
    while (Bfs(src, dst)) Dfs(src, dst, INF);
    if (hasTo != GetFlow(src)) return -1;

    while (Bfs(source, sink)) Dfs(source, sink, INF);
    return GetFlow(source);
  }

private:
  Type GetFlow(int x) {
    Type ans = 0;
    for (int go = first[x]; go; go = next[go]) if ((go ^ 1) != bridge) ans += cap[go ^ 1];
    return ans;
  }

  bool Bfs(int source, int sink) {
    queue<int> q;
    fill(level, level + node, 0);
    q.push(source), level[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = current[x] = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[to[go]]) {
        int y = to[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(int x, int sink, Type flow) {
    if (x == sink || flow == 0) return flow;
    Type ans = 0, tmp;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = to[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, sink, min(flow, cap[go]))) > 0) {
        ans += tmp, flow -= tmp;
        cap[go] -= tmp, cap[go ^ 1] += tmp;
        if (flow == 0) break;
      }
    }
    return ans;
  }
};
MaxFlow<2 * N, 7 * N, int, 1 << 30> net;

int main() {
  ios::sync_with_stdio(0);
  int n, m, r, b;
  cin >> n >> m >> r >> b;
  if (r > b) {
    swap(r, b), swap(colors[0], colors[1]);
  }
  map<int, int> mp[2], cnt[2], up[2];
  net.Init();
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (!mp[0].count(x)) mp[0][x] = net.Node();
    if (!mp[1].count(y)) mp[1][y] = net.Node();
    p[i] = {mp[0][x], mp[1][y]};
    cnt[0][x]++, cnt[1][y]++;
  }
  for (int i = 0; i < 2; i++) up[i] = cnt[i];
  for (int i = 0; i < m; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    type--;
    if (!up[type].count(x)) continue;
    up[type][x] = min(up[type][x], y);
  }
  for (int j = 0; j < 2; j++) {
    for (auto a = cnt[j].begin(), b = up[j].begin(); a != cnt[j].end(); a++, b++) {
      int A = (*a).second, B = (*b).second;
      int L = (A - B + 1) / 2;
      int R = (A + B) / 2;
      if (L > R) {
        cout << -1 << endl;
        return 0;
      }
      if (j == 0) {
        net.LRAdd(net.source, mp[0][(*a).first], L, R);
      }
      else {
        net.LRAdd(mp[1][(*a).first], net.sink, L, R);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    idx[i] = net.Add(p[i].first, p[i].second, 1);
  }
  int ans = net.Dinic();
  if (ans < 0) {
    cout << -1 << endl;
    return 0;
  }
  string res = string(n, '#');
  for (int i = 0; i < n; i++) res[i] = colors[net.cap[idx[i]]];
  cout << 1LL * r * ans + 1LL * (n - ans) * b << endl;
  cout << res << endl;
  return 0;
}
