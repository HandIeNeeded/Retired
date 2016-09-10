/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 01:52:30 PM CST
*************************************************************************/
#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

std::vector<int> edges[N];
int L[N], R[N], now = 0;

void Dfs(int x, int p) {
  L[x] = ++now;
  for (auto &y: edges[x]) {
    if (y != p) {
      Dfs(y, x);
    }
  }
  R[x] = now;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    edges[x].emplace_back(i);
    edges[i].emplace_back(x);
  }
  for (auto &x: edges[0]) {
    Dfs(x, 0);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int n;
    std::cin >> n;
    std::set<int> s;
    std::vector<int> idx;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      s.insert(x);
      idx.emplace_back(x);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (i != j) {
        int a = idx[i], b = idx[j];
        if (L[a] <= L[b] && R[a] >= R[b]) {
          s.erase(b);
        }
      }
    }
    int ans = 0;
    for (auto &idx: s) {
      ans += R[idx] - L[idx] + 1;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
