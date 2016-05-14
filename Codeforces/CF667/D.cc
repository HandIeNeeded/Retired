/*************************************************************************
  > File Name: D.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 30 Apr 2016 01:24:55 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define rank hehe
using namespace std;

const int N = 3005;
vector<int> edge[N];
int dis[N][N], vis[N];
vector<pair<int, int>> top[N], rank[N];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int x, y;
    cin >> x >> y;
    if (x != y) {
      edge[x].push_back(y);
    }
  }
  REPP(i, 1, n) REPP(j, 1, n) dis[i][j] = -1;
  REPP(i, 1, n) {
    REPP(j, 1, n) vis[j] = 0;
    queue<int> q;
    q.push(i),  dis[i][i] = 0, vis[i] = 1;
    while(q.size()) {
      int x = q.front(); q.pop();
      for (auto &y: edge[x]) {
        if (!vis[y]) {
          vis[y] = 1;
          dis[i][y] = dis[i][x] + 1;
          q.push(y);
        }
      }
    }
  }
  REPP(i, 1, n) {
    REPP(j, 1, n) if (dis[i][j] > 0) {
      top[i].push_back({dis[i][j], j});
      rank[j].push_back({dis[i][j], i});
    }
  }
  REPP(i, 1, n) {
    sort(top[i].begin(), top[i].end());
    reverse(top[i].begin(), top[i].end());
    top[i].resize(min(3, int(top[i].size())));
    sort(rank[i].begin(), rank[i].end());
    reverse(rank[i].begin(), rank[i].end());
    rank[i].resize(min(3, int(rank[i].size())));
  }
  int ans = 0;
  vector<int> result;
  REPP(i, 1, n) {
    REPP(j, 1, n) if (i != j && dis[i][j] > 0) {
      for (int a = 0; a < int(rank[i].size()); a++) if (rank[i][a].second != j) {
        for (int b = 0; b < int(top[j].size()); b++) if (top[j][b].second != i && top[j][b].second != rank[i][a].second) {
          int length = rank[i][a].first + dis[i][j] + top[j][b].first;
          if (length > ans) {
            ans = length;
            vector<int> idx;
            idx.push_back(rank[i][a].second), idx.push_back(i), idx.push_back(j), idx.push_back(top[j][b].second);
            result = idx;
          }
        }
      }
    }
  }
  for (auto &x: result) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
