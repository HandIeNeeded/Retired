/*************************************************************************
	> File Name: F.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 03 Jul 2016 02:19:47 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
using namespace std;

template<int N, int M, typename Type>
struct MaxFlow{
  int edge, source, sink;
  int lvl[N], cur[N];
  int fi[N], ne[M << 1], en[M << 1], vis[M << 1];
  Type cap[M << 1];
  const Type INF = 0x3f3f3f3f;

  void init(int S, int T) {
    source = S, sink = T;
    edge = 1, MST(fi, 0), MST(vis, 0);
  }

  void _add(int x, int y, Type z) {
    ne[++edge] = fi[x]; fi[x] = edge; en[edge] = y; cap[edge] = z;
  }

  void add(int x, int y, Type z) {
    _add(x, y, z);
    _add(y, x, 0);
  }

  bool bfs() {
    queue<int> q;
    MST(lvl, 0);
    q.push(source), lvl[source] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !lvl[en[go]]) {
        int y = en[go];
        lvl[y] = lvl[x] + 1;
        q.push(y);
      }
    }
    return lvl[sink];
  }

  Type dfs(Type x, Type flow) {
    if (x == sink || flow == 0) {
      return flow;
    }
    Type ans = 0, tmp = 0;
    for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
      int y = en[go];
      if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, (Type) cap[go]))) > 0) {
        ans += tmp, flow -= tmp;
        cap[go] -= tmp, cap[go ^ 1] += tmp;
        if (flow == 0) {
          return ans;
        }
      }
    }
    return ans;
  }

  Type dinic() {
    Type ans = 0;
    while (bfs()) {
      memcpy(cur, fi, sizeof(fi));
      ans += dfs(source, INF);
    }	
    return ans;
  }

  bool GetPath(int x, int target, int n, vector<int>& ans) {
    ans.push_back(x);
    if (x == source) return false;
    if (x == target) return true;
    for (int go = fi[x]; go; go = ne[go]) {
      if (!vis[go] && go % 2 == 1 && cap[go] == 1) {
        vis[go] = 1;
        if (en[go] <= n) continue;
        bool can = GetPath(en[go] - n, target, n, ans);
        if (can) return true;
        else vis[go] = 0;
      }
    }
    ans.pop_back();
    return false;
  }
};
MaxFlow<400, 100000, int> flow;

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    flow.init(0, c);
    flow.add(0, a, 1), flow.add(0, b, 1);
    REPP(i, 1, n) if (i != c) flow.add(i, i + n, 1);
    REP(i, m) {
      int x, y;
      cin >> x >> y;
      if (x == y) continue;
      if (x == c || y == c) {
        if (x == c) swap(x, y);
        flow.add(x + n, c, 1);
      }
      else {
        flow.add(y + n, x, 1);
        flow.add(x + n, y, 1);
      }
    }
    //cout << flow.dinic() << endl;
    assert(flow.dinic() == 2);
    //REPP(i, 0, flow.edge) {
    //  cout << "Edge: " << i << ' ' << flow.cap[i] << endl;
    //}
    //cerr << "hehe" << endl;
    vector<int> left, right;
    //cout << c << ' ' << a << endl;
    flow.GetPath(c, a, n, left);
    //cout << "hehe" << endl;
    //cout << c << ' ' << b << endl;
    flow.GetPath(c, b, n, right);
    //assert(flow.GetPath(a, n, left) && flow.GetPath(b, n, right));
    reverse(left.begin(), left.end());
    left.pop_back();
    //cout << "left: " << endl;
    //for (auto &x: left) {
    //  cout << x << ' ';
    //}
    //cout << endl;
    //cout << "right: " << endl;
    //for (auto &x: right) {
    //  cout << x << ' ';
    //}
    //cout << endl;
    left.insert(left.end(), right.begin(), right.end());
    REP(i, left.size()) {
      cout << left[i] << " \n"[i == int(left.size() - 1)];
    }
  }
  return 0;
}


