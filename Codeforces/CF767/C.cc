/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Feb 18 18:25:59 2017
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

const int N = 1e6 + 1;
std::vector<int> edges[N];
int val[N], dp[N], good[N], match[N];
int V;

void dfs(int x, int p) {
  for (auto &y: edges[x]) if (y != p) {
    dfs(y, x);
    dp[x] += dp[y];
    good[x] |= good[y];
    if (good[y]) match[x] = match[y];
  }
  dp[x] += val[x];
  if (dp[x] == V) good[x] = 1, match[x] = x;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int sum = 0;
  int start = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    val[i + 1] = y;
    edges[x].push_back(i + 1);
    edges[i + 1].push_back(x);
    sum += val[i + 1];
    if (x == 0) start = i + 1;
  }
  if (sum % 3 != 0) {
    std::cout << -1 << std::endl;
    return 0;
  }
  V = sum / 3;
  dfs(start, 0);
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (dp[i + 1] == V && i + 1 != start) {
      ans.push_back(i + 1);
    }
  }
  if (ans.size() >= 2) {
    std::cout << ans[0] << ' ' << ans[1] << std::endl;
    return 0;
  } else if (sum != 0) {
    for (int i = 0; i < n; ++i) {
      if (dp[i + 1] == 2 * V && i + 1 != start && good[i + 1]) {
        std::cout << i + 1 << ' ' << match[i + 1] << std::endl;
        return 0;
      }
    }
  }
  std::cout << -1 << std::endl;

  return 0;
}
