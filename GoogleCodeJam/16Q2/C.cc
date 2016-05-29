/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 12:02:44 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 100;
vector<int> edge[N];
int r, c, tot;
pair<int, int> p[N];
char mp[N][N];
int nodes[N][N][4];
int a[N], b[N], cc[N], d[N], now;

void construct(int x) {
  REP(i, now) edge[i].clear();
  REP(i, c) {
    edge[nodes[0][i][0]].push_back(a[i]);
    edge[a[i]].push_back(nodes[0][i][0]);
    edge[nodes[r - 1][i][2]].push_back(cc[i]);
    edge[cc[i]].push_back(nodes[r - 1][i][2]);
  }
  REP(i, r) {
    edge[nodes[i][c - 1][1]].push_back(b[i]);
    edge[b[i]].push_back(nodes[i][c - 1][1]);
    edge[nodes[i][0][3]].push_back(d[i]);
    edge[d[i]].push_back(nodes[i][0][3]);
  }
  REP(i, r) {
    REP(j, c) {
      if (i + 1 < r) {
        edge[nodes[i][j][2]].push_back(nodes[i + 1][j][0]);
        edge[nodes[i + 1][j][0]].push_back(nodes[i][j][2]);
      }
      if (j + 1 < c) {
        edge[nodes[i][j][1]].push_back(nodes[i][j + 1][3]);
        edge[nodes[i][j + 1][3]].push_back(nodes[i][j][1]);
      }
    }
  }
  REP(i, r) {
    REP(j, c) {
      int n = i * c + j;
      if (x & (1 << n)) {
        edge[nodes[i][j][0]].push_back(nodes[i][j][3]);
        edge[nodes[i][j][3]].push_back(nodes[i][j][0]);
        edge[nodes[i][j][1]].push_back(nodes[i][j][2]);
        edge[nodes[i][j][2]].push_back(nodes[i][j][1]);
      }
      else {
        edge[nodes[i][j][0]].push_back(nodes[i][j][1]);
        edge[nodes[i][j][1]].push_back(nodes[i][j][0]);
        edge[nodes[i][j][3]].push_back(nodes[i][j][2]);
        edge[nodes[i][j][2]].push_back(nodes[i][j][3]);
      }
    }
  }
}

int get(int x) {
  //cout << "get: " << x << endl;
  x--;
  if (x < c) return a[x];
  else if (x < r + c) return b[x - c];
  else if (x < 2 * c + r) return cc[2 * c + r - 1 - x];
  else return d[2 * r + 2 * c - 1 - x];
}

bool vis[N];

int bfs(int a, int b) {
  queue<int> q;
  q.push(a);
  memset(vis, 0, sizeof(vis));
  vis[a] = 1;
  while (q.size()) {
    int x = q.front(); q.pop();
    //cout << x << endl;
    for (auto &y: edge[x]) {
      //cout << "x: " << x << ", y: " << y << endl;
      if (y == b) return 1;
      if (!vis[y]) {
        vis[y] = 1;
        q.push(y);
      }
    }
  }
  return 0;
}

bool check() {
  for (int i = 0; i < r + c; i++) {
    int start = get(p[i].first);
    int end = get(p[i].second);
    //cout << "start: " << start << ' ' << end << endl;
    if (!bfs(start, end)) return 0;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> r >> c;
    for (int i = 0; i < r + c; i++) {
      int x, y;
      cin >> x >> y;
      p[i] = make_pair(x, y);
    }
    now = 0;
    for (int i = 0; i < r; i ++) {
      for (int j = 0; j < c; j ++) {
        REP(k, 4) nodes[i][j][k] = now++;
      }
    }
    REP(i, c) a[i] = now++;
    REP(i, r) b[i] = now++;
    REP(i, c) cc[c - 1 - i] = now++;
    REP(i, r) d[r - 1 - i] = now++;
    tot = r * c;
    bool find = 0;
    cout << "Case #" << ca++ << ":\n";
    REP(i, 1 << tot) {
      construct(i);
      if (check()) {
        find = 1;
        REP(j, tot) {
          if (i & (1 << j)) {
            mp[j / c][j % c] = '/';
          }
          else {
            mp[j / c][j % c] = '\\';
          }
        }
        REP(i, r) mp[i][c] = 0;
        REP(i, r) {
          cout << mp[i] << endl;
        }
        break;
      }
    }
    if (!find) {
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}

