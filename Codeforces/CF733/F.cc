/*************************************************************************
  >         File: F.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 31 Oct 2016 11:51:07 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
constexpr int N = 2e5 + 5;
int A[N], B[N], value[N], cost[N];
bool mark[N];
std::vector<std::pair<int, int>> edges[N];
LL best, answer;

namespace DSU {
  int parent[N];
  void Init(int n) { for (int i = 1; i <= n; ++i) parent[i] = i;}
  int Get(int x) { return parent[x] == x ? x : parent[x] = Get(parent[x]); }
  void Merge(int a, int b, int id) {
    int ta = Get(a), tb = Get(b);
    if (ta != tb) {
      parent[ta] = tb;
      mark[id] = true;
      edges[a].emplace_back(b, value[id]);
      edges[b].emplace_back(a, value[id]);
      answer += value[id];
    }
  }
}

namespace SGT {
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

  int value[N], id[N];
  std::pair<int, int> tree[N << 2];

  void Build(int x, int l, int r) {
    if (l == r) tree[x] = {value[l], id[l]};
    else {
      Build(LC), Build(RC);
      tree[x] = std::max(tree[L], tree[R]);
    }
  }

  std::pair<int, int> Ask(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return tree[x];
    else {
      if (ql > MID) return Ask(RC, ql, qr);
      if (qr <= MID) return Ask(LC, ql, qr);
      return std::max(Ask(LC, ql, qr), Ask(RC, ql, qr));
    }
  }
}

namespace HLD {
  constexpr int K = 20;
  int parent[N][K], depth[N], position[N], son[N], heavy[N];
  int index;

  void Dfs(int x, int p) {
    parent[x][0] = p;
    for (int i = 1; i < K; ++i) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    for (auto &q: edges[x]) {
      int y, v;
      std::tie(y, v) = q;
      if (y == p) continue;
      Dfs(y, x);
      son[x] += son[y];
      if (son[y] > son[heavy[x]]) heavy[x] = y;
    }
    son[x]++;
  }

  void Build(int x, int p, int value = 0) {
    position[x] = ++index;
    SGT::value[index] = value;
    for (auto &q: edges[x]) {
      int y, v;
      std::tie(y, v) = q;
      if (y == heavy[x]) {
        Build(y, x, v);
      }
    }
    for (auto &q: edges[x]) {
      int y, v;
      std::tie(y, v) = q;
      if (y == heavy[x]) continue;
      Build(y, x, v);
    }
  }

  void Init(int n) {
    index = 0;
    Dfs(1, 0);
    Build(1, 0);
  }

  int GoUp(int x, int step) {
    for (int i = 0; i < 20; ++i) {
      if (step & (1 << i)) x = parent[x][i];
    }
    return x;
  }

  std::pair<int, int> Ask(int a, int b) {

  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, S;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> value[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> cost[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> A[i] >> B[i];
  }
  std::cin >> S;
  std::vector<int> indexs(m);
  std::iota(indexs.begin(), indexs.end(), 0);
  std::sort(indexs.begin(), indexs.end(), [] (int a, int b) {
      return value[a] < value[b];
    });
  DSU::Init(n);
  for (int i = 0; i < m; ++i) {
    int id = indexs[i];
    DSU::Merge(A[id], B[id], id);
  }
  HLD::Init(n);
  best = answer;
  int bridge = -1;
  int remove = -1;
  for (int i = 0; i < m; ++i) {
    int val = value[i] - S / cost[i];
    if (mark[i]) {
      if (answer - value[i] + val < best) {
        best = answer - value[i] + val;
        bridge = i;
      }
    } else {
      int newBridge = val;
      std::pair<int, int> replacement = HLD::Ask(A[i], B[i]);
      if (answer + newBridge - replacement < best) {
        best = answer + newBridge - replacement;
        bridge = i;
        remove = replacement.second;
      }
    }
  }
  std::cout << best << std::endl;
  for (int i = 0; i < m; ++i) if (mark[i]) {
    if (i == remove) continue;
    if (i == bridge) {
      std::cout << i << ' ' << value[i] - S / cost[i] << std::endl;
    } else {
      std::cout << i << ' ' << value[i] << std::endl;
    }
  }
  if (!mark[bridge]) {
    std::cout << bridge << ' ' << value[bridge] - S / cost[bridge] << std::endl;
  }
  return 0;
}
