/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Dec 31 13:48:38 2016
*************************************************************************/
#include <vector>
#include <cstdio>
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

const int N = 333;
const int X = 160;
bool dp[N][N][X][8];
bool use[N][N];
bool mark[X];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int turn[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> turn[i + 1];
  for (int i = 0; i < n; ++i) turn[i + 1] += turn[i], mark[turn[i + 1]] = true;
  std::queue<std::tuple<int, int, int, int>> q;
  dp[X][X][1][0] = true;
  q.emplace(X, X, 1, 0);
  while (q.size()) {
    int x, y, t, d;
    std::tie(x, y, t, d) = q.front(); q.pop();
    if (t == turn[n]) break;
    if (!mark[t]) {
      int nx = x + dx[d], ny = y + dy[d];
      if (!dp[nx][ny][t + 1][d]) {
        dp[nx][ny][t + 1][d] = true;
        q.emplace(nx, ny, t + 1, d);
      }
    } else {
      for (int z = -1; z < 2; z += 2) {
        int nd = (d + z + 8) % 8;
        int nx = x + dx[nd], ny = y + dy[nd];
        if (!dp[nx][ny][t + 1][nd]) {
          dp[nx][ny][t + 1][nd] = true;
          q.emplace(nx, ny, t + 1, nd);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int t = 0; t < X; ++t) {
        for (int d = 0; d < 8; ++d) {
          if (!use[i][j] && dp[i][j][t][d] == true) {
            ans++;
            use[i][j] = true;
          }
        }
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
