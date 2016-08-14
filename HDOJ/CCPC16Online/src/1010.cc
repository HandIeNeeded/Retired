/*************************************************************************
  >         File: 1010.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 03:52:42 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
const int K = 20;
const int L = 16;

int tr[N * K][2], node;
int rt[N], idx[N], res[N], ans[N];
vector<int> numbers[N], edges[N];

int Node() {
  tr[node][0] = tr[node][1] = 0;
  return node++;
}

void Init(int n) {
  node = 0;
  Node();
  for (int i = 1; i <= n; i++) rt[i] = Node();
}

void Insert(int a, int x) {
  int now = rt[a];
  numbers[a].push_back(x);
  for (int i = L; i >= 0; i--) {
    int idx = (x & (1 << i)) > 0;
    if (tr[now][idx] == 0) tr[now][idx] = Node();
    now = tr[now][idx];
  }
}

int Query(int a, int x) {
  int now = rt[a];
  int number = 0;
  for (int i = L; i >= 0; i--) {
    int idx = (x & (1 << i)) > 0;
    if (tr[now][idx] == 0) idx ^= 1;
    number |= idx << i;
    now = tr[now][idx];
  }
  return x ^ number;
}

int Merge(int a, int b) {
  a = idx[a], b = idx[b];
  if (numbers[a].size() < numbers[b].size()) swap(a, b);
  int ans = max(res[a], res[b]);
  for (auto &y: numbers[b]) {
    ans = max(ans, Query(a, y));
    Insert(a, y);
  }
  res[a] = ans;
  return a;
}

void dfs(int x, int p) {
  for (auto &y: edges[x]) if (y != p) {
    dfs(y, x);
    idx[x] = Merge(x, y);
  }
  ans[x] = numbers[idx[x]].size() > 1 ? res[idx[x]] : -1;
}

int main() {
  int t, ca = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    Init(n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      idx[i] = i;
      res[i] = 0;
      edges[i].clear();
      numbers[i].clear();
      Insert(idx[i], x);
    }
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    dfs(1, 0);
    int q;
    scanf("%d", &q);
    printf("Case #%d:\n", ca++);
    while (q--) {
      int x;
      scanf("%d", &x);
      printf("%d\n", ans[x]);
    }
  }
  return 0;
}
