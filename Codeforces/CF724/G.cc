/*************************************************************************
  >         File: G.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 08 Oct 2016 10:38:32 PM CST
*************************************************************************/
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 2e5 + 5;
const int MO = 1e9 + 7;

std::vector<std::pair<int, LL>> te[N];
int f[N];
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
int color[N], A[N], B[N], C[N], n, m;
int mark[N], node[N], cnt[N][2];

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int Bfs(LL bit, int start, int id) {
  queue<int> q;
  q.push(start), mark[start] = id, color[start] = 0;
  cnt[start][0] = cnt[start][1] = 0;
  int tot = 1;
  while (q.size()) {
    int x = q.front(); q.pop();
    for (auto &p: te[x]) {
      int y;
      LL z;
      tie(y, z) = p;
      if (color[y] >= 0) continue;
      if (z & bit) {
        color[y] = color[x] ^ 1;
      }
      else color[y] = color[x];
      q.push(y);
      cnt[y][0] = cnt[y][1] = 0;
      mark[y] = id;
      tot++;
    }
  }
  return tot;
}

int Get(int x) {
  return 1LL * x * (x - 1) % MO;
}

void Dfs(LL bit, int x, int f) {
  //std::cerr << "# x # is " << x << std::endl;
  for (auto &p: te[x]) {
    int y;
    LL z;
    tie(y, z) = p;
    if (y == f) continue;
    Dfs(bit, y, x);
    if (z & bit) {
      cnt[x][0] += cnt[y][1];
      cnt[x][1] += cnt[y][0];
    }
    else {
      cnt[x][0] += cnt[y][0];
      cnt[x][1] += cnt[y][1];
    }
  }
  cnt[x][0]++;
}

void Dfs2(LL bit, int x, int f, int& ans) {
  Add(ans, cnt[x][1]);
  for (auto &p: te[x]) {
    int y;
    LL z;
    tie(y, z) = p;
    int tmp[2];
    std::copy(cnt[x], cnt[x] + 2, tmp);
    if (z & bit) {
      tmp[0] -= cnt[y][1];
      tmp[1] -= cnt[y][0];
    }
    else {
      tmp[0] -= cnt[y][0];
      tmp[1] -= cnt[y][1];
    }
    if (z & bit) {
      cnt[y][0] += tmp[1];
      cnt[y][1] += tmp[0];
    }
    else {
      cnt[y][0] += tmp[0];
      cnt[y][1] += tmp[1];
    }
    if (y != f) Dfs2(bit, y, x, ans);
  }
}

int build(LL bit) {
  std::fill(color + 1, color + n + 1, -1);
  int now = 0;
  map<int, int> good;
  for (int i = 1; i <= n; ++i) {
    if (color[i] == -1) {
      int cnt = Bfs(bit, i, ++now);
      node[now] = cnt;
      Dfs(bit, i, 0);
      int ans = 0;
      Dfs2(bit, i, 0, ans);
      good[now] = ans;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x = A[i], y = B[i];
    LL z = C[i];
    assert(mark[x] == mark[y]);
    int has = (z & bit) > 0;
    if (has ^ color[x] ^ color[y]) {
      good[now] = Get(node[mark[x]]);
    }
  }
  int ans = 0;
  for (auto &p: good) {
    Add(ans, p.second);
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 0; i < m; ++i) {
    int x, y;
    LL z;
    cin >> x >> y >> z;
    A[i] = x, B[i] = y, C[i] = z;
    int tx = find(x), ty = find(y);
    if (tx != ty) {
      f[tx] = ty;
      te[x].emplace_back(y, z);
      te[y].emplace_back(x, z);
    }
  }
  int ans = 0;
  for (int i = 0; i < 63; ++i) {
    Add(ans, (1LL << i) * build(1LL << i) % MO);
  }
  std::cout << 1LL * ans * ((MO + 1) / 2) % MO << std::endl;
  return 0;
}
