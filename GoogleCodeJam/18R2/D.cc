/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat 19 May 16:49:24 2018
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

const int N = 444;
char mp[2][N][N], g[N][N];
int r, c;
int n, m;

std::vector<std::pair<int, int>> points;
bool visit[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

bool connect(int st) {
  int tot = n * m;
  points.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) visit[i][j] = 0;
  }
  for (int i = 0; i < tot; ++i) {
    if (st & (1 << i)) {
      points.push_back({i / m, i % m});
      visit[i / m][i % m] = 1;
    }
  }
  if (!points.size()) return 0;
  std::queue<int> q;
  q.push(points[0].first);
  q.push(points[0].second);
  while (q.size()) {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    visit[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (good(nx, ny) && visit[nx][ny]) {
        q.push(nx);
        q.push(ny);
      }
    }
  }
  for(auto &p: points) {
    int x, y;
    std::tie(x, y) = p;
    if (visit[x][y]) return 0;
  }
  return 1;
}

bool search(int st) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      bool bad = 0;
      for (auto &p: points) {
        int x, y;
        std::tie(x, y) = p;
        if (mp[0][i + x][j + y] != g[x][y]) {
          bad = 1;
          break;
        }
      }
      if (!bad) return 1;
    }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> g[i];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) mp[0][i][j] = g[i][j];
    }
    int now = 0;
    r = n, c = m;
    for (int i = 0; i < 2; ++i) {
      for (int a = 0; a < r; ++a) {
        for (int b = 0; b < c; ++b) {
          int x = a * 2;
          int y = b * 2;
          for (int dx = 0; dx < 2; ++dx) {
            for (int dy = 0; dy < 2; ++dy) {
              mp[now ^ 1][x + dx][y + dy] = mp[now][a][b];
            }
          }
        }
      }
      r <<= 1;
      c <<= 1;
      now ^= 1;
    }
    int tot = n * m;
    int ans = 0;
    for (int i = 0; i < (1 << tot); ++i) if (i) {
      if (__builtin_popcount(i) <= ans) continue;
      if (connect(i)) {
        if (search(i)) {
          ans = __builtin_popcount(i);
        }
      }
    }
    std::cout << "Case #" << cas + 1 << ": " << ans << std::endl;
  }

  return 0;
}
