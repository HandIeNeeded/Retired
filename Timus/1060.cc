/*************************************************************************
  >         File: 1060.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Wed Jan  4 22:46:36 2017
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

char mp[2][4][4];

bool good() {
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mp[1][i][j] == 'b') ans |= 1;
      else ans |= 2;
    }
  }
  return ans != 3;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void flip(int x, int y) {
  mp[1][x][y] = 'b' + 'w' - mp[1][x][y];
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (tx < 0 || tx >= 4) continue;
    if (ty < 0 || ty >= 4) continue;
    mp[1][tx][ty] = 'b' + 'w' - mp[1][tx][ty];
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  for (int i = 0; i < 4; ++i) {
    std::cin >> mp[0][i];
  }
  int ans = 17;
  for (int i = 0; i < (1 << 16); ++i) {
    memcpy(mp[1], mp[0], sizeof(mp[1]));
    for (int j = 0; j < 16; ++j) {
      if (i & (1 << j)) {
        flip(j / 4, j % 4);
      }
    }
    if (good()) ans = std::min(ans, __builtin_popcount(i));
  }
  if (ans == 17) {
    std::cout << "Impossible" << std::endl;
    return 0;
  }
  std::cout << ans << std::endl;

  return 0;
}
