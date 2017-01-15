/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Jan  6 23:44:35 2017
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

char mp[5][5];

bool good(int x, int y) {
  mp[x][y] = 'x';
  bool find = 0;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int bad = 0;
      for (int k = 0; k < 3; ++k) {
        if (j + k >= 4 || mp[i][j + k] != 'x') {
          bad = 1;
          break;
        }
      }
      if (!bad) find = 1;
      bad = 0;
      for (int k = 0; k < 3; ++k) {
        if (i + k >= 4 || mp[i + k][j] != 'x') {
          bad = 1;
          break;
        }
      }
      if (!bad) find = 1;
      bad = 0;
      for (int k = 0; k < 3; ++k) {
        if (j + k >= 4 || i + k >= 4 || mp[i + k][j + k] != 'x') {
          bad = 1;
          break;
        }
      }
      if (!bad) find = 1;
      bad = 0;
      for (int k = 0; k < 3; ++k) {
        if (j - k < 0 || i + k >= 4 || mp[i + k][j - k] != 'x') {
          bad = 1;
          break;
        }
      }
      if (!bad) find = 1;
    }
  }
  mp[x][y] = '.';
  return find;
}

int main() {
  std::ios::sync_with_stdio(0);
  
  for (int i = 0; i < 4; ++i) std::cin >> mp[i];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mp[i][j] == '.') {
        if (good(i, j)) {
          std::cout << "YES" << std::endl;
          return 0;
        }
      }
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}
