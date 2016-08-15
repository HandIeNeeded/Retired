/*************************************************************************
  >         File: 1009.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 01:39:01 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
vector<int> edges[N];
int a[N];
int visited[N], p[N], tot;

void Prime() {
  for (int i = 2; i < N; i++) {
    if (!visited[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      visited[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}

int top[N], pos[N], l[N], r[N], pre[N], son[N], size[N], inv[N], dep[N], now;

void dfs(int x, int p) {
  pre[x] = p, size[x] = 1, son[x] = 0;
  dep[x] = dep[p] + 1;
  for (auto &y: edges[x]) {
    if (y != p) {
      dfs(y, x);
      size[x] += size[y];
      if (size[y] > size[son[x]]) {
        son[x] = y;
      }
    }
  }
}

void divide(int x, int tp) {
  top[x] = tp, pos[x] = l[x] = now, inv[now++] = x;
  if (son[x]) divide(son[x], tp);
  for (auto &y: edges[x]) {
    if (y != pre[x] && y != son[x]) {
      divide(y, y);
    }
  }
  r[x] = now - 1;
}

int query(int a, int b) {
  int ans = -INT_MAX;
  while (top[a] - top[b]) {
    if (dep[top[a]] > dep[top[b]]) {
      swap(a, b);
    }
    ql = pos[top[b]], qr = pos[b];
    ans = max(ans, query(1, 1, n));
    b = pre[top[b]];
  }
  //if (a == b) return ans; edge
  if (dep[a] > dep[b]) swap(a, b);
  //ql = pos[son[a]], qr = pos[b]; edge
  ql = pos[a], qr = pos[b];
  ans = max(ans, query(1, 1, n));
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  int t, ca = 1;
  Prime();
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    dfs(1, 0);
    build(1, 1, n);
    printf("Case #%d:\n", ca++);
    while (m--) {
      int u, v, k;
      scanf("%d%d%d", &u, &v, &k);
      printf("%d\n", query(u, v, k));
    }
  }


  return 0;
}
