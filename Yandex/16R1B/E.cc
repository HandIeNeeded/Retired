/*************************************************************************
	> File Name: E.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 03:09:06 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2e5 + 5;
vector<int> edge[N];

struct Node{
  int value, size;
  Node *l, *r;

  Node* update() {
    size = l->size + 1 + r->size;
    return this;
  }
}bar[N * 15], *foo, *s[N], *null;

void init() {
  foo = null = bar;
  null->l = null->r = null;
  foo++;
}

Node* New(int x) {
  return new(foo++) (Node) {x, 1, null, null};
}

bool gen(int a, int b) {
  return rand() % (a + b) < a;
}

Node* merge(Node *a, Node *b) {
  if (a == null) return b;
  if (b == null) return a;
  if (gen(a->size, b->size)) {
    a->r = merge(a->r, b);
    return a->update();
  }
  else {
    b->l = merge(a, b->l);
    return b->update();
  }
}	

#define PNN pair<Node*, Node*>

PNN split(Node *u, int s) {
  if (u == null) return {null, null};
  Node *l = u->l, *r = u->r;
  if (l->size >= s) {
    PNN res = split(l, s);
    u->l = res.second;
    return {res.first, u->update()};
  }
  else {
    PNN res = split(r, s - (l->size + 1));
    u->r = res.first;
    return {u->update(), res.second};
  }
}

void show(Node *u) {
  if (u == null) return ;
  else {
    show(u->l);
    printf("value: %d\n", u->value);
    show(u->r);
  }
}

int find(Node *u, int x) {
  if (u == null) return 0;
  if (u->value <= x) {
    return u->l->size + 1 + find(u->r, x);
  }
  else return find(u->l, x);
}

Node* erase(Node *&u, int s) {
  int tmp = find(u, s);
  PNN res = split(u, tmp - 1);
  PNN ans = split(res.second, 1);
  u = merge(res.first, ans.second);
  return ans.first;
}

void insert(Node *a, Node *&u) {
  int ans = find(u, a->value);
  PNN res = split(u, ans);
  u = a;
  u = merge(res.first, u);
  u = merge(u, res.second);
}

void dfs(Node *a, Node *&b) {
  if (a == null) return ;
  else {
    dfs(a->l, b);
    dfs(a->r, b);
    a->l = a->r = null;
    insert(a->update(), b);
  }
}

Node* combine(Node *a, Node *b) {
  if (a->size > b->size) {
    swap(a, b);
  }
  dfs(a, b);
  return b;
}

int a[N], l[N], r[N], num[N], now, n;
LL dp[N];

void dfs(int x, int p = 0) {
  l[x] = now++;
  num[now] = a[x];
  insert(New(a[x]), s[x]);
  for (auto &y: edge[x]) if (y != p) {
    dfs(y, x);
    s[x] = combine(s[x], s[y]);
  }
  r[x] = now;
  dp[x] = find(s[x], a[x] - 1);
}

void dfs1(int x, int p) {
  for (auto &y: edge[x]) if (y != p) {
    dfs1(y, x);
    dp[x] += dp[y];
  }
}

int cnt[N];
LL result[N];

int LB(int x) {
  return x & -x;
}

void add(int x, int d) {
  while (x < N) {
    cnt[x] += d;
    x += LB(x);
  }
}

int query(int x) {
  int ans = 0;
  while (x) {
    ans += cnt[x];
    x -= LB(x);
  }
  return ans;
}

void dfs2(int x, int p) {
  add(a[x], 1);
  for (auto &y: edge[x]) if (y != p) {
    int num = query(N - 1);
    LL tot = 1LL * (num - 1) * num / 2;
    LL rev = query(a[x] - 1);
    LL change = tot - rev;
    LL dpy = dp[y];
    dp[y] = dp[x] - 

  }

}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  dfs(1);
  REP(i, n - 1) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  int idx = -1;
  LL ans = LLONG_MAX;
  REPP(i, 1, n) if (ans > result[i]) {
    ans = result[i];
    idx = i;
  }
  cout << idx << ' ' << ans << endl;

  return 0;
}


