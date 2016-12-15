/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Dec  6 23:59:08 2016
*************************************************************************/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
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

const int N = 1111;
int dp[2][N];
int b[N], weight[N], f[N];
std::vector<int> num[N];

int Get(int x) {
  return x == f[x] ? x : f[x] = Get(f[x]);
}

void Update(int &x, int y) {
  if (x < y) x = y;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, w;
  std::cin >> n >> m >> w;
  for (int i = 1; i <= n; ++i) std::cin >> weight[i];
  for (int i = 1; i <= n; ++i) std::cin >> b[i];
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    int tx = Get(x), ty = Get(y);
    if (tx != ty) f[tx] = ty;
  }
  for (int i = 1; i <= n; ++i) {
    int x = Get(i);
    num[x].push_back(i);
  }
  dp[0][0] = 0;
  int now = 0;
  for (int i = 1; i <= n; ++i) if (num[i].size()) {
    memcpy(dp[now ^ 1], dp[now], sizeof(dp[now ^ 1]));
    int sum = 0;
    int sumb = 0;
    for (auto &x: num[i]) {
      int y = weight[x];
      sum += y;
      sumb += b[x];
      for (int j = 0; j < w; ++j) {
        if (y + j <= w) {
          Update(dp[now ^ 1][y + j], dp[now][j] + b[x]);
        }
      }
    }
    for (int j = 0; j < w; ++j) {
      if (sum + j <= w) {
        Update(dp[now ^ 1][sum + j], dp[now][j] + sumb);
      }
    }
    memset(dp[now], 0, sizeof(dp[now]));
    now ^= 1;
  }
  int ans = 0;
  for (int i = 1; i <= w; ++i) Update(ans, dp[now][i]);
  std::cout << ans << std::endl;
  return 0;
}
