/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Mar  5 22:27:27 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

const int N = 2e5 + 5;
int f[N];
std::vector<int> edges[N];
std::vector<int> paths[N];

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

int now = 0, cnt;

void dfs(int x, int p) {
  paths[now].push_back(x);
  if (paths[now].size() == cnt) ++now;
  for (auto &y: edges[x]) if (y != p) {
    dfs(y, x);
    paths[now].push_back(x);
    if (paths[now].size() == cnt) ++now;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    if (find(x) != find(y)) {
      f[find(x)] = find(y);
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
  }
  cnt = (2 * n + k - 1) / k;
  dfs(1, 0);
  for (int i = 0; i < k; ++i) {
    if (paths[i].size() == 0) {
      paths[i].push_back(1);
    }
    std::cout << paths[i].size();
    for (auto &y: paths[i]) {
      std::cout << " " << y;
    }
    std::cout << "" << std::endl;
  }



  return 0;
}
