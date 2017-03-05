/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Mar  5 22:04:33 2017
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

const int N = 2e5 +5;
std::vector<int> edges[N];
int color[N];

void build(int x, int p, int c, int t) {
  color[x] = c;
  int now = 1;
  for (auto &y: edges[x]) if (y != p) {
    while (now == c || now == t) ++now;
    build(y, x, now, color[x]);
    ++now;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n - 1; ++i){
    int x, y;
    std::cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (edges[i].size() > ans) ans = edges[i].size();
  build(1, 0, 1, 0);
  std::cout << ++ans << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout << color[i + 1] << std::endl;
  }

  return 0;
}

