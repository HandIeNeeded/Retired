/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Feb 24 01:27:24 2017
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

const int N = 1e5 + 5;
int good[N];
std::vector<int> control[N];
std::vector<int> edges[N];

bool use[2][N];

void dfs(int x) {
  use[0][x] = 1;
  int y = edges[x][0];
  if (use[1][y]) y = edges[x][1];
  if (use[1][y]) {
    std::cout << "NO" << std::endl;
    exit(0);
  }
  use[1][y] = 1;
  for (auto &z: control[y]) {
    good[z] ^= 1;
  }
  for (auto &z: control[y]) {
    if (!use[0][z] && !good[z]) {
      dfs(z);
    }
    if (!good[z]) {
      std::cout << "NO" << std::endl;
      exit(0);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> good[i + 1];
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    for (int j = 0; j < x; ++j) {
      int y;
      std::cin >> y;
      control[i + 1].emplace_back(y);
      edges[y].push_back(i + 1);
    }
  }
  for (int i = 1; i <= n; ++i) if (!good[i]) {
    dfs(i);
  }
  std::cout << "YES" << std::endl;

  return 0;
}
