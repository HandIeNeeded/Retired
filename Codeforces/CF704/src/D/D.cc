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
pair<int, int> p[N];
int upX[N], upY[N], cntX[N], cntY[N];

template<int N, int M, typename Type>
struct MaxFlow{
  int edge, source, sink;
  int level[N], current[N];
  int first[N], next[M << 1], end[M << 1];
  Type cap[M << 1];
  const Type INF = 1e18;

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
MaxFlow<200005, 300005, LL> flow, tmp;

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  int r, b;
  cin >> n >> m;
  cin >> r >> b;
  if (r > b) swap(r, b);
  vector<int> X, Y;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
    X.push_back(x), Y.push_back(y);
  }
  sort(X.begin(), X.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());
  sort(Y.begin(), Y.end());
  Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
  for (int i = 0; i < n; i++) {
    int x, y;
    tie(x, y) = p[i];
    x = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
    y = lower_bound(Y.begin(), Y.end(), y) - Y.begin() + 1;
    p[i] = {x, y};
    cntX[x]++, cntY[y]++;
  }
  for (int i = 1; i <= X.size(); i++) upX[i] = cntX[i];
  for (int i = 1; i <= Y.size(); i++) upY[i] = cntY[i];
  for (int i = 0; i < m; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      x = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
      upX[x] = min(upX[x], y);
    }
    else {
      x = lower_bound(Y.begin(), Y.end(), x) - Y.begin() + 1;
      upY[x] = min(upY[x], y);
    }
  }
  int tot = X.size() + Y.size();
  int S = 0, T = tot + 1;
  int A = T + 1, B = T + 2;
  flow.Init(A, B);
  tmp.Init(S, T);
  bool bad = 0;
  LL sum = 0;
  for (int i = 1; i <= X.size(); i++) {
    int L = (cntX[i] - upX[i] + 1) / 2;
    int R = (cntX[i] + upX[i]) / 2;
    cerr << L << ' ' << R << endl;
    if (L > R) {
      bad = 1;
      break;
    }
    tmp.Add(S, i, R - L);
    flow.Add(A, i, L);
    flow.Add(S, B, L);
    flow.Add(S, i, R - L);
    sum += L;
  }
  for (int i = 1; i <= Y.size(); i++) {
    int L = (cntY[i] - upY[i] + 1) / 2;
    int R = (cntY[i] + upY[i]) / 2;
    if (L > R) {
      bad = 1;
      break;
    }
    cerr << L << ' ' << R << endl;
    tmp.Add(i + X.size(), T, R - L);
    flow.Add(A, T, L);
    flow.Add(i + X.size(), B, L);
    flow.Add(i + X.size(), T, R - L);
    sum += L;
  }
  if (bad) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    flow.Add(p[i].first, p[i].second + X.size(), 1);
    tmp.Add(p[i].first, p[i].second + X.size(), 1);
  }
  flow.Add(T, S, flow.INF);
  //check if it's fulfilled
  if (sum != flow.Dinic()) {
    cout << -1 << endl;
    return 0;
  }
  LL ans = tmp.Dinic();
  cout << ans * r + (n - ans) * b << endl;


  return 0;
}
