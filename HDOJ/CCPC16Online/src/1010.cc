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

int tr[N * K * K][2], node;
int rt[N], idx[N], res[N], ans[N];
vector<int> numbers[N];

int first[N], to[N << 1], nex[N << 1], edge;

void Add(int x, int y) {
  nex[++edge] = first[x];
  first[x] = edge;
  to[edge] = y;
}

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
  for (int go = first[x]; go; go = nex[go]) {
    int y = to[go];
    if (y == p) continue;
    dfs(y, x);
    idx[x] = Merge(x, y);
  }
  ans[x] = numbers[idx[x]].size() > 1 ? res[idx[x]] : -1;
}

int in() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
  bool flag = (c == '-');
  if (flag) c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return flag ? -x : x;
}

void out(int x) { //int
  if (x < 0) putchar('-'), x = -x;
  int len = 0, bit[10]; // LL  -> bit[20]
  while (x) {
    bit[len++] = x % 10;
    x /= 10;
  }
  if (!len) bit[len++] = 0;
  while (len--) putchar(bit[len] + 48);
  putchar('\n');
}

int main() {
  int t, ca = 1;
  t = in();
  //scanf("%d", &t);
  while (t--) {
    int n;
    n = in();
    //scanf("%d", &n);
    Init(n);
    edge = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      x = in();
      //scanf("%d", &x);
      idx[i] = i;
      res[i] = 0;
      first[i] = 0;
      numbers[i].clear();
      Insert(idx[i], x);
    }
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      x = in(), y = in();
      //scanf("%d%d", &x, &y);
      Add(x, y);
      Add(y, x);
    }
    dfs(1, 0);
    int q;
    q = in();
    //scanf("%d", &q);
    printf("Case #%d:\n", ca++);
    while (q--) {
      int x;
      x = in();
      //scanf("%d", &x);
      out(ans[x]);
      //printf("%d\n", ans[x]);
    }
  }
  return 0;
}
