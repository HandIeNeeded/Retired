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
pair<int, int> p[N];
map<pair<int, int>, vector<int>> mp;
int cntX[N], cntY[N], upX[N], upY[N];
int n, m, r, b, K;

template<int N, int M, typename Type>
struct MaxFlow{
  int edge, source, sink;
  int level[N], current[N];
  int first[N], next[M << 1], to[M << 1];
  Type cap[M << 1];
  const Type INF = 1e18;

  void Init(int S, int T) {
    source = S, sink = T;
    edge = 1, memset(first, 0, sizeof(first));
  }

  void add(int x, int y, Type z) {
    next[++edge] = first[x]; first[x] = edge; to[edge] = y; cap[edge] = z;
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
      for (int go = first[x]; go; go = next[go]) if (cap[go] > 0 && !level[to[go]]) {
        int y = to[go];
        level[y] = level[x] + 1;
        q.push(y);
      }
    }
    return level[sink];
  }

  Type Dfs(int x, Type flow) {
    if (x == sink || flow == 0) {
      return flow;
    }
    Type ans = 0, tmp = 0;
    for (int &go = current[x]; go; go = next[go]) if (cap[go] > 0) {
      int y = to[go];
      if (level[y] == level[x] + 1 && (tmp = Dfs(y, min(flow, cap[go]))) > 0) {
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

  map<pair<int, int>, int> GetCutEdges() {
    map<pair<int, int>, int> ans;
    int sum = 0;
    for (int i = 1; i <= K; i++) {
      for (int go = first[i]; go; go = next[go]) if (!(go & 1)) {
        if (to[go] <= K && to[go] >= 1 && cap[go] == 0) {
          ans[make_pair(i, to[go])]++;
          sum++;
        }
      }
    }
    ans[make_pair(0, 0)] = sum;
    return ans;
  }
};
MaxFlow<2 * N, 10 * N, LL> flow[2];

int main() {
  ios :: sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  cin >> n >> m >> r >> b;
  if (r > b) {
    swap(r, b), swap(colors[0], colors[1]);
  }
  vector<int> X, Y;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
    X.push_back(x), Y.push_back(y);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());
  Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
  K = X.size() + Y.size();
  for (int i = 0; i < n; i++) {
    int x, y;
    tie(x, y) = p[i];
    x = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
    y = lower_bound(Y.begin(), Y.end(), y) - Y.begin() + 1;
    cntX[x]++, cntY[y]++;
    p[i] = {x, y};
    mp[make_pair(x, y)].push_back(i);
  }
  for (int i = 1; i <= int(X.size()); i++) upX[i] = cntX[i];
  for (int i = 1; i <= int(Y.size()); i++) upY[i] = cntY[i];
  for (int i = 0; i < m; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      int pos = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
      if (pos > X.size() || X[pos - 1] != x) continue;
      x = pos;
      upX[x] = min(upX[x], y);
    }
    else {
      int pos = lower_bound(Y.begin(), Y.end(), x) - Y.begin() + 1;
      if (pos > Y.size() || Y[pos - 1] != x) continue;
      x = pos;
      upY[x] = min(upY[x], y);
    }
  }
  int S = 0, T = X.size() + Y.size() + 1;
  int A = T + 1, B = T + 2;
  LL sum = 0;
  bool bad = 0;
  flow[0].Init(S, T), flow[1].Init(S, T);
  flow[0].Add(B, A, flow[0].INF);
  for (int i = 1; i <= int(X.size()); i++) {
    int L = (cntX[i] - upX[i] + 1) / 2;
    int R = (cntX[i] + upX[i]) / 2;
    cout << L << ' ' << R << endl;
    if (L > R) {
      bad = 1;
      break;
    }
    flow[0].Add(A, i, L);
    flow[0].Add(S, B, L);
    flow[0].Add(S, i, R - L);
    flow[1].Add(S, i, R - L);
    sum += L;
  }
  for (int i = 1; i <= int(Y.size()); i++) {
    int L = (cntY[i] - upY[i] + 1) / 2;
    int R = (cntY[i] + upY[i]) / 2;
    cout << L << ' ' << R << endl;
    if (L > R) {
      bad = 1;
      break;
    }
    flow[0].Add(A, T, L);
    flow[0].Add(i + X.size(), B, L);
    flow[0].Add(i + X.size(), T, R - L);
    flow[1].Add(i + X.size(), T, R - L);
    sum += L;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    tie(x, y) = p[i];
    flow[0].Add(x, y + X.size(), 1);
    flow[1].Add(x, y + X.size(), 1);
  }
  if (bad || sum != flow[0].Dinic()) {
    cout << "-1" << endl;
    return 0;
  }
  LL ans = flow[1].Dinic();
  map<pair<int, int>, int> edges[2];
  for (int i = 0; i < 2; i++) edges[i] = flow[i].GetCutEdges();
  for (int i = 1; i <= 3; i++) {
    for (int go = flow[0].first[i]; go; go = flow[0].next[go]) {
      if (flow[0].to[go] <= K && flow[0].to[go] >= 1) {
        cout << "Edge: " << i  << ' ' << flow[0].to[go] << ' ' << flow[0].cap[go] << endl;
      }
    }
  }
  A = edges[0][make_pair(0, 0)], B = edges[1][make_pair(0, 0)];
  cout << "A: " << A << endl;
  cout << "B: " << B << endl;
  assert(ans == B);
  string res(n, colors[1]);
  for (int i = 0; i < 2; i++) {
    for (auto &p: edges[i]) {
      pair<int, int> point;
      int cnt;
      tie(point, cnt) = p;
      if (point.first == 0) continue;
      if (point.first > X.size()) point.first -= X.size();
      if (point.second > X.size()) point.second -= X.size();
      assert(mp[point].size() >= cnt);
      //cout << point.first << ' ' << point.second << ' '  << cnt << endl;
      //continue;
      for (int j = 0; j < cnt; j++) {
        res[mp[point].back()] = colors[0];
        mp[point].pop_back();
      }
    }
  }
  cout << 1LL * r * (A + B) + 1LL * (n - A - B) * b << endl;
  cerr << res << endl;
  return 0;
}
