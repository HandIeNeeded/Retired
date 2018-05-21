/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat 14 Apr 01:57:16 2018
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

const int N = 222;
char mp[N][N];
std::vector<int> idx, idy;
int n, m, h, v;

void NO() {
  std::cout << "IMPOSSIBLE" << std::endl;
}

void YES() {
  std::cout << "POSSIBLE" << std::endl;
}

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cin >> n >> m >> h >> v;
    for (int i = 0; i < n; ++i) {
      std::cin >> mp[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == '@') ++cnt;
      }
    }
    std::cout << "Case #" << i + 1 << ": ";
    if (cnt == 0) {
      YES();
      continue;
    }
    if (cnt % ((h + 1) * (v + 1))) {
      NO();
      continue;
    } else {
      idx.clear(), idy.clear();
      int now = 0;
      int need = cnt / (h + 1);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (mp[i][j] == '@') {
            ++now;
          }
        }
        if (now == need) {
          idx.push_back(i);
          now = 0;
        } else if (now > need) break;
      }
      if (now) {
        NO();
        continue;
      }
      need = cnt / (v + 1);
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (mp[j][i] == '@') {
            ++now;
          }
        }
        if (now == need) {
          idy.push_back(i);
          now = 0;
        } else if (now > need) break;
      }
      if (now) {
        NO();
        continue;
      }
      std::vector<std::vector<int> > has(h + 1, std::vector<int> (v + 1, 0)); 
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (mp[i][j] == '@') {
          int x = std::lower_bound(idx.begin(), idx.end(), i) - idx.begin();
          int y = std::lower_bound(idy.begin(), idy.end(), j) - idy.begin();
          has[x][y] += mp[i][j] == '@';
        }
      }
      bool bad = 0;
      for (int i = 0; i < h + 1; ++i) {
        for (int j = 0; j < v + 1; ++j) {
          if (has[i][j] != has[0][0]) {
            bad = 1;
            break;
          }
        }
        if (bad) break;
      }
      if (!bad) YES();
      else NO();
    }
  }

  return 0;
}
