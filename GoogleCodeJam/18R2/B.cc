/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat 19 May 17:04:01 2018
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

const int N = 501;
int dp[2][N][N];

void toMax(int &x, int y) {
  if (y > x) x = y;
}

int ans = 0;

void init() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  int now = 0;
  for (int i = 0; i < N; ++i) {
    memset(dp[now ^ 1], -1, sizeof(dp[now ^ 1]));
    for (int j = 0 ; j < N; ++j)
      for (int k = 0 ; k < N; ++k) if (dp[now][j][k] >= 0) {
        toMax(dp[now ^ 1][j][k] , dp[now][j][k]);
        for (int d = 1 , r = i , c = 0 ; r + j < N && c + k < N; ) {
          int e = d;
          if (i == 0) e = d - 1;
          toMax(dp[now ^ 1][j + r][k + c] , dp[now][j][k] + e);
          r += i;
          c += d;
          d++;
        }
      }
    now ^= 1;
  }
  ans = now ^ 1;
  for (int i = 0 ; i < N; ++i)
    for (int j = 0 ; j < N; ++j)
        toMax(dp[ans][i][j], dp[1 - ans][i][j]);

  for (int i = 0 ; i < N; ++i)
    for (int j = 0 ; j < N; ++j) {
        if (i) toMax(dp[ans][i][j] , dp[ans][i - 1][j]);
        if (j) toMax(dp[ans][i][j] , dp[ans][i][j - 1]);
    }
}

int main() {
  std::ios::sync_with_stdio(0);
  init();
  int T;
  std::cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    int n, m;
    std::cin >> n >> m;
    std::cout << "Case #" << cas + 1 << ": " << dp[ans][n][m] << std::endl;
  }

  return 0;
}
