/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Mar 14 20:30:49 2017
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

const int N = 101;
const int K = 70;

int dp[N][N][K][K];
char mp[N][N];

void toMax(int &x, int y) {
  if (x < y) x = y;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> mp[i];
  memset(dp, -1, sizeof(dp));
  dp[1][1][mp[0][0] == '>'][mp[0][0] == '-'] = mp[0][0] == '|';
  for (int i = 2; i <= m; ++i) {
    for (int a = 0; a < K; ++a){
      for (int b = 0; b < K; ++b) {
        int na = a + (mp[0][i - 1] == '>');
        int nb = b + (mp[0][i - 1] == '-');
        int add = mp[0][i - 1] == '|';
        na = std::min(na, K - 1);
        nb = std::min(nb, K - 1);
        if (dp[1][i - 1][a][b] >= 0) toMax(dp[1][i][na][nb], dp[1][i - 1][a][b] + add);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int a = 0; a < K; ++a){
      for (int b = 0; b < K; ++b) {
        int na = a + (mp[i - 1][0] == '>');
        int nb = b + (mp[i - 1][0] == '-');
        na = std::min(na, K - 1);
        nb = std::min(nb, K - 1);
        int add = mp[i - 1][0] == '|';
        if (dp[i - 1][1][a][b] >= 0) toMax(dp[i][1][na][nb], dp[i - 1][1][a][b] + add);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      for (int x = 0; x < K; ++x) {
        for (int y = 0; y < K; ++y) {
          int nx = x + (mp[i - 1][j - 1] == '>');
          int ny = y + (mp[i - 1][j - 1] == '-');
          int add = mp[i - 1][j - 1] == '|';
          nx = std::min(nx, K - 1);
          ny = std::min(ny, K - 1);
          if (dp[i - 1][j][x][y] >= 0) toMax(dp[i][j][nx][ny], dp[i - 1][j][x][y] + add);
          if (dp[i][j - 1][x][y] >= 0) toMax(dp[i][j][nx][ny], dp[i][j - 1][x][y] + add);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      int res = std::min(i, std::min(j, dp[n][m][i][j]));
      toMax(ans, res);
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
