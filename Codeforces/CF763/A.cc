/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu 02 Feb 2017 10:47:02 PM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;

int f[N], color[N], cnt[N];
std::vector<int> edges[N];

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}

bool dfs(int x, int p) {
  for (auto &y: edges[x]) {
    if (y != p) {
      if (color[x] != color[y] || !dfs(y, x)) return 0;
    }
  }
  return 1;
}

void check(int x) {
  for (auto &y: edges[x]) {
    if (!dfs(y, x)) return;
  }
  std::cout << "YES" << std::endl;
  std::cout << x << std::endl;
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) f[i + 1] = i + 1;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    std::cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> color[i + 1];
  }

  for (int i = 0; i < n; ++i) {
    int x = i + 1;
    for (auto &y: edges[x]) {
      if (color[x] != color[y]) {
        check(x);
        check(y);
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "YES" << std::endl;
  std::cout << 1 << std::endl;

  return 0;
}
