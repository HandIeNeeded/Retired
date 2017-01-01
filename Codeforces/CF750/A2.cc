/*************************************************************************
  >         File: A2.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Jan  1 21:36:09 2017
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
const int X = 33;
bool use[N][N], dp[N][N][X][8];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int turn[N], ans, n;

void go(int x, int y, int t, int d) {
  if (t == n) return ;
  if (dp[x][y][t][d]) return;
  dp[x][y][t][d] = 1;
  for (int i = 0; i < turn[t]; ++i) {
    x += dx[d], y += dy[d];
    if (!use[x][y]) {
      ans++;
      use[x][y] = 1;
    }
  }
  go(x, y, t + 1, (d + 1) & 7);
  go(x, y, t + 1, (d + 7) & 7);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> turn[i];
  go(N / 2, N / 2, 0, 0);
  std::cout << ans << std::endl;
  return 0;
}
