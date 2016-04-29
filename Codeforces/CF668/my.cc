/*************************************************************************
  > File Name: D.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Mon 25 Apr 2016 01:14:06 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e6 + 5;
int a[N], b[N], c[N];
vector<int> numbers;

struct Node{
  int value, size;
  Node *l, *r;

  Node* update() {
    size = l->size + 1 + r->size;
    return this;
  }
}bar[N * 12], *foo, *rt[N << 1], *null;

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

#define LB(x) ((x) & (-(x)))

void add(Node *&a, int d) {
  Node* node = New(d);
  insert(node, a);
}

void Add(int x, int d) {
  while (x < N * 2) {
    add(rt[x], d);
    x += LB(x);
  }
}

void Erase(int x, int d) {
  while (x < N * 2) {
    erase(rt[x], d);
    x += LB(x);
  }
}

int query(Node *u, int x) {
  return find(u, x) - find(u, x - 1);
}

int Query(int x, int d) {
  int answer = 0;
  while (x) {
    answer += query(rt[x], d);
    x -= LB(x);
  }
  return answer;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  REPP(i, 1, n) {
    scanf("%d%d%d", a + i, b + i, c + i);
    numbers.push_back(b[i]), numbers.push_back(c[i]);
  }
  sort(numbers.begin(), numbers.end());
  numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());
  int tot = numbers.size();
  cerr << tot << endl;
  REPP(i, 1, n) {
    b[i] = lower_bound(numbers.begin(), numbers.end(), b[i]) - numbers.begin() + 1;
    c[i] = lower_bound(numbers.begin(), numbers.end(), c[i]) - numbers.begin() + 1;
  }
  init();
  REP(i, N * 2) rt[i] = null;
  REPP(i, 1, n) {
    if (a[i] == 1) {
      Add(b[i], c[i]);
      //show(rt[b[i]]);
    }
    else if (a[i] == 2) {
      Erase(b[i], c[i]);
    }
    else {
      printf("%d\n", Query(b[i], c[i]));
    }
  }
  return 0;
}

